using System;
using System.Diagnostics;

namespace Dotective
{
    internal sealed class Profilee : IProfilee
    {
        public Profilee(
            Process process)
        {
            if (process == null)
            {
                throw new ArgumentNullException(nameof(process));
            }

            Process = process;
        }

        #region IProfilee

        public Process Process { get; }

        #endregion
    }
}
