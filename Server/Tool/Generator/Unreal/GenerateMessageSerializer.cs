
using System.Text;

namespace Zee
{
    static public partial class Generator
    {
        static public partial class Unreal
        {
            public static void GenerateMessageSerializer()
            {
                var newFile = new UnrealFile();

                newFile.SrcFileName = UnrealMessageSerializerSrcFile;
                newFile.SrcContent.Append(DescriptionGenerated);
                newFile.SrcContent.Append("#include \"ZeeNetMessageSerializer.h \" \r\n");
                newFile.SrcContent.Append("#include \"ZeeNet/Private/ZeeNetMessageSerializerDef.h\" \r\n");
                newFile.SrcContent.Append("\r\n");

                foreach(var protoFile in Parse().ProtoFiles)
                {
                    newFile.SrcContent.Append($"#include \"ZeeNet/Public/Messages/{protoFile.FileNameWithoutProto}.h\" \r\n");
                    newFile.SrcContent.Append($"#include \"ZeeNet/Private/Convert/ZeeNetMessageConvert_{protoFile.FileNameWithoutProto}.h\" \r\n");
                    //Header content end.
                }
                newFile.SrcContent.Append("\r\n");
                
                newFile.SrcContent.Append("void FZeeNetPacketSerializerMap::BuildPacketSerializer() \r\n");
                newFile.SrcContent.Append("{ \r\n");
                newFile.SrcContent.Append("\tusing namespace Zee::Net::Message::Convert; \r\n");
                newFile.SrcContent.Append("\r\n");
                    
                foreach(var protoFile in Parse().ProtoFiles)
                {
                    foreach(var msg in protoFile.Messages)
                    {
                        if(!msg.IsEnum)
                        {
                            newFile.SrcContent.Append($"\tDefaultSerializers.Add(TZeeNetMapping_ProtoToPoint<{msg.UnrealProtoName}>::Point, \r\n");
                            newFile.SrcContent.Append($"\t\tMakeShared<FZeeNetPacket<TZeeNetMapping_ProtoToPoint<{msg.UnrealProtoName}>::Point>>()); \r\n");
                            newFile.SrcContent.Append("\r\n");
                        }
                    }
                }
                
                newFile.SrcContent.Append("} \r\n\r\n");

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
