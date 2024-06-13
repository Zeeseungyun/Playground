
using System.Text;

namespace Zee
{
    static public partial class Generator
    {
        public static void Cleanup()
        {
            List<string> files = new List<string>(Directory.GetFiles(CppDst, "*.*", SearchOption.AllDirectories));
            files.AddRange(Directory.GetFiles(CSharpDst, "*.*", SearchOption.AllDirectories));
            files.Add(packetMappingFile);
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
