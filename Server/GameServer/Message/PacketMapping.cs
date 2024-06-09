using System.Reflection;
using Google.Protobuf;

namespace Zee.Message
{
    static public partial class PacketMapping
    {
        private static readonly Dictionary<int, Type> pointToType = new();
        private static readonly Dictionary<Type, int> typeToPoint = new();
        private static readonly Dictionary<Type, MethodInfo> clientTypeToMethodInfos = new();
        public static void Start()
        {
            startMapping();
        }
        private static void mapping(int point, Type type)
        {
            pointToType.Add(point, type); typeToPoint.Add(type, point);
        }
        public static IMessage? MakeMessage(int point)
        {
            var type = GetPacketType(point);
            if(type == null)
            {
                throw new ArgumentException("invalid point");
            }

            return Activator.CreateInstance(type) as IMessage;
        }
        public static Type? GetPacketType(int point)
        {
            Type? ret = null;
            pointToType.TryGetValue(point, out ret);
            return ret;
        }
        public static int GetPacketPoint(Type type)
        {
            int ret = 0;
            typeToPoint.TryGetValue(type, out ret);
            return ret;
        }
        
    }
}
