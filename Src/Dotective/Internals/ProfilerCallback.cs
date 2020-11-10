namespace Dotective.Internals
{
    internal abstract class ProfilerCallback
    {
        public abstract CallbackType Type { get; }
        public abstract void Invoke(DotectiveMessage message);
    }
}
