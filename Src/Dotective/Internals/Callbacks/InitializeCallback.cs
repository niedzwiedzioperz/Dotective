using System;

namespace Dotective.Internals.Callbacks
{
    internal class InitializeCallback : ProfilerCallback
    {
        private readonly IProfilingContext _context;

        public InitializeCallback(
            IProfilingContext context)
        {
            if (context == null)
            {
                throw new ArgumentNullException(nameof(context));
            }

            _context = context;
        }

        public override CallbackType Type => CallbackType.Initialize;

        public override void Invoke(DotectiveMessage message)
            => _context.Profiler.Initialize(_context);
    }
}
