using System;
using System.Threading;
using System.Threading.Tasks;

namespace Dotective.Internals
{
    internal class DotectiveListener : IDisposable
    {
        private readonly DotectiveLink _link;
        private readonly ProfilerBridge _profilerBridge;
        private readonly Thread _listener;
        private bool _isRunning;

        public DotectiveListener(
            DotectiveLink link,
            ProfilerBridge profilerBridge)
        {
            if (link == null)
            {
                throw new ArgumentNullException(nameof(link));
            }

            if (profilerBridge == null)
            {
                throw new ArgumentNullException(nameof(profilerBridge));
            }

            _link = link;
            _profilerBridge = profilerBridge;
            _listener = new Thread(Listen)
            {
                IsBackground = true
            };
        }

        public Task Start()
            => Task.Factory.StartNew(Connect);

        private void Connect()
        {
            _link.Connect();

            _isRunning = true;
            _listener.Start();
        }

        private void Listen()
        {
            while (_isRunning)
            {
                DotectiveMessage message = null;
                try
                {
                    message = _link.Receive();
                }
                catch (Exception e) when (e is ObjectDisposedException || e is InvalidOperationException)
                {
                    _isRunning = false;
                }

                if (message != null)
                {
                    try
                    {
                        _profilerBridge.HandleCallback(message);
                    }
                    finally
                    {
                        message.Dispose();

                        Continue();
                    }
                }
            }
        }

        private void Continue()
        {
            var response = DotectiveMessage.Create();

            try
            {
                response.Buffer[0] = 0;
                response.AddLength(1);

                _link.Send(response);
            }
            finally
            {
                response.Dispose();
            }
        }

        #region IDisposable

        public void Dispose()
        {
            _isRunning = false;
            _link.Dispose();
        }

        #endregion
    }
}
