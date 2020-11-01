using Dotective.Profiler;
using System;

namespace Dotective.Internals
{
    internal class ProfilerBridge
    {
        private readonly IProfiler _profiler;

        public ProfilerBridge(
            IProfiler profiler)
        {
            if (profiler == null)
            {
                throw new ArgumentNullException(nameof(profiler));
            }

            _profiler = profiler;
        }

        public void HandleCallback(DotectiveMessage message)
        {
            switch ((CallbackType)message.Buffer[0])
            {
                case CallbackType.Initialize:
                    _profiler.Initialize();
                    break;
                case CallbackType.Shutdown:
                    _profiler.Shutdown();
                    break;
            }
        }
    }
}
