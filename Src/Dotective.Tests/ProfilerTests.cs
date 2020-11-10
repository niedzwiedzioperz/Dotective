using Dotective.Profiler;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using Moq;
using static Dotective.Tests.Internal.TestRunner;

namespace Dotective.Tests
{
    [TestClass]
    public class ProfilerTests
    {
        [TestMethod]
        public void Initialize_ShouldBeCalled()
        {
            var mock = new Mock<IProfiler>();

            Run(mock.Object);

            mock.Verify(p => p.Initialize(It.IsNotNull<IProfilingContext>()), Times.Once);
        }

        [TestMethod]
        public void Shutdown_ShouldBeCalled()
        {
            var mock = new Mock<IProfiler>();

            Run(mock.Object);

            mock.Verify(p => p.Shutdown(), Times.Once);
        }
    }
}
