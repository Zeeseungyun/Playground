
using System.Text;

namespace Zee
{
    static public partial class Generator
    {
        static public partial class CSharp
        {        
            public static void GeneratePacketMap()
            {
                if(File.Exists(CSharpPacketMapFile))
                {
                    File.Delete(CSharpPacketMapFile);
                }

                FileStream fileStream = File.OpenWrite(CSharpPacketMapFile);
                using (StreamWriter streamWriter = new StreamWriter(fileStream))
                {
                    List<StringBuilder> stringBuilders = new();

                    StringBuilder beginNamespaceScope = new();
                    stringBuilders.Add(beginNamespaceScope);
                    beginNamespaceScope.Append(DescriptionGenerated);
                    beginNamespaceScope.Append(
@"
using Google.Protobuf;
namespace Zee.Net.Message
{
");

                    StringBuilder beginClassPacketMap = new();
                    stringBuilders.Add(beginClassPacketMap);
                    beginClassPacketMap.Append(
                    
@"
    static public partial class PacketMap
    {"
                    );

                    StringBuilder funcStartMapping = new();
                    stringBuilders.Add(funcStartMapping);
                    funcStartMapping.Append(
@"
        static private bool isMappingStarted = false;
        private static void startMapping()
        {
            if(isMappingStarted)
            {
                return;
            }

            isMappingStarted = true;

"
                    );

                    foreach(var protoFile in parseResult!.ProtoFiles)
                    {
                        foreach(var message in protoFile.Messages)
                        {
                            if(message.IsEnum)
                            {
                                continue; 
                            }

                            if(protoFile.ScopeString.Length > 0)
                            {
                                funcStartMapping.Append($"\t\t\tmapping<{protoFile.ScopeString}.{message.Name}>(0x{message.Point.ToString("X")});\r\n");
                            }
                            else
                            {
                                funcStartMapping.Append($"\t\t\tmapping<{message.Name}>(0x{message.Point.ToString("X")});\r\n");
                            }
                        }
                    }

                    funcStartMapping.Append(
@"
        }
    }
}
"
                    );

                    foreach(var str in stringBuilders)
                    {
                        streamWriter.Write(str);
                    }
                }//end using(StreamWriter streamWriter = new StreamWriter(fileStream)))

                fileStream.Close();
            }
        }
    }
}
