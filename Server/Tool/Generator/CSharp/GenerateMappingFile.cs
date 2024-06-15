
using System.Text;

namespace Zee
{
    static public partial class Generator
    {
        static public partial class CSharp
        {        
            static public string PacketMappingFile => Path.GetFullPath(Path.Combine(ProtoSrcFilePath, "../","PacketMapping.g.cs"));
            public static void GenerateMappingFile(ParseResult parseResult)
            {
                if(File.Exists(PacketMappingFile))
                {
                    File.Delete(PacketMappingFile);
                }

                FileStream fileStream = File.OpenWrite(PacketMappingFile);
                using (StreamWriter streamWriter = new StreamWriter(fileStream))
                {
                    List<StringBuilder> stringBuilders = new();

                    StringBuilder beginNamespaceScope = new();
                    stringBuilders.Add(beginNamespaceScope);
                    beginNamespaceScope.Append(
@"
using Google.Protobuf;
namespace Zee.Message
{
");

                    StringBuilder beginClassPacketMapping = new();
                    stringBuilders.Add(beginClassPacketMapping);
                    beginClassPacketMapping.Append(
                    
@"
    static public partial class PacketMapping
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

                    foreach(var protoFile in parseResult.ProtoFiles)
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
"
                    );
                
                    StringBuilder funcHandleMessage = new();
                    stringBuilders.Add(funcHandleMessage);
                    funcHandleMessage.Append(
@"
        static public void HandleMessage(IHandler h, PacketBase p)
        {
            switch(p.Point)
            {
"
                    );

                    foreach(var protoFile in parseResult.ProtoFiles)
                    {
                        foreach(var message in protoFile.Messages)
                        {
                            if(message.IsEnum)
                            {
                                continue; 
                            }

                            if(protoFile.ScopeString.Length > 0)
                            {
                                funcHandleMessage.Append($"\t\t\t\tcase 0x{message.Point.ToString("X")}: h.OnMessage(p as Packet<{protoFile.ScopeString}.{message.Name}>); return;\r\n");
                            }
                            else
                            {
                                funcHandleMessage.Append($"\t\t\t\tcase 0x{message.Point.ToString("X")}: h.OnMessage(p as Packet<{message.Name}>); return;\r\n");
                            }
                        }
                    }

                    funcHandleMessage.Append(
@"              
                default: throw new Exception(""invalid message point"");
            }
        }
"
                    );
                    StringBuilder endClassPacketMapping = new();
                    stringBuilders.Add(endClassPacketMapping);
                    endClassPacketMapping.Append(
                    
@"
    }"
                    );

                    StringBuilder classIHandler = new();
                    stringBuilders.Add(classIHandler);
                    classIHandler.Append(
@"                
    public interface IHandler 
    {
"
                    );
                    string warningMessage = "not impl packet: ";
                    foreach(var protoFile in parseResult.ProtoFiles)
                    {
                        foreach(var message in protoFile.Messages)
                        {
                            if(message.IsEnum)
                            {
                                continue; 
                            }

                            if(protoFile.ScopeString.Length > 0)
                            {
                                classIHandler.Append($"\t\tvoid OnMessage(Packet<{protoFile.ScopeString}.{message.Name}> p) {{ Logger.LogWarning(\"{warningMessage}{protoFile.ScopeString}.{message.Name}.\"); }}\r\n");
                            }
                            else
                            {
                                classIHandler.Append($"\t\tvoid OnMessage(Packet<{message.Name}> p) {{ Logger.LogWarning(\"{warningMessage}{message.Name}.\"); }}\r\n");
                            }
                        }
                    }

                    classIHandler.Append(
@"
    }
"
                    );

                    StringBuilder endNamespaceScope = new();
                    stringBuilders.Add(endNamespaceScope);
                    endNamespaceScope.Append(
@"
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
