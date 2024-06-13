using Zee.Common;
using Zee;

CommandLineArg.ParseCommandLineArgs(args);
CommandLineArg protocArg     = new (new []{"-protoc"});
CommandLineArg protoSrcArg   = new (new []{"-src"});
CommandLineArg csharpDstArg  = new (new []{"-csharpdst"});
CommandLineArg cppDstArg     = new (new []{"-cppdst"});

Generator.ProtoExeFilePath = protocArg.Value;
Generator.ProtoSrcFilePath = protoSrcArg.Value;
Generator.CSharpDst = csharpDstArg.Value;
Generator.CppDst = cppDstArg.Value; //temp.

{
    var files = Directory.GetFiles(Generator.ProtoSrcFilePath, "*.proto", SearchOption.AllDirectories);
    Generator.ProtoSrcFilePaths.AddRange(files);

    Console.WriteLine("1) cleanup generated files started.");
    Generator.Cleanup();
    Console.WriteLine("1) cleanup generated files finished.");
    
    Console.WriteLine("2) compile proto started.");
    Generator.CompileProto();
    Console.WriteLine("2) compile proto finished.");
    
    var result = Generator.Parse();
    Console.WriteLine("3) generate mapping file started.");
    Generator.GenerateMappingFile(result);
    Console.WriteLine("3) generate mapping file finished.");
    Generator.Fix4125();
    Generator.FixLF();

    Console.WriteLine("Generator done.");
}
