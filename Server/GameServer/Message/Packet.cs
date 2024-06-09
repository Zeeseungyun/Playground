using System.Net.Sockets;
using Google.Protobuf;

namespace Zee.Message
{
    public class PacketBase
    {
        public int Size;
        public int Point;
        public int CalculateSize => Message!.CalculateSize() + sizeof(int) + sizeof(int);
        public IMessage? Message;
    }
    public class Packet<T> : PacketBase
        where T : class, IMessage
    {
        public T? ExactMessage => Message as T;
    }
}
