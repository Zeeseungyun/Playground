using System.Diagnostics;

namespace Zee
{
    static public partial class Generator
    {
        public static void CompileAndGenerateProto()
        {
            ProcessStartInfo startInfo = new();
            startInfo.FileName = ProtoExeFilePath;
            //--cpp_out={CSharpDst} 
            if(Directory.Exists(CShardMessageDst))
            {
                Directory.Delete(CShardMessageDst, true);
            }
            Directory.CreateDirectory(CShardMessageDst);
            startInfo.Arguments = $"--csharp_out={CShardMessageDst} --cpp_out={CppPrivateMessageDst} --proto_path={ProtoMessageDir} {string.Join(" ", ProtoSrcFilePaths)}";
            //startInfo.Arguments = $"--proto_path={ProtoSrcFilePath} {string.Join(" ", ProtoSrcFilePaths)}";
            using (Process? exeProcess = Process.Start(startInfo))
            {
                if(exeProcess == null)
                {
                    throw new Exception("if(exeProcess == null)");
                }

                exeProcess.WaitForExit();
                if(exeProcess.ExitCode != 0)
                {
                    throw new Exception("proto compile failed.");
                }
            }
        }

        private static ParseResult? parseResult;
        public static ParseResult Parse()
        {
            if(parseResult == null)
            {
                parseResult = new(ProtoMessageDir, ProtoSrcFilePaths.ToArray());
            }
            return parseResult ;
        }
    }
}
