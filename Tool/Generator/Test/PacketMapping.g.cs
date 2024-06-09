
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

			mapping(1, typeof(Temp1.T2.Tt4.Tt1.T12.Person));
			mapping(2, typeof(Temp1.T2.Tt4.Tt1.T12.Person2));
			mapping(3, typeof(Temp1.T2.Tt4.Tt1.T12.swe1.Test444));
			mapping(4, typeof(Depth1Test2));
			mapping(5, typeof(P1.Depth2Test3));

        }
    }
}
