using Dotective.Profiler;
using System;

namespace Dotective
{
    public interface IProfilingContext : IDisposable
    {
        IProfiler Profiler { get; }

        IProfilee Profilee { get; }
    }
}
