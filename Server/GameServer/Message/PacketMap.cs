using System.Reflection;
using Google.Protobuf;

namespace Zee.Net.Message
{
    static public partial class PacketMap
    {
        private static bool isStarted =false;
        private static readonly Dictionary<int, Type> pointToMessageType = new();
        private static readonly Dictionary<int, Type> pointToPacketType = new();
        private static readonly Dictionary<Type, int> typeToPoint = new();
        private static readonly Dictionary<Type, MethodInfo> clientTypeToMethodInfos = new();
        public static void Start()
        {
            if(isStarted == false)
            {
                isStarted = true;
                startMapping();
            }
        }
        private static void mapping<T>(int point) where T : class, IMessage, new()
        {
            pointToMessageType.Add(point, typeof(T)); 
            pointToPacketType.Add(point, typeof(Packet<T>));
            typeToPoint.Add(typeof(T), point);
        }
        public static IMessage? MakeMessage(int point)
        {
            var type = GetMessageType(point);
            if(type == null)
            {
                throw new ArgumentException("invalid point");
            }

            return Activator.CreateInstance(type) as IMessage;
        }
        public static PacketBase? MakePacket(int point)
        {
            var type = GetPacketType(point);
            if(type == null)
            {
                throw new ArgumentException("invalid point");
            }

            PacketBase? ret = Activator.CreateInstance(type) as PacketBase;
            ret!.InternalMessage = MakeMessage(point);
            return ret;
        }
        public static Type? GetMessageType(int point)
        {
            Type? ret = null;
            pointToMessageType.TryGetValue(point, out ret);
            return ret;
        }
        public static Type? GetPacketType(int point)
        {
            Type? ret = null;
            pointToPacketType.TryGetValue(point, out ret);
            return ret;
        }
        public static int GetMessagePoint(Type type)
        {
            int ret = 0;
            typeToPoint.TryGetValue(type, out ret);
            return ret;
        }
    }
}
