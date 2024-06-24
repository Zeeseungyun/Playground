////////////////////////////////////////////////////////
// This file is generated by Zeenerator.
////////////////////////////////////////////////////////

using Google.Protobuf;
namespace Zee.Net.Message
{

    static public partial class PacketMap
    {
        static private bool isMappingStarted = false;
        private static void startMapping()
        {
            if(isMappingStarted)
            {
                return;
            }

            isMappingStarted = true;

			mapping<Zee.Proto.Authentication.Login>(0x1001);
			mapping<Zee.Proto.Authentication.Logout>(0x1002);
			mapping<Zee.Proto.Chat.Speak>(0x2002);
			mapping<Zee.Proto.Chat.Speak1>(0x2001);
			mapping<Zee.Proto.Packet.Header>(0x3001);
			mapping<Zee.Proto.Test.TestMessage>(0x4001);
			mapping<Zee.Proto.Data.Account>(0x5001);

        }
    }
}
