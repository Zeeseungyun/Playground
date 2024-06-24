
using System.Text;

namespace Zee
{
    static public partial class Generator
    {
        static public partial class Unreal
        {        
            public static void FixProtoInclude()
            {
                var files = Directory.GetFiles(UnrealProtoMessageDir, "*.pb.cc", SearchOption.AllDirectories);
                foreach(var file in files)
                {
                    if(!File.Exists(file))
                    {
                        continue;
                    }

                    var fileNameWithoutExt = Path.GetFileNameWithoutExtension(file);
                    List<string> lines = new (File.ReadAllLines(file));
                    bool bNeedFix = false;
                    for(int i = 0; i != lines.Count; ++i)
                    {
                        int found = lines[i].IndexOf(fileNameWithoutExt);
                        if(found != -1)
                        {
                            if(lines[i][found-1] != '\"')
                            {
                                lines[i] = $"#include \"{fileNameWithoutExt}.h\"";
                                bNeedFix = true;
                                break;
                            }
                        }

                        //이 이후로 include 문이 나타나지 않음.
                        if(lines[i].IndexOf("PROTOBUF_PRAGMA_INIT_SEG") != -1)
                        {
                            break;
                        }
                    }

                    if(bNeedFix)
                    {
                        File.Delete(file);
                        using (var fs = File.OpenWrite(file))
                        {
                            using var sw = new StreamWriter(fs);
                            foreach(var line in lines)
                            {
                                sw.WriteLine(line);
                            }
                        }
                    }
                }
            }
        }
    }
}
