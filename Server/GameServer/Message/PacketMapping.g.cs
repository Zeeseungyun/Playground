
using Google.Protobuf;
namespace Zee.Message
{

    static public partial class PacketMapping
    {
        private static void startMapping()
        {
            if(pointToType.Count > 0)
            {
                return;
            }

			mapping(0x1001, typeof(Playground.Authentication.Login));
			mapping(0x1002, typeof(Playground.Authentication.Logout));

        }

        static public void HandleMessage(IHandler h, PacketBase p)
        {
            switch(p.Point)
            {
				case 0x1001: h.OnMessage(p as Packet<Playground.Authentication.Login>); return;
				case 0x1002: h.OnMessage(p as Packet<Playground.Authentication.Logout>); return;
              
                default: throw new Exception("invalid message point"); return;
            }
        }
                
    public interface IHandler 
    {
		void OnMessage(Packet<Playground.Authentication.Login> p) { Logger.LogWarning("not impl packet: Playground.Authentication.Login."); }
		void OnMessage(Packet<Playground.Authentication.Logout> p) { Logger.LogWarning("not impl packet: Playground.Authentication.Logout."); }

    }

}
