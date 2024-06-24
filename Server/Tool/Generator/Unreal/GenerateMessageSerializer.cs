
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
                newFile.SrcContent.Append("#include \"ZeeNetMessageSerializer.h \" \r\n");
                newFile.SrcContent.Append("#include \"ZeeNet/Private/ZeeNetMessageSerializerDef.h\" \r\n");
                newFile.SrcContent.Append("\r\n");

                foreach(var protoFile in Parse().MessagableProtoFiles)
                {
                    newFile.SrcContent.Append($"#include \"ZeeNet/Public/Messages/{protoFile.FileNameWithoutProto}.h\" \r\n");
                    newFile.SrcContent.Append($"#include \"ZeeNet/Private/Convert/{protoFile.FileNameWithoutProto}.h\" \r\n");
                    //Header content end.
                }
                newFile.SrcContent.Append("\r\n");
                
                newFile.SrcContent.Append("void FZeeNetPacketSerializerMap::BuildPacketSerializer() \r\n");
                newFile.SrcContent.Append("{ \r\n");
                newFile.SrcContent.Append("\tusing namespace Zee::Net::Message::Convert; \r\n");
                newFile.SrcContent.Append("\r\n");
                    
                foreach(var protoFile in Parse().MessagableProtoFiles)
                {
                    foreach(var msg in protoFile.NonEnumMessages)
                    {
                        
                        newFile.SrcContent.Append($"\tDefaultSerializers.Add(TZeeNetPacketTraits<{msg.UnrealName}>::Point, \r\n");
                        newFile.SrcContent.Append($"\t\tMakeShared<FZeeNetPacketSerializer<{msg.UnrealName}>>()); \r\n");
                        newFile.SrcContent.Append("\r\n");
                    }
                }
                
                newFile.SrcContent.Append("} \r\n\r\n");
                newFile.DoWrite();
            }
        }
    }
}
