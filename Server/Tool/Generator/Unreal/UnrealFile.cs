
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
                public void DoWrite()
                {
                    if(HeaderFileName.Length > 0)
                    {
                        using var fs = File.OpenWrite(HeaderFileName);
                        Console.WriteLine($"generate message : {HeaderFileName}");

                        using var sw = new StreamWriter(fs);
                        sw.Write(HeaderContent);
                    }

                    if(SrcFileName.Length > 0)
                    {
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
