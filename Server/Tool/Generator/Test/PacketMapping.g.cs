
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

			mapping(0x1001, typeof(Temp1.T2.Tt4.Tt1.T12.Person));
			mapping(0x1002, typeof(Temp1.T2.Tt4.Tt1.T12.Person2));
			mapping(0x2001, typeof(Temp1.T2.Tt4.Tt1.T12.swe1.Test444));
			mapping(0x3001, typeof(Depth1Test2));
			mapping(0x4001, typeof(P1.Depth2Test3));

        }

        static public void HandleMessage(IHandler h, PacketBase p)
        {
            switch(p.Point)
            {
				case 0x1001: h.OnMessage(p as Packet<Temp1.T2.Tt4.Tt1.T12.Person>); return;
				case 0x1002: h.OnMessage(p as Packet<Temp1.T2.Tt4.Tt1.T12.Person2>); return;
				case 0x2001: h.OnMessage(p as Packet<Temp1.T2.Tt4.Tt1.T12.swe1.Test444>); return;
				case 0x3001: h.OnMessage(p as Packet<Depth1Test2>); return;
				case 0x4001: h.OnMessage(p as Packet<P1.Depth2Test3>); return;
              
                default: throw new Exception("invalid message point");
            }
        }

    }                
    public interface IHandler 
    {
		void OnMessage(Packet<Temp1.T2.Tt4.Tt1.T12.Person> p) { Logger.LogWarning("not impl packet: Temp1.T2.Tt4.Tt1.T12.Person."); }
		void OnMessage(Packet<Temp1.T2.Tt4.Tt1.T12.Person2> p) { Logger.LogWarning("not impl packet: Temp1.T2.Tt4.Tt1.T12.Person2."); }
		void OnMessage(Packet<Temp1.T2.Tt4.Tt1.T12.swe1.Test444> p) { Logger.LogWarning("not impl packet: Temp1.T2.Tt4.Tt1.T12.swe1.Test444."); }
		void OnMessage(Packet<Depth1Test2> p) { Logger.LogWarning("not impl packet: Depth1Test2."); }
		void OnMessage(Packet<P1.Depth2Test3> p) { Logger.LogWarning("not impl packet: P1.Depth2Test3."); }

    }

}
