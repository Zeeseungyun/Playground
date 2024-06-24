
using System.Text;

namespace Zee
{
    static public partial class Generator
    {
        static public partial class Unreal
        {
            public static void GenerateNotifyHandler()
            {
                var notifyHandlerRelativePath = Path.GetRelativePath(UnrealZeeNetDir, UnrealNotifyHandlerFile);
                notifyHandlerRelativePath = notifyHandlerRelativePath.Replace("\\", "/");

                foreach(var protoFile in Parse().MessagableProtoFiles)
                {
                    var newFile = new UnrealFile();
                    newFile.NameWihtoutProto = protoFile.FileNameWithoutProto;

                    ////////////////////////
                    ///header
                    ////////////////////////

                    newFile.HeaderFileName = $"{UnrealInterfaceNotifyHandlerDir}/{newFile.NameWihtoutProto}.h";
                    newFile.HeaderContent.Append("#pragma once\r\n");
                    newFile.HeaderContent.Append($"#include \"ZeeNet.h\"\r\n");

                    var relativePublicMessageDir = Path.GetRelativePath(UnrealZeeNetDir, UnrealMessageDir);
                    relativePublicMessageDir = relativePublicMessageDir.Replace("\\", "/");

                    newFile.HeaderContent.Append($"#include \"ZeeNet/{relativePublicMessageDir}{newFile.NameWihtoutProto}.h\"\r\n");
                    newFile.HeaderContent.Append($"#include \"ZeeNet/{notifyHandlerRelativePath}\"\r\n");
                    newFile.HeaderContent.Append("\r\n");

                    newFile.HeaderContent.Append($"struct ZEENET_API IZeeNetNotifyHandler_{newFile.NameWihtoutProto} \r\n");
                    newFile.HeaderContent.Append($"\t: public IZeeNetNotifyHandler \r\n");
                    newFile.HeaderContent.Append($"{{\r\n");
                    newFile.HeaderContent.Append($"\tconst FString& GetHandlerName() const final {{ static FString Name = TEXT(\"Notify_{newFile.NameWihtoutProto}\"); return Name; }} \r\n");
                    newFile.HeaderContent.Append("\r\n");

                    foreach(var msg in protoFile.Messages)
                    {
                        if(!msg.IsEnum)
                        {
                            newFile.HeaderContent.Append($"\tvirtual void OnNotify(const {msg.UnrealName}& InMessage) {{ UE_LOG(LogZeeNet, Warning, TEXT(\"OnNotify is not impl: '{msg.UnrealName}'\")); }} \r\n");
                        }
                    }

                    newFile.HeaderContent.Append($"}};\r\n");
                    newFile.HeaderContent.Append("\r\n");

                    ////////////////////////
                    ///source
                    ////////////////////////

                    newFile.SrcFileName = $"{UnrealConsumeNotifyHandlerDir}/Notify_{newFile.NameWihtoutProto}.g.cpp"; 
                    
                    newFile.SrcContent.Append(
@"#include ""ZeeNetClient.h""
#include ""ZeeNet/Public/Messages/Packet.h""
#include ""ZeeNet/Private/ZeeNetMessageSerializerDef.h""
#include ""ZeeNet/Private/Handler/NotifyDef.h""
");
                    newFile.SrcContent_IncludeHeaderFile();
                    newFile.SrcContent.Append("\r\n");

                    newFile.SrcContent.Append($"FZeeNetNotifyHandlerArray* FindNotifyHandler_{newFile.NameWihtoutProto}(int32 Point, TMap<FString, FZeeNetNotifyHandlerArray>& NotifyHandlers) {{ \r\n");
                    newFile.SrcContent.Append($"\tswitch (Point) {{ \r\n");
                    foreach(var msg in protoFile.NonEnumMessages)
                    {
                        newFile.SrcContent.Append($"\tcase TZeeNetPacketTraits<{msg.UnrealName}>::Point: ");
                        if(protoFile.NonEnumMessages.Last() != msg)
                        {
                            newFile.SrcContent.Append("[[fallthrough]]; \r\n");
                        }
                        else
                        {
                            newFile.SrcContent.Append("\r\n");
                        }
                    }

                    newFile.SrcContent.Append($"\t\treturn NotifyHandlers.Find(TEXT(\"Notify_{newFile.NameWihtoutProto}\")); \r\n");
                    newFile.SrcContent.Append($"\tdefault: break; \r\n");
                    newFile.SrcContent.Append($"\t}}\r\n");
                    newFile.SrcContent.Append("\r\n");
                    newFile.SrcContent.Append("\treturn nullptr; \r\n");
                    newFile.SrcContent.Append("}\r\n");
                    newFile.SrcContent.Append("\r\n");

                    newFile.SrcContent.Append($"bool ConsumeNotifyMessage_{newFile.NameWihtoutProto}(TSharedPtr<struct FZeeNetPacketSerializerBase> Packet, FZeeNetNotifyHandlerArray& NotifyHandlers) {{ \r\n");
                    newFile.SrcContent.Append($"\tconst int32 PacketPoint = Packet->GetHeader().Point; \r\n");
                    newFile.SrcContent.Append($"\tswitch (PacketPoint) {{ \r\n");
                    foreach(var msg in protoFile.NonEnumMessages)
                    {
                        newFile.SrcContent.Append($"\t\tZEENET_CASE_CONSUME_NOTIFY({newFile.NameWihtoutProto}, {msg.Name});\r\n");
                    }

                    newFile.SrcContent.Append($"\tdefault: break; \r\n");
                    newFile.SrcContent.Append($"\t}} \r\n");
                    newFile.SrcContent.Append("\r\n");
                    newFile.SrcContent.Append("\treturn false; \r\n");
                    newFile.SrcContent.Append("}\r\n");
                    newFile.SrcContent.Append("\r\n");

                    newFile.DoWrite(); 
                } //for (var proto in MessagableProtoFiles)

                {
                    var newFile = new UnrealFile();
                    newFile.SrcFileName = UnrealConsumeNotifyFile;
                    newFile.SrcContent.Append(
@"#include ""ZeeNetClient.h""
#include ""ZeeNet/Private/ZeeNetMessageSerializerDef.h""
#include ""ZeeNet/Public/Interface/Handler/ZeeNetNotifyHandler.h""
#include ""ZeeNet/Private/Handler/NotifyDef.h""

"
);
                    foreach(var protoFile in Parse().MessagableProtoFiles)
                    {
                        newFile.SrcContent.Append($"extern FZeeNetNotifyHandlerArray* FindNotifyHandler_{protoFile.FileNameWithoutProto}(int32 Point, TMap<FString, FZeeNetNotifyHandlerArray>& NotifyHandlers); \r\n");
                        newFile.SrcContent.Append($"extern bool ConsumeNotifyMessage_{protoFile.FileNameWithoutProto}(TSharedPtr<struct FZeeNetPacketSerializerBase> Packet, FZeeNetNotifyHandlerArray& NotifyHandlers); \r\n");
                    }// for proto

                    newFile.SrcContent.Append("\r\n");
                    newFile.SrcContent.Append("bool FZeeNetClient::ConsumeNotifyMessage(TSharedPtr<struct FZeeNetPacketSerializerBase> Packet) { \r\n");
                    newFile.SrcContent.Append("\tCheckNotifyHandlers(); \r\n");
                    newFile.SrcContent.Append("\tFZeeNetNotifyHandlerArray* Found = nullptr; \r\n");
                    newFile.SrcContent.Append("\r\n");
                    
                    foreach(var protoFile in Parse().MessagableProtoFiles)
                    {
                        newFile.SrcContent.Append($"\tFound = FindNotifyHandler_{protoFile.FileNameWithoutProto}(Packet->GetHeader().Point, NotifyHandlers); \r\n");
                        newFile.SrcContent.Append($"\tif (Found) {{ if(Found->Num() > 0) ConsumeNotifyMessage_{protoFile.FileNameWithoutProto}(Packet, *Found); return false; }} \r\n");
                        newFile.SrcContent.Append("\r\n");
                    }// for proto

                    newFile.SrcContent.Append("\treturn false;\r\n");
                    newFile.SrcContent.Append("}\r\n");
                    
                    newFile.SrcContent.Append("\r\n");
                    newFile.SrcContent.Append("void FZeeNetClient::BuildValidNotifyHandlerNames() {\r\n");
                    
                    foreach(var protoFile in Parse().MessagableProtoFiles)
                    {
                        newFile.SrcContent.Append($"\tValidNotifyHandlerNames.Add(TEXT(\"Notify_{protoFile.FileNameWithoutProto}\")); \r\n");
                    }// for proto

                    newFile.SrcContent.Append("\r\n");
                    newFile.SrcContent.Append("}\r\n");

                    newFile.DoWrite();
                }// new file
            } 
        } 
    } 
} 

