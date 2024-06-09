using System.Diagnostics;

namespace Zee
{
    static public partial class Generator
    {
        public static string ProtoExeFilePath = string.Empty;
        public static string CSharpDst = string.Empty;
        public static string CppDst = string.Empty;
        public static readonly List<string> ProtoSrcFilePaths = new();
        public static string ProtoSrcFilePath = string.Empty;
        public static void CompileProto()
        {
            ProcessStartInfo startInfo = new();
            startInfo.FileName = ProtoExeFilePath;
            //--cpp_out={CSharpDst} 
            if(Directory.Exists(CSharpDst))
            {
                Directory.Delete(CSharpDst, true);
            }
            Directory.CreateDirectory(CSharpDst);
            startInfo.Arguments = $"--csharp_out={CSharpDst} --proto_path={ProtoSrcFilePath} {string.Join(" ", ProtoSrcFilePaths)}";
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
        public static ParseResult Parse()
        {
            return new(ProtoSrcFilePath, ProtoSrcFilePaths.ToArray());
        }
    }
}
