using System;

namespace Dotective.Internals.Callbacks
{
    internal class ShutdownCallback : ProfilerCallback
    {
        private readonly IProfilingContext _context;

        public ShutdownCallback(
            IProfilingContext context)
        {
            if (context == null)
            {
                throw new ArgumentNullException(nameof(context));
            }

            _context = context;
        }

        public override CallbackType Type => CallbackType.Shutdown;

        public override void Invoke(DotectiveMessage message)
            => _context.Profiler.Shutdown();
    }
}
