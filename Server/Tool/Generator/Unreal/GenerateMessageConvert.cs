
using System.Text;

namespace Zee
{
    static public partial class Generator
    {
        static public partial class Unreal
        {
            public static void GenerateMessageConvert()
            {
                foreach(var protoFile in Parse().ProtoFiles)
                {
                    var newFile = new UnrealFile();

                    newFile.NameWihtoutProto = protoFile.FileNameWithoutProto;
                    newFile.SrcFileName = $"{UnrealMessageConvertDir}/ZeeNetMessageConvert_{newFile.NameWihtoutProto}.cpp";
                    newFile.HeaderFileName = $"{UnrealMessageConvertDir}/ZeeNetMessageConvert_{newFile.NameWihtoutProto}.h";

                    newFile.HeaderContent.Append(DescriptionGenerated);
                    newFile.HeaderContent.Append("#pragma once \r\n");
                    newFile.HeaderContent.Append("#include \"CoreMinimal.h\" \r\n");
                    newFile.HeaderContent.Append($"#include \"ZeeNet/Public/Messages/{protoFile.FileNameWithoutProto}.h\" \r\n");
                    newFile.HeaderContent.Append($"#include \"ZeeNet/Private/Messages/{protoFile.FileNameWithoutProto}.pb.h\" \r\n");
                    newFile.HeaderContent.Append($"#include \"ZeeNet/Private/ZeeNetMessageConvert.h\" \r\n");
                    newFile.HeaderContent.Append("\r\n");

                    newFile.HeaderContent.Append("namespace Zee::Net::Message::Convert \r\n");
                    newFile.HeaderContent.Append("{ \r\n");

                    foreach(var msg in protoFile.Messages)
                    {
                        if(!msg.IsEnum)
                        {
                            newFile.HeaderContent.Append($"\ttemplate<> struct TZeeNetMapping_ProtoToPoint<{msg.UnrealProtoName}> {{ static constexpr int32 Point = 0x{msg.Point.ToString("X")}; }}; \r\n");
                            newFile.HeaderContent.Append($"\ttemplate<> struct TZeeNetMapping_PointToProto<TZeeNetMapping_ProtoToPoint<{msg.UnrealProtoName}>::Point> {{ using Type = {msg.UnrealProtoName}; }}; \r\n");
                    
                            newFile.HeaderContent.Append($"\tFORCEINLINE void FromTo(const {msg.UnrealProtoName}& InFrom, {msg.UnrealName}& OutTo);\r\n");
                            newFile.HeaderContent.Append($"\tFORCEINLINE void FromTo(const {msg.UnrealName}& InFrom, {msg.UnrealProtoName}& OutTo);\r\n");
                            newFile.HeaderContent.Append("\r\n");
                            // newFile.HeaderContent.Append($"\ttemplate<> struct TIsConvertible<{msg.UnrealName}, {msg.UnrealProtoName}> {{ enum {{ Value = true }}; }};\r\n");
                            // newFile.HeaderContent.Append($"\ttemplate<> struct TIsConvertible<{msg.UnrealProtoName}, {msg.UnrealName}> {{ enum {{ Value = true }}; }};\r\n");
                        }
                    }
                    newFile.HeaderContent.Append("} \r\n");
                    //Header content end.

                    newFile.SrcContent.Append($"#include \"ZeeNet/Private/Convert/ZeeNetMessageConvert_{newFile.NameWihtoutProto}.h\" \r\n");
                    foreach(var dependency in protoFile.ProtoFileDependencies)
                    {
                        if(dependency.Proto!.Messages.Count > 0)
                        {
                            newFile.SrcContent.Append($"#include \"ZeeNet/Private/Convert/ZeeNetMessageConvert_{dependency.Proto!.FileNameWithoutProto}.h\" \r\n");
                        }
                    }
                    newFile.SrcContent.Append("\r\n");
                    
                    foreach(var msg in protoFile.Messages)
                    {
                        if(!msg.IsEnum)
                        {
                            newFile.SrcContent.Append($"void Zee::Net::Message::Convert::FromTo(const {msg.UnrealProtoName}& InFrom, {msg.UnrealName}& OutTo)\r\n");
                            newFile.SrcContent.Append("{\r\n");
                            foreach(var prop in msg.Properties)
                            {   
                                if(!prop.IsArray && (prop.IsEnum || prop.IsStandardType || prop.IsStringType))
                                {
                                    newFile.SrcContent.Append($"\tOutTo.{prop.Name} = To<{prop.TypeToUnreal}>(InFrom.{prop.Name.ToLower()}()); \r\n");
                                }
                                else if(prop.IsArray && prop.IsEnum)
                                {
                                    newFile.SrcContent.Append($"\tOutTo.{prop.Name} = To<{prop.TypeToUnreal}>(InFrom.{prop.Name.ToLower()}()); \r\n");
                                }
                                else 
                                {
                                    newFile.SrcContent.Append($"\tFromTo(InFrom.{prop.Name.ToLower()}(), OutTo.{prop.Name}); \r\n");
                                }
                            }
                            newFile.SrcContent.Append("}\r\n\r\n");

                            newFile.SrcContent.Append($"void Zee::Net::Message::Convert::FromTo(const {msg.UnrealName}& InFrom, {msg.UnrealProtoName}& OutTo)\r\n");
                            newFile.SrcContent.Append("{\r\n");
                            foreach(var prop in msg.Properties)
                            {
                                if(!prop.IsArray && (prop.IsEnum || prop.IsStandardType || prop.IsStringType))
                                {
                                    newFile.SrcContent.Append($"\tOutTo.set_{prop.Name.ToLower()}(To<{prop.TypeToUnrealProto}>(InFrom.{prop.Name})); \r\n");
                                }
                                else if(prop.IsArray && prop.IsEnum)
                                {
                                    newFile.SrcContent.Append($"\t*OutTo.mutable_{prop.Name.ToLower()}() = To<int32>(InFrom.{prop.Name}); \r\n");
                                }
                                else //maybe struct
                                {
                                    newFile.SrcContent.Append($"\tFromTo(InFrom.{prop.Name}, *OutTo.mutable_{prop.Name.ToLower()}());\r\n");
                                }
                            }
                            newFile.SrcContent.Append("}\r\n\r\n");

                        }
                    }
                    
                    //header
                    {
                        using var fs = File.OpenWrite(newFile.HeaderFileName);
                        Console.WriteLine($"generate message convert: {newFile.HeaderFileName}");
                        using var sw = new StreamWriter(fs);
                        sw.Write(newFile.HeaderContent);
                    }

                    //source
                    {
                        using var fs = File.OpenWrite(newFile.SrcFileName);
                        Console.WriteLine($"generate message convert: {newFile.SrcFileName}");
                        using var sw = new StreamWriter(fs);
                        sw.Write(newFile.SrcContent);
                    }
                }
            }
        }
    }
}