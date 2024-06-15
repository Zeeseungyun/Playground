
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
            }
        }
    }
}
