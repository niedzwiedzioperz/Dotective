using System;
using System.IO;
using System.IO.MemoryMappedFiles;
using System.IO.Pipes;

namespace Dotective.Internals
{
    internal class DotectiveLink : IDisposable
    {
        private readonly MemoryMappedFile _sharedMemory;
        private readonly MemoryMappedViewAccessor _accessor;
        private readonly NamedPipeServerStream _pipe;
        private readonly byte[] _lengthBuffer = new byte[4];

        public DotectiveLink()
        {
            _sharedMemory = MemoryMappedFile.CreateNew("DotectiveMemory", 1048576, MemoryMappedFileAccess.ReadWriteExecute, MemoryMappedFileOptions.None, HandleInheritability.None);
            _accessor = _sharedMemory.CreateViewAccessor();
            _pipe = new NamedPipeServerStream("DotectivePipe", PipeDirection.InOut, 1);
        }

        public void Connect()
        {
            _pipe.WaitForConnection();
        }

        public DotectiveMessage Receive()
        {
            int length;
            lock (_lengthBuffer)
            {
                _pipe.Read(_lengthBuffer, 0, sizeof(int));

                length = BitConverter.ToInt32(_lengthBuffer, 0);
            }

            var message = DotectiveMessage.Create();

            try
            {
                _pipe.Read(message.Buffer, 0, length);
                message.AddLength(length);
            }
            catch
            {
                message.Dispose();

                throw;
            }

            return message;
        }

        public void Send(DotectiveMessage message)
        {
            lock (_lengthBuffer)
            {
                WriteInt(_lengthBuffer, message.Length);

                _pipe.Write(_lengthBuffer, 0, sizeof(int));
            }

            if (message.Length > 0)
            {
                _pipe.Write(message.Buffer, 0, message.Length);
            }
        }

        #region IDisposable

        public void Dispose()
        {
            _accessor.Dispose();
            _sharedMemory.Dispose();
            _pipe.Dispose();
        }

        #endregion

        private static void WriteInt(byte[] buffer, int value)
        {
            buffer[3] = (byte)((value & 0xFF) >> 24);
            buffer[2] = (byte)((value & 0x00FF) >> 16);
            buffer[1] = (byte)((value & 0x0000FF) >> 8);
            buffer[0] = (byte)(value & 0x000000FF);
        }
    }
}
