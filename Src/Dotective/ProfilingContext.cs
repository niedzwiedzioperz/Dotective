using Dotective.Internals;
using Dotective.Profiler;
using System;

namespace Dotective
{
    internal sealed class ProfilingContext : IProfilingContext
    {
        private readonly DotectiveListener _listener;

        public ProfilingContext(
            IProfiler profiler,
            IProfilee profilee,
            DotectiveListener listener)
        {
            if (profiler == null)
            {
                throw new ArgumentNullException(nameof(profiler));
            }

            if (profilee == null)
            {
                throw new ArgumentNullException(nameof(profilee));
            }

            if (listener == null)
            {
                throw new ArgumentNullException(nameof(listener));
            }

            _listener = listener;

            Profiler = profiler;
            Profilee = profilee;
        }

        #region IProfilingContext

        public IProfiler Profiler { get; }

        public IProfilee Profilee { get; }

        public void Dispose()
        {
            _listener.Dispose();
        }

        #endregion
    }
}
