using System.Net.Sockets;
using Google.Protobuf;

namespace Zee.Message
{
    public class PacketBase
    {
        public int Size = -1;
        public int Point = -1;
        public int Seq = -1;
        public int CalculateSize => Message!.CalculateSize() + sizeof(int) + sizeof(int);
        public IMessage? Message;
    }
    public class Packet<T> : PacketBase
        where T : class, IMessage
    {
        public T? ExactMessage => Message as T;
    }
}
