using System;

namespace Dotective.Tests.Internal
{
    public class TestSource
    {
        private const string Template = @"
namespace Test
{{
    public class Program
    {{
        public static void Main()
        {{
            {0}
        }}
    }}
}}";

        public TestSource(
            string source)
        {
            if (string.IsNullOrWhiteSpace(source))
            {
                throw new ArgumentNullException(nameof(source));
            }

            Source = source;
        }

        public string Source { get; }

        public static TestSource Create()
            => Create(string.Empty);

        public static TestSource Create(string mainMethodContent)
            => new TestSource(string.Format(Template, mainMethodContent));
    }
}
