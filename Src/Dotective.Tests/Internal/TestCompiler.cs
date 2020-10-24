using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.Text;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace Dotective.Tests.Internal
{
    public static class TestCompiler
    {
        private static readonly IEnumerable<string> DefaultNamespaces =
            new[]
            {
                "System",
                "System.IO",
                "System.Linq",
                "System.Text",
                "System.Collections.Generic"
            };

        private static readonly IEnumerable<MetadataReference> DefaultReferences =
            new[]
            {
                MetadataReference.CreateFromFile(typeof(string).Assembly.Location),
                MetadataReference.CreateFromFile(typeof(Enumerable).Assembly.Location)
            };

        private static readonly CSharpCompilationOptions DefaultCompilationOptions =
            new CSharpCompilationOptions(OutputKind.ConsoleApplication)
                .WithOverflowChecks(true)
                .WithOptimizationLevel(OptimizationLevel.Debug)
#if WIN64
                .WithPlatform(Platform.X64)
#else
                .WithPlatform(Platform.X86)
#endif
                .WithUsings(DefaultNamespaces);

        public static string Compile(TestSource source)
        {
            if (source == null)
            {
                throw new ArgumentNullException(nameof(source));
            }

            var sourceText = SourceText.From(source.Source, Encoding.UTF8);
            var syntaxTree = SyntaxFactory.ParseSyntaxTree(sourceText);
            var fileName = CreateFileName();

            if (File.Exists(fileName))
            {
                File.Delete(fileName);
            }

            var compilation = CSharpCompilation.Create(fileName, new SyntaxTree[] { syntaxTree }, DefaultReferences, DefaultCompilationOptions);
            var result = compilation.Emit(fileName);

            if (!result.Success)
            {
                var errors = result
                    .Diagnostics
                    .Where(d => d.Severity == DiagnosticSeverity.Error);

                throw new InvalidOperationException("Compilation failed: " + string.Join(Environment.NewLine, errors.Select(e => e.GetMessage())));
            }

            return fileName;
        }

        private static string CreateFileName()
            => $"Test_{Guid.NewGuid():N}.exe";
    }
}
