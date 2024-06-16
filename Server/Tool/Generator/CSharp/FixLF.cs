
using System.Text;

namespace Zee
{
    static public partial class Generator
    {
        static public partial class CSharp
        {        
            public static void FixLF()
            {
                var files = Directory.GetFiles(CSharpProtoMessageDir, "*.cs");
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
                        origin = origin.Replace("\n", "\r\n");
                        sw.WriteLine(origin);
                    }
                }
            }
        }
    }
}
