
using System.Text;

namespace Zee
{
    static public partial class Generator
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
                List<StringBuilder> stringBuilders = new();
                StringBuilder beginNamespaceScope = new();
                stringBuilders.Add(beginNamespaceScope);
                beginNamespaceScope.Append(
                    
@"
using Google.Protobuf;
namespace Zee.Message
{
");

                StringBuilder classPacketMapping = new();
                stringBuilders.Add(classPacketMapping);
                classPacketMapping.Append(
                    
@"
    static public partial class PacketMapping
    {"
                );

                StringBuilder funcStartMapping = new();
                stringBuilders.Add(funcStartMapping);
                funcStartMapping.Append(
@"
        private static void startMapping()
        {
            if(pointToType.Count > 0)
            {
                return;
            }

"
                );

                foreach(var protoFile in parseResult.ProtoFiles)
                {
                    foreach(var message in protoFile.Messages)
                    {
                        if(protoFile.ScopeString.Length > 0)
                        {
                            funcStartMapping.Append($"\t\t\tmapping(0x{message.Point.ToString("X")}, typeof({protoFile.ScopeString}.{message.Name}));\n");
                        }
                        else
                        {
                            funcStartMapping.Append($"\t\t\tmapping(0x{message.Point.ToString("X")}, typeof({message.Name}));\n");
                        }
                    }
                }

                funcStartMapping.Append(
@"
        }
");
                
                StringBuilder funcHandleMessage = new();
                stringBuilders.Add(funcHandleMessage);
                funcHandleMessage.Append(
@"
        static public void HandleMessage(IHandler h, PacketBase p)
        {
            switch(p.Point)
            {
");

                foreach(var protoFile in parseResult.ProtoFiles)
                {
                    foreach(var message in protoFile.Messages)
                    {
                        if(protoFile.ScopeString.Length > 0)
                        {
                            funcHandleMessage.Append($"\t\t\t\tcase 0x{message.Point.ToString("X")}: h.OnMessage(p as Packet<{protoFile.ScopeString}.{message.Name}>); return;\n");
                        }
                        else
                        {
                            funcHandleMessage.Append($"\t\t\t\tcase 0x{message.Point.ToString("X")}: h.OnMessage(p as Packet<{message.Name}>); return;\n");
                        }
                    }
                }
                funcHandleMessage.Append(
@"              
                default: throw new Exception(""invalid message point""); return;
            }
        }
");
                StringBuilder classIHandler = new();
                stringBuilders.Add(classIHandler);
                classIHandler.Append(
@"                
    public interface IHandler 
    {
");
                string warningMessage = "not impl packet: ";
                foreach(var protoFile in parseResult.ProtoFiles)
                {
                    foreach(var message in protoFile.Messages)
                    {
                        if(protoFile.ScopeString.Length > 0)
                        {
                            classIHandler.Append($"\t\tvoid OnMessage(Packet<{protoFile.ScopeString}.{message.Name}> p) {{ Logger.LogWarning(\"{warningMessage}{protoFile.ScopeString}.{message.Name}.\"); }}\n");
                        }
                        else
                        {
                            classIHandler.Append($"\t\tvoid OnMessage(Packet<{message.Name}> p) {{ Logger.LogWarning(\"{warningMessage}{message.Name}.\"); }}\n");
                        }
                    }
                }
                
                classIHandler.Append(
@"
    }
");
                
                StringBuilder endNamespaceScope = new();
                stringBuilders.Add(endNamespaceScope);
                endNamespaceScope.Append(
                    
@"
}
");
                foreach(var str in stringBuilders)
                {
                    streamWriter.Write(str);
                }
            }//end using(StreamWriter streamWriter = new StreamWriter(fileStream)))

            fileStream.Close();
        }
    }
}
