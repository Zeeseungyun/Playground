
using System.Text;

namespace Zee
{
    static public partial class Generator
    {
        public static void Cleanup()
        {
            List<string> files = new List<string>(Directory.GetFiles(CppPrivateMessageDst, "*.*", SearchOption.AllDirectories));
            files.AddRange(Directory.GetFiles(CShardMessageDst, "*.*", SearchOption.AllDirectories));
            files.Add(CSharp.PacketMap);
            files.AddRange(Directory.GetFiles($"{CppZeeNetDir}Public/Messages/", "*.*", SearchOption.AllDirectories));
            files.AddRange(Directory.GetFiles($"{CppZeeNetDir}Private/Convert/", "*.*", SearchOption.AllDirectories));
            files.Add($"{CppZeeNetDir}Private/ZeeNetMessageSerializer.g.cpp");
            
            foreach(var file in files)
            {
                if(File.Exists(file))
                {
                    Console.WriteLine($"delete {file}");
                    File.Delete(file);
                }
            }
        }
    }
}
