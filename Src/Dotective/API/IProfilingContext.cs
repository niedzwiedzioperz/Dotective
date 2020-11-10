using Dotective.Metadata;
using Dotective.Profiler;
using Dotective.Runtime;
using System;

namespace Dotective
{
    public interface IProfilingContext : IDisposable
    {
        IProfiler Profiler { get; }

        IProfilee Profilee { get; }

        IProfilerOptions Options { get; }

        IRuntimeInfo RuntimeInfo { get; }

        IMetadataInfo MetadataInfo { get; }
    }
}
