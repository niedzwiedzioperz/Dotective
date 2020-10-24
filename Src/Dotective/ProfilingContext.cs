using Dotective.Profiler;
using System;

namespace Dotective
{
    internal sealed class ProfilingContext : IProfilingContext
    {
        public ProfilingContext(
            IProfiler profiler,
            IProfilee profilee)
        {
            if (profiler == null)
            {
                throw new ArgumentNullException(nameof(profiler));
            }

            if (profilee == null)
            {
                throw new ArgumentNullException(nameof(profilee));
            }

            Profiler = profiler;
            Profilee = profilee;
        }

        #region IProfilingContext

        public IProfiler Profiler { get; }

        public IProfilee Profilee { get; }

        #endregion
    }
}
