using Dotective.Profiler;
using System.IO;

namespace Dotective.Tests.Internal
{
    public static class TestRunner
    {
        public static void Run(IProfiler profiler)
            => Run(profiler, string.Empty);

        public static void Run(IProfiler profiler, string source)
            => Run(profiler, TestSource.Create(source));

        public static void Run(IProfiler profiler, TestSource source)
        {
            var fileName = TestCompiler.Compile(source);

            IProfilingContext context = null;

            try
            {
                context = ProfilerRunner.Run(profiler, fileName);
            }
            finally
            {
                context?.Profilee.Process.WaitForExit();
                context?.Dispose();

                File.Delete(fileName);
            }
        }
    }
}
