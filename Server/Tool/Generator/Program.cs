using System.Diagnostics;
using System.Text.RegularExpressions;
using Zee.Common;
using Zee.Generator;

CommandLineArg.ParseCommandLineArgs(args);
CommandLineArg protocArg     = new (new []{"-protoc"});
CommandLineArg protoSrcArg   = new (new []{"-src"});
CommandLineArg csDstArg      = new (new []{"-csdst"});
CommandLineArg singleFileArg      = new (new []{"-single"});

string protoc = protocArg.Value;
string protoSrc = protoSrcArg.Value;
string csDst = csDstArg.Value;

{
    var files = Directory.GetFiles(protoSrc, "*.proto", SearchOption.AllDirectories);
    Zee.Generator.Program.CompileProto(protoc, csDst, protoSrc, files);
    var result = new ParseResult(protoSrc, files);
    Zee.Generator.Program.GenerateMappingFile(result);
}
