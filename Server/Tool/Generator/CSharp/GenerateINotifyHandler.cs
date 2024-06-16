
using System.Text;

namespace Zee
{
    static public partial class Generator
    {
        static public partial class CSharp
        {        
            static public string HandlerFile => Path.GetFullPath(Path.Combine(ProtoMessageDir, "../","INotifyHandler.g.cs"));
            public static void GenerateNotifyHandlerFile()
            {
                if(File.Exists(HandlerFile))
                {
                    File.Delete(HandlerFile);
                }

                FileStream fileStream = File.OpenWrite(HandlerFile);
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

                    StringBuilder classIHandler = new();
                    stringBuilders.Add(classIHandler);
                    classIHandler.Append(
@"                
    public interface INotifyHandler 
    {
"
                    );
                    string warningMessage = "not impl packet: ";
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
                                classIHandler.Append($"\t\tvoid OnNotify(Packet<{protoFile.ScopeString}.{message.Name}> p) {{ Logger.LogWarning(\"{warningMessage}{protoFile.ScopeString}.{message.Name}.\"); }}\r\n");
                            }
                            else
                            {
                                classIHandler.Append($"\t\tvoid OnNotify(Packet<{message.Name}> p) {{ Logger.LogWarning(\"{warningMessage}{message.Name}.\"); }}\r\n");
                            }
                        }
                    }

                    classIHandler.Append(
@"
        static public void HandleNotify(INotifyHandler h, PacketBase p)
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
                                classIHandler.Append($"\t\t\t\tcase 0x{message.Point.ToString("X")}: h.OnNotify(p as Packet<{protoFile.ScopeString}.{message.Name}>); return;\r\n");
                            }
                            else
                            {
                                classIHandler.Append($"\t\t\t\tcase 0x{message.Point.ToString("X")}: h.OnNotify(p as Packet<{message.Name}>); return;\r\n");
                            }
                        }
                    }

                    classIHandler.Append(
@"              
                default: throw new Exception(""invalid message point"");
            }
        }
"
                    );
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
