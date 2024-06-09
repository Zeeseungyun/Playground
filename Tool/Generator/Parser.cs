using System.Diagnostics;

namespace Zee.Generator
{
    static public partial class Program
    {
        public static void CompileProto(string protoc, string csDst, string protoSrc, string[] filePaths)
        {
            ProcessStartInfo startInfo = new();
            startInfo.FileName = protoc;
            startInfo.Arguments = $"--csharp_out={csDst} --proto_path={protoSrc} {string.Join(" ", filePaths)}";
            using (Process exeProcess = Process.Start(startInfo))
            {
                exeProcess.WaitForExit();
                if(exeProcess.ExitCode != 0)
                {
                    throw new Exception("proto compile failed.");
                }
            }
        }
        public static ParseResult Parse(string rootDir, string[] filePaths)
        {
            return new(rootDir, filePaths);
        }
    }
}
