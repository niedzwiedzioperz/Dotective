using System;
using System.Collections.Generic;
using System.Linq;

namespace Dotective.Internals
{
    internal class DotectiveMessage : IDisposable
    {
        private const int MessageSize = 10240;
        private static readonly List<DotectiveMessage> _pool = new List<DotectiveMessage>();

        private DotectiveMessage()
        {
            Buffer = new byte[MessageSize];
        }

        public byte[] Buffer { get; }

        public int Length { get; private set; }

        public void AddLength(int length)
        {
            Length += length;
        }

        #region IDisposable

        public void Dispose()
        {
            Length = 0;
            _pool.Add(this);
        }

        #endregion

        public static DotectiveMessage Create()
        {
            if (_pool.Count == 0)
            {
                return new DotectiveMessage();
            }

            var message = _pool.Last();
            _pool.RemoveAt(_pool.Count - 1);

            return message;
        }
    }
}
