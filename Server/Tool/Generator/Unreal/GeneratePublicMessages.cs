
using System.Text;

namespace Zee
{
    static public partial class Generator
    {
        static public partial class Unreal
        {
            public static void GeneratePublicMessages()
            {
                foreach(var protoFile in Parse().ProtoFiles)
                {
                    var newFile = new UnrealFile();

                    newFile.NameWihtoutProto = protoFile.FileNameWithoutProto;
                    newFile.SrcFileName = string.Empty; //현재 소스파일은 사용하지 않을 예정.
                    newFile.HeaderFileName = $"{UnrealMessageDir}/{newFile.NameWihtoutProto}.h";
                    newFile.HeaderContent.Append(DescriptionGenerated);
                    newFile.HeaderContent.Append("#pragma once\r\n");
                    newFile.HeaderContent.Append("#include \"CoreMinimal.h\"\r\n");
                    newFile.HeaderContent.Append($"#include \"ZeeNet/Public/ZeeNetPacketMapping.h\"\r\n");

                    foreach(var dependency in protoFile.ProtoFileDependencies)
                    {
                        if(dependency.Proto!.Messages.Count > 0)
                        {
                            newFile.HeaderContent.Append($"#include \"ZeeNet/Public/Messages/{dependency.Proto!.FileNameWithoutProto}.h\"\r\n");
                        }
                    }
                    
                    if(protoFile.Messages.Count != 0)
                    {
                        newFile.HeaderContent.Append($"#include \"{newFile.NameWihtoutProto}.generated.h\"\r\n");
                        newFile.HeaderContent.Append("\r\n");
                    }
                    
                    foreach(var msg in protoFile.Messages)
                    {
                        if(msg.IsEnum)
                        {
                            newFile.HeaderContent.Append($"UENUM(BlueprintType) \r\n");
                            newFile.HeaderContent.Append($"enum class {msg.UnrealName} : uint8 \r\n");
                            newFile.HeaderContent.Append("{ \r\n");

                            foreach(var prop in msg.Properties)
                            {
                                newFile.HeaderContent.Append($"\t{prop.Name} = {prop.OrderOrEnumValue},\r\n");
                            }

                            newFile.HeaderContent.Append("}; \r\n\r\n");
                        }
                        else //if !msg.IsEnum
                        {
                            newFile.HeaderContent.Append($"USTRUCT(BlueprintType) \r\n");
                            newFile.HeaderContent.Append($"struct {msg.UnrealName} \r\n");
                            newFile.HeaderContent.Append("{ \r\n");
                            newFile.HeaderContent.Append("\tGENERATED_BODY()\r\n\r\n");
                            foreach(var prop in msg.Properties)
                            {
                                newFile.HeaderContent.Append($"\tUPROPERTY(BlueprintReadWrite) \r\n");
                                if(prop.IsArray)
                                {
                                    if(prop.IsStandardType && !prop.IsStringType)
                                    {
                                        newFile.HeaderContent.Append($"\tTArray<{prop.TypeToUnreal}> {prop.Name}; \r\n");
                                    }
                                    else
                                    {
                                        newFile.HeaderContent.Append($"\tTArray<{prop.TypeToUnreal}> {prop.Name}; \r\n");
                                    }
                                }
                                else
                                {
                                    if(prop.IsStandardType && !prop.IsStringType)
                                    {
                                        newFile.HeaderContent.Append($"\t{prop.TypeToUnreal} {prop.Name} = static_cast<{prop.TypeToUnreal}>(0); \r\n");
                                    }
                                    else if(prop.IsEnum)
                                    {
                                        newFile.HeaderContent.Append($"\t{prop.TypeToUnreal} {prop.Name} = static_cast<{prop.TypeToUnreal}>(0); \r\n");
                                    }
                                    else
                                    {
                                        newFile.HeaderContent.Append($"\t{prop.TypeToUnreal} {prop.Name}; \r\n");
                                    }
                                }
                                
                                newFile.HeaderContent.Append("\r\n");
                            }
                            newFile.HeaderContent.Append("}; \r\n");
                            newFile.HeaderContent.Append($"template<> struct TZeeNetMapping_UnrealToPoint<{msg.UnrealName}> {{ static constexpr int32 Point = 0x{msg.Point.ToString("X")}; }}; \r\n");
                            newFile.HeaderContent.Append($"template<> struct TZeeNetMapping_PointToUnreal<TZeeNetMapping_UnrealToPoint<{msg.UnrealName}>::Point> {{ using Type = {msg.UnrealName}; }}; \r\n");
                            newFile.HeaderContent.Append("\r\n\r\n");
                        }
                    }

                    using var fs = File.OpenWrite(newFile.HeaderFileName);
                    Console.WriteLine($"generate message : {newFile.HeaderFileName}");
                    
                    using var sw = new StreamWriter(fs);
                    sw.Write(newFile.HeaderContent);
                }//function 
            }
        }
    }
}
