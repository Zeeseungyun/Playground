
using Google.Protobuf;
namespace Zee.Message
{

    static public partial class PacketMapping
    {
        private static void startMapping()
        {
            if(pointToMessageType.Count > 0)
            {
                return;
            }

			mapping<Zee.Proto.Authentication.Login>(0x1002);
			mapping<Zee.Proto.Authentication.Logout>(0x1003);
			mapping<Zee.Proto.Chat.Speak>(0x2002);

        }

        static public void HandleMessage(IHandler h, PacketBase p)
        {
            switch(p.Point)
            {
				case 0x1002: h.OnMessage(p as Packet<Zee.Proto.Authentication.Login>); return;
				case 0x1003: h.OnMessage(p as Packet<Zee.Proto.Authentication.Logout>); return;
				case 0x2002: h.OnMessage(p as Packet<Zee.Proto.Chat.Speak>); return;
              
                default: throw new Exception("invalid message point");
            }
        }

    }                
    public interface IHandler 
    {
		void OnMessage(Packet<Zee.Proto.Authentication.Login> p) { Logger.LogWarning("not impl packet: Zee.Proto.Authentication.Login."); }
		void OnMessage(Packet<Zee.Proto.Authentication.Logout> p) { Logger.LogWarning("not impl packet: Zee.Proto.Authentication.Logout."); }
		void OnMessage(Packet<Zee.Proto.Chat.Speak> p) { Logger.LogWarning("not impl packet: Zee.Proto.Chat.Speak."); }

    }

}
