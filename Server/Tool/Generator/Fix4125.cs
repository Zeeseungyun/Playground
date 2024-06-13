
using System.Text;

namespace Zee
{
    static public partial class Generator
    {
        public static void Fix4125()
        {
            var files = Directory.GetFiles(CppDst, "*.pb.cc");
            foreach(var file in files)
            {
                if(!File.Exists(file))
                {
                    continue;
                }

                string origin = string.Empty;
                using(var fs = File.OpenRead(file))
                {
                    using var sr = new StreamReader(fs);
                    origin = sr.ReadToEnd();
                }

                File.Delete(file);
                using (var fs = File.OpenWrite(file))
                {
                    using var sw = new StreamWriter(fs);
                    sw.WriteLine("#pragma warning (disable : 4125)");
                    sw.WriteLine(origin);
                }
            }
        }
    }
}
