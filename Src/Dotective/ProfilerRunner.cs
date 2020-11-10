using Dotective.Internals;
using Dotective.Internals.Callbacks;
using Dotective.Metadata;
using Dotective.Profiler;
using Dotective.Runtime;
using System;
using System.Diagnostics;
using System.IO;

namespace Dotective
{
    public static class ProfilerRunner
    {
        private const string ProfilerGuid = "8BAE2CC3-5F66-4981-82E8-E47BA7EB08BF";
        private const string ProfilerDllName = "DotectiveProfiler.dll";

        private static string ProfilerPath => Path.Combine(Directory.GetCurrentDirectory(), ProfilerDllName);

        public static IProfilingContext Run(IProfiler profiler, string profileePath)
        {
            if (profiler == null)
            {
                throw new ArgumentNullException(nameof(profiler));
            }

            if (string.IsNullOrWhiteSpace(profileePath))
            {
                throw new ArgumentNullException(nameof(profileePath));
            }

            RegisterProfiler();

            var link = new DotectiveLink();
            var bridge = new ProfilerBridge();
            var listener = new DotectiveListener(link, bridge);

            var listenerTask = listener.Start();

            try
            {
                var process = RunProcess(profileePath);
                var profilee = new Profilee(process);

                listenerTask.Wait();

                return CreateContext(profiler, profilee, listener, bridge);
            }
            catch
            {
                listener.Dispose();

                throw;
            }
        }

        private static void RegisterProfiler()
        {
            try
            {
                RegisterProfilerComponent(false);
            }
            catch
            { }

            RegisterProfilerComponent(true);
        }

        private static void RegisterProfilerComponent(bool register)
        {
            using (var reg = new Process())
            {
                var args = "/s";

                if (!register)
                {
                    args += " /u";
                }

                reg.StartInfo.FileName = "regsvr32.exe";
                reg.StartInfo.Arguments = $"{args} \"{ProfilerPath}\"";
                reg.StartInfo.UseShellExecute = false;
                reg.StartInfo.CreateNoWindow = true;
                reg.StartInfo.RedirectStandardOutput = true;
                reg.Start();
                reg.WaitForExit();

                if (reg.ExitCode != 0)
                {
                    throw new InvalidOperationException($"Command '{reg.StartInfo.FileName} {reg.StartInfo.Arguments}' exited with code: {reg.ExitCode}");
                }
            }
        }

        private static Process RunProcess(string profileePath)
        {
            var psi = new ProcessStartInfo(profileePath)
            {
                UseShellExecute = false
            };

            psi.EnvironmentVariables.Add("COR_ENABLE_PROFILING", "1");
            psi.EnvironmentVariables.Add("COR_PROFILER", "{" + ProfilerGuid + "}");

            return Process.Start(psi);
        }

        private static ProfilingContext CreateContext(IProfiler profiler, IProfilee profilee, DotectiveListener listener, ProfilerBridge bridge)
        {
            var runtmeInfo = SetUpRuntimeInfo();
            var metadataInfo = SetUpMetadataInfo();
            var context = new ProfilingContext(
                listener,
                profiler,
                profilee,
                runtmeInfo,
                runtmeInfo,
                metadataInfo);

            SetUpCallbacks(bridge, context);

            return context;
        }

        private static RuntimeInfo SetUpRuntimeInfo() => new RuntimeInfo();

        private static MetadataInfo SetUpMetadataInfo() => new MetadataInfo();

        private static void SetUpCallbacks(ProfilerBridge bridge, IProfilingContext context)
            => bridge
            .AddCallback(new InitializeCallback(context))
            .AddCallback(new ShutdownCallback(context));
    }
}
