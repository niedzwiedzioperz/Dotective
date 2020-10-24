using Dotective.Profiler;

namespace Dotective
{
    public interface IProfilingContext
    {
        IProfiler Profiler { get; }

        IProfilee Profilee { get; }
    }
}
