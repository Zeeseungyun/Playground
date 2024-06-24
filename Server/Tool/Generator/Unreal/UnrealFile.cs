
using System.Text;

namespace Zee
{
    static public partial class Generator
    {
        static public partial class Unreal
        {
            public class UnrealFile
            {
                public string NameWihtoutProto = string.Empty;
                public string SrcFileName = string.Empty; 
                public string HeaderFileName = string.Empty; 
                public List<string> DependencyNames = new();
                public List<UnrealFile> Dependencies = new();
                public StringBuilder SrcContent = new();
                public StringBuilder HeaderContent = new();
                public UnrealFile()
                {
                    SrcContent.Append(DescriptionGenerated);
                    HeaderContent.Append(DescriptionGenerated);
                }
                public void SrcContent_IncludeHeaderFile()
                {
                    SrcContent.Append($"#include \"ZeeNet/{Path.GetRelativePath(UnrealZeeNetDir, HeaderFileName).Replace("\\", "/")}\" \r\n" );
                }
                public void DoWrite()
                {
                    if(HeaderFileName.Length > 0)
                    {
                        var dirName = Path.GetDirectoryName(HeaderFileName);
                        if(!Directory.Exists(dirName))
                        {
                            Directory.CreateDirectory(dirName!);
                        }
                        
                        using var fs = File.OpenWrite(HeaderFileName);
                        Console.WriteLine($"generate message : {HeaderFileName}");

                        using var sw = new StreamWriter(fs);
                        sw.Write(HeaderContent);
                    }

                    if(SrcFileName.Length > 0)
                    {
                        var dirName = Path.GetDirectoryName(SrcFileName);
                        if(!Directory.Exists(dirName))
                        {
                            Directory.CreateDirectory(dirName!);
                        }

                        using var fs = File.OpenWrite(SrcFileName);
                        Console.WriteLine($"generate message : {SrcFileName}");

                        using var sw = new StreamWriter(fs);
                        sw.Write(SrcContent);
                    }
                }
            }
        }
    }
}
