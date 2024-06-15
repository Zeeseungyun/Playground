
using Google.Protobuf;
namespace Zee.Message
{

    static public partial class PacketMapping
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
			mapping<Zee.Proto.TestMessage>(0x3001);
			mapping<Zee.Proto.Test2.TestMessage2>(0x4004);
			mapping<Zee.Proto.Test2.TestMessage3>(0x4002);
			mapping<Zee.Proto.Test2.TestMessage4>(0x4003);
			mapping<Zee.Proto.Test2.TestMessage5>(0x4001);

        }

        static public void HandleMessage(IHandler h, PacketBase p)
        {
            switch(p.Point)
            {
				case 0x1001: h.OnMessage(p as Packet<Zee.Proto.Authentication.Login>); return;
				case 0x1002: h.OnMessage(p as Packet<Zee.Proto.Authentication.Logout>); return;
				case 0x2002: h.OnMessage(p as Packet<Zee.Proto.Chat.Speak>); return;
				case 0x2001: h.OnMessage(p as Packet<Zee.Proto.Chat.Speak1>); return;
				case 0x3001: h.OnMessage(p as Packet<Zee.Proto.TestMessage>); return;
				case 0x4004: h.OnMessage(p as Packet<Zee.Proto.Test2.TestMessage2>); return;
				case 0x4002: h.OnMessage(p as Packet<Zee.Proto.Test2.TestMessage3>); return;
				case 0x4003: h.OnMessage(p as Packet<Zee.Proto.Test2.TestMessage4>); return;
				case 0x4001: h.OnMessage(p as Packet<Zee.Proto.Test2.TestMessage5>); return;
              
                default: throw new Exception("invalid message point");
            }
        }

    }                
    public interface IHandler 
    {
		void OnMessage(Packet<Zee.Proto.Authentication.Login> p) { Logger.LogWarning("not impl packet: Zee.Proto.Authentication.Login."); }
		void OnMessage(Packet<Zee.Proto.Authentication.Logout> p) { Logger.LogWarning("not impl packet: Zee.Proto.Authentication.Logout."); }
		void OnMessage(Packet<Zee.Proto.Chat.Speak> p) { Logger.LogWarning("not impl packet: Zee.Proto.Chat.Speak."); }
		void OnMessage(Packet<Zee.Proto.Chat.Speak1> p) { Logger.LogWarning("not impl packet: Zee.Proto.Chat.Speak1."); }
		void OnMessage(Packet<Zee.Proto.TestMessage> p) { Logger.LogWarning("not impl packet: Zee.Proto.TestMessage."); }
		void OnMessage(Packet<Zee.Proto.Test2.TestMessage2> p) { Logger.LogWarning("not impl packet: Zee.Proto.Test2.TestMessage2."); }
		void OnMessage(Packet<Zee.Proto.Test2.TestMessage3> p) { Logger.LogWarning("not impl packet: Zee.Proto.Test2.TestMessage3."); }
		void OnMessage(Packet<Zee.Proto.Test2.TestMessage4> p) { Logger.LogWarning("not impl packet: Zee.Proto.Test2.TestMessage4."); }
		void OnMessage(Packet<Zee.Proto.Test2.TestMessage5> p) { Logger.LogWarning("not impl packet: Zee.Proto.Test2.TestMessage5."); }

    }

}
