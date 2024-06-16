
using System.Text;

namespace Zee
{
    static public partial class Generator
    {
        public static void Cleanup()
        {
            foreach(var file in GetCleanupFiles())
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
