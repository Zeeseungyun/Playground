
using System.Text;

namespace Zee
{
    static public partial class Generator
    {
        static public partial class Unreal
        {
            public static void GenerateRequestHandler()
            {
                var requestHandlerRelativePath = Path.GetRelativePath(UnrealZeeNetDir, UnrealRequestHandlerFile);
                requestHandlerRelativePath = requestHandlerRelativePath.Replace("\\", "/");

                foreach(var protoFile in Parse().ProtoFiles)
                {
                    if(protoFile.FileNameWithoutProto == "Packet")
                    {
                        Console.WriteLine("packet message passed.");
                        continue;
                    }

                    var newFile = new UnrealFile();
                    newFile.NameWihtoutProto = protoFile.FileNameWithoutProto;

                    ////////////////////////
                    ///header
                    ////////////////////////

                    newFile.HeaderFileName = $"{UnrealInterfaceRequestHandlerDir}/{newFile.NameWihtoutProto}.h";
                    newFile.HeaderContent.Append("#pragma once\r\n");
                    newFile.HeaderContent.Append($"#include \"ZeeNet.h\"\r\n");

                    var relativePublicMessageDir = Path.GetRelativePath(UnrealZeeNetDir, UnrealMessageDir);
                    relativePublicMessageDir = relativePublicMessageDir.Replace("\\", "/");

                    newFile.HeaderContent.Append($"#include \"ZeeNet/{relativePublicMessageDir}{newFile.NameWihtoutProto}.h\"\r\n");
                    newFile.HeaderContent.Append($"#include \"ZeeNet/{requestHandlerRelativePath}\"\r\n");
                    newFile.HeaderContent.Append("\r\n");

                    newFile.HeaderContent.Append($"struct ZEENET_API IZeeNetRequestHandler_{newFile.NameWihtoutProto} \r\n");
                    newFile.HeaderContent.Append($"\t: public IZeeNetRequestHandler \r\n");
                    newFile.HeaderContent.Append($"{{\r\n");
                    newFile.HeaderContent.Append($"\tconst FString& GetHandlerName() const final {{ static FString Name = TEXT(\"Request_{newFile.NameWihtoutProto}\"); return Name; }} \r\n");
                    newFile.HeaderContent.Append("\r\n");

                    foreach(var msg in protoFile.Messages)
                    {
                        if(!msg.IsEnum)
                        {
                            newFile.HeaderContent.Append($"\t[[nodiscard]] virtual EZeeNetRequestHandlerResponse OnRequest(const TSharedPtr<IZeeNetResponser>& InResponser, const {msg.UnrealName}& InMessage) {{ \r\n");
                            newFile.HeaderContent.Append($"\t\treturn EZeeNetRequestHandlerResponse::NoResponse; \r\n");
                            newFile.HeaderContent.Append($"\t}}\r\n");
                            newFile.HeaderContent.Append($"\r\n");
                        }
                    }

                    newFile.HeaderContent.Append($"}};\r\n");
                    newFile.HeaderContent.Append("\r\n");

                    ////////////////////////
                    ///source
                    ////////////////////////

                    newFile.SrcFileName = $"{UnrealConsumeRequestHandlerDir}/Request_{newFile.NameWihtoutProto}.g.cpp"; 
                    
                    newFile.SrcContent.Append(
@"#include ""ZeeNetClient.h""
#include ""ZeeNet/Private/ZeeNetMessageSerializerDef.h""
#include ""ZeeNet/Private/Handler/RequestDef.h""

");
                    var relativeHeaderFile = Path.GetRelativePath(UnrealZeeNetDir, newFile.HeaderFileName);
                    relativeHeaderFile = relativeHeaderFile.Replace("\\", "/");
                    newFile.SrcContent.Append($"#include \"ZeeNet/{relativeHeaderFile}\" \r\n");
                    newFile.SrcContent.Append($"#include \"ZeeNet/{relativeHeaderFile}\" \r\n");
                    newFile.SrcContent.Append("\r\n");

                    newFile.SrcContent.Append($"FZeeNetRequestHandlerArray* FindRequestHandler_{newFile.NameWihtoutProto}(int32 Point, TMap<FString, FZeeNetRequestHandlerArray>& RequestHandlers) {{ \r\n");
                    newFile.SrcContent.Append($"\tswitch (Point) {{ \r\n");
                    foreach(var msg in protoFile.NonEnumMessages)
                    {
                        newFile.SrcContent.Append($"\tcase TZeeNetMapping_UnrealToPoint<{msg.UnrealName}>::Point: ");
                        if(protoFile.NonEnumMessages.Last() != msg)
                        {
                            newFile.SrcContent.Append("[[fallthrough]]; \r\n");
                        }
                        else
                        {
                            newFile.SrcContent.Append("\r\n");
                        }
                    }

                    newFile.SrcContent.Append($"\t\treturn RequestHandlers.Find(TEXT(\"Request_{newFile.NameWihtoutProto}\")); \r\n");
                    newFile.SrcContent.Append($"\tdefault: break; \r\n");
                    newFile.SrcContent.Append($"\t}}\r\n");
                    newFile.SrcContent.Append("\r\n");
                    newFile.SrcContent.Append("\treturn nullptr; \r\n");
                    newFile.SrcContent.Append("}\r\n");
                    newFile.SrcContent.Append("\r\n");

                    newFile.SrcContent.Append($"EZeeNetRequestHandlerResponse ConsumeRequestMessage_{newFile.NameWihtoutProto}(TSharedPtr<IZeeNetResponser> Responser\r\n\t, TSharedPtr<struct FZeeNetPacketSerializerBase> Packet\r\n\t, FZeeNetRequestHandlerArray& RequestHandlers) {{ \r\n");
                    newFile.SrcContent.Append($"\tconst int32 PacketPoint = Packet->GetHeader().Point; \r\n");
                    newFile.SrcContent.Append($"\tswitch (PacketPoint) {{ \r\n");
                    foreach(var msg in protoFile.NonEnumMessages)
                    {
                        newFile.SrcContent.Append($"\t\tZEENET_CASE_CONSUME_REQUEST({newFile.NameWihtoutProto}, {msg.Name});\r\n");
                    }

                    newFile.SrcContent.Append($"\tdefault: break; \r\n");
                    newFile.SrcContent.Append($"\t}} \r\n");
                    newFile.SrcContent.Append("\r\n");
                    newFile.SrcContent.Append("\treturn EZeeNetRequestHandlerResponse::NoResponse; \r\n");
                    newFile.SrcContent.Append("}\r\n");
                    newFile.SrcContent.Append("\r\n");

                    newFile.DoWrite(); 
                } //for (var proto in protofiles)

                {
                    var newFile = new UnrealFile();
                    newFile.SrcFileName = UnrealConsumeRequestFile;
                    newFile.SrcContent.Append(
@"#include ""ZeeNetClient.h""
#include ""ZeeNet/Public/Messages/Packet.h""
#include ""ZeeNet/Private/ZeeNetMessageSerializerDef.h""
#include ""ZeeNet/Public/Interface/Handler/ZeeNetRequestHandler.h""
#include ""ZeeNet/Private/Handler/RequestDef.h""

"
);
                    foreach(var protoFile in Parse().ProtoFiles)
                    {
                        if(protoFile.FileNameWithoutProto == "Packet")
                        {
                            continue;
                        }

                        newFile.SrcContent.Append($"extern FZeeNetRequestHandlerArray* FindRequestHandler_{protoFile.FileNameWithoutProto}(int32 Point, TMap<FString, FZeeNetRequestHandlerArray>& RequestHandlers); \r\n");
                        newFile.SrcContent.Append($"extern EZeeNetRequestHandlerResponse ConsumeRequestMessage_{protoFile.FileNameWithoutProto}(\r\n\tTSharedPtr<IZeeNetResponser> Responser\r\n\t, TSharedPtr<struct FZeeNetPacketSerializerBase> Packet\r\n\t, FZeeNetRequestHandlerArray& RequestHandlers\r\n); \r\n");
                    }// for proto

                    newFile.SrcContent.Append("\r\n");
                    newFile.SrcContent.Append("EZeeNetRequestHandlerResponse FZeeNetClient::ConsumeRequestMessage(TSharedPtr<struct FZeeNetPacketSerializerBase> Packet) { \r\n");
                    newFile.SrcContent.Append("\tCheckRequestHandlers(); \r\n");
                    newFile.SrcContent.Append("\tFZeeNetRequestHandlerArray* Found = nullptr; \r\n");
                    newFile.SrcContent.Append("\tTSharedPtr<IZeeNetResponser> Responser = StaticCastSharedPtr<IZeeNetResponser>(AsShared().ToSharedPtr()); \r\n");
                    newFile.SrcContent.Append("\r\n");
                    
                    foreach(var protoFile in Parse().ProtoFiles)
                    {
                        if(protoFile.FileNameWithoutProto == "Packet")
                        {
                            continue;
                        }

                        newFile.SrcContent.Append($"\tFound = FindRequestHandler_{protoFile.FileNameWithoutProto}(Packet->GetHeader().Point, RequestHandlers); \r\n");
                        newFile.SrcContent.Append($"\tif (Found) {{ \r\n");
                        newFile.SrcContent.Append($"\t\tif (Found->Num() > 0) return ConsumeRequestMessage_{protoFile.FileNameWithoutProto}(Responser, Packet, *Found); \r\n");
                        newFile.SrcContent.Append($"\t\treturn EZeeNetRequestHandlerResponse::NoResponse; \r\n");
                        newFile.SrcContent.Append($"\t}}\r\n");
                        newFile.SrcContent.Append("\r\n");

                    }// for proto
                    newFile.SrcContent.Append("\treturn EZeeNetRequestHandlerResponse::NoResponse;\r\n");
                    newFile.SrcContent.Append("}\r\n");
                    newFile.SrcContent.Append("\r\n");
                    
                    newFile.SrcContent.Append("void FZeeNetClient::BuildValidRequestHandlerNames() {\r\n");
                    
                    foreach(var protoFile in Parse().ProtoFiles)
                    {
                        if(protoFile.FileNameWithoutProto == "Packet")
                        {
                            continue;
                        }

                        newFile.SrcContent.Append($"\tValidRequestHandlerNames.Add(TEXT(\"Request_{protoFile.FileNameWithoutProto}\")); \r\n");
                    }// for proto

                    newFile.SrcContent.Append("\r\n");
                    newFile.SrcContent.Append("}\r\n");
                    newFile.SrcContent.Append("\r\n");

                    newFile.DoWrite();
                }// new file
            } 
        } 
    } 
} 

