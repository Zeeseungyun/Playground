
using System.Text;

namespace Zee.Generator
{
    static public partial class Program
    {
        public static void GenerateMappingFile(ParseResult parseResult)
        {
            var fileName = Path.Combine(parseResult.RootDir, "../","PacketMapping.g.cs");
            if(File.Exists(fileName))
            {
                File.Delete(fileName);
            }

            FileStream fileStream = File.OpenWrite(fileName);
            using (StreamWriter streamWriter = new StreamWriter(fileStream))
            {
                var lineBegin =
@"
namespace Zee.Message
{
    static public partial class PacketMapping
    {
        private static void startMapping()
        {
            if(pointToType.Count > 0)
            {
                return;
            }

";
                streamWriter.Write(lineBegin);
                int id = 1;
                foreach(var protoFile in parseResult.ProtoFiles)
                {
                    StringBuilder stringBuilder = new StringBuilder();
                    foreach(var elem in protoFile.Scope)
                    {
                        stringBuilder.Append(elem);
                        stringBuilder.Append('.');
                    }

                    var scope = stringBuilder.ToString();
                    foreach(var message in protoFile.Messages)
                    {
                        if(scope.Length > 0)
                        {
                            streamWriter.Write($"\t\t\tmapping({id}, typeof({scope}{message.Name}));\n");
                        }
                        else
                        {
                            streamWriter.Write($"\t\t\tmapping({id}, typeof({message.Name}));\n");
                        }
                        ++id;
                    }
                }
                
                var lineEnd =
@"
        }
    }
}
";
                streamWriter.Write(lineEnd);
            }

            fileStream.Close();
        }
    }
}
