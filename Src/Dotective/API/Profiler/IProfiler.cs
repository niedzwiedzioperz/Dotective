namespace Dotective.Profiler
{
    public interface IProfiler
    {
        void Initialize(IProfilingContext context);
        void Shutdown();
    }
}
