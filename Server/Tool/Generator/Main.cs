using Zee.Common;
using Zee;

CommandLineArg.ParseCommandLineArgs(args);
CommandLineArg protocArg     = new (new []{"-protoc"});
CommandLineArg protoSrcArg   = new (new []{"-src"});
CommandLineArg csharpDstArg  = new (new []{"-csharpdst"});
CommandLineArg cppDstArg     = new (new []{"-cppdst"});

Generator.ProtoExeFilePath = protocArg.Value;
Generator.ProtoMessageDir = protoSrcArg.Value;
Generator.CSharpProtoMessageDir = csharpDstArg.Value;
Generator.UnrealZeeNetDir = cppDstArg.Value; //temp.
// Generator.CppZeeNetDir

{
    var files = Directory.GetFiles(Generator.ProtoMessageDir, "*.proto", SearchOption.AllDirectories);
    Generator.ProtoSrcFilePaths.AddRange(files);

    Console.WriteLine("1) cleanup generated files started.");
    Generator.Cleanup();
    Console.WriteLine("1) cleanup generated files finished.");
    
    Console.WriteLine("2) compile proto started.");
    Generator.CompileAndGenerateProto();
    Console.WriteLine("2) compile proto finished.");
    
    var result = Generator.Parse();
    Console.WriteLine("3) generate csharp files started.");
    Generator.CSharp.FixLF();
    Generator.CSharp.GeneratePacketMap();
    Generator.CSharp.GenerateRequestHandlerFile();
    Generator.CSharp.GenerateNotifyHandlerFile();
    Console.WriteLine("3) generate csharp files finished.");
    
    Console.WriteLine("4) generate cpp files started.");
    Generator.Unreal.Fix4125();
    Generator.Unreal.GeneratePublicMessages();
    Generator.Unreal.GenerateMessageConvert();
    Generator.Unreal.GenerateMessageSerializer();
    Console.WriteLine("4) generate cpp files finished.");

    Console.WriteLine("Generator done.");
}
