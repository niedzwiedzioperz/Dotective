using System;
using System.Linq;

namespace Dotective.Internals
{
    internal class ProfilerBridge
    {
        private readonly ProfilerCallback[] _callbacks;

        public ProfilerBridge()
        {
            var maxValue = Enum
                .GetValues(typeof(CallbackType))
                .OfType<CallbackType>()
                .Max(t => (byte)t);

            _callbacks = new ProfilerCallback[maxValue + 1];
        }

        public ProfilerBridge AddCallback(ProfilerCallback callback)
        {
            if (callback == null)
            {
                throw new ArgumentNullException(nameof(callback));
            }

            _callbacks[(int)callback.Type] = callback;

            return this;
        }

        public void Callback(DotectiveMessage message)
        {
            var callbackType = (int)message.Buffer[0];
            if (callbackType < 0
                || callbackType >= _callbacks.Length)
            {
                throw new InvalidOperationException("Invalid callback.");
            }

            _callbacks[callbackType]?.Invoke(message);
        }
    }
}
