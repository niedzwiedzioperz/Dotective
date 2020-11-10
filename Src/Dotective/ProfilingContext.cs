using Dotective.Metadata;
using Dotective.Internals;
using Dotective.Profiler;
using Dotective.Runtime;
using System;

namespace Dotective
{
    internal sealed class ProfilingContext : IProfilingContext
    {
        public ProfilingContext(
            DotectiveListener listener,
            IProfiler profiler,
            IProfilee profilee,
            IProfilerOptions profilerOptions,
            IRuntimeInfo runtimeInfo,
            IMetadataInfo metadataInfo)
        {
            if (listener == null)
            {
                throw new ArgumentNullException(nameof(listener));
            }

            if (profiler == null)
            {
                throw new ArgumentNullException(nameof(profiler));
            }

            if (profilee == null)
            {
                throw new ArgumentNullException(nameof(profilee));
            }

            if (profilerOptions == null)
            {
                throw new ArgumentNullException(nameof(profilerOptions));
            }

            if (runtimeInfo == null)
            {
                throw new ArgumentNullException(nameof(runtimeInfo));
            }

            if (metadataInfo == null)
            {
                throw new ArgumentNullException(nameof(metadataInfo));
            }

            Listener = listener;
            Profiler = profiler;
            Profilee = profilee;
            Options = profilerOptions;
            RuntimeInfo = runtimeInfo;
            MetadataInfo = metadataInfo;
        }

        public DotectiveListener Listener { get; }

        #region IProfilingContext

        public IProfiler Profiler { get; }

        public IProfilee Profilee { get; }

        public IProfilerOptions Options { get; }

        public IRuntimeInfo RuntimeInfo { get; }

        public IMetadataInfo MetadataInfo { get; }

        public void Dispose()
        {
            Listener.Dispose();
        }

        #endregion
    }
}
