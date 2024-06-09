
using Google.Protobuf;
using MyPack;
using Zee.Net;

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

			mapping(1, typeof(MyPack.Person));
			mapping(2, typeof(Person2));
        }
        static public void HandleMessage(IHandler h, PacketBase p)
        {
            switch(p.Point)
            {
                case 1: h.OnMessage(p as Packet<Person>); return;
                case 2: h.OnMessage(p as Packet<Person2>); return;
            }
        }
    }
    
    public interface IHandler 
    {
        void OnMessage(Packet<Person> p) { Logger.LogWarning("not impl packet person."); }
        void OnMessage(Packet<Person2> p) { Logger.LogWarning("not impl packet person2."); }
    }
}
