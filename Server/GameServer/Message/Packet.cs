using System.Net.Sockets;
using Google.Protobuf;

namespace Zee.Message
{
    public class PacketBase
    {
        public int Size = 0;
        public int Point = 0;
        public int Sequence = 0;
        public bool IsRespond = false;
        public int CalculateSize => Message!.CalculateSize() + sizeof(int) + sizeof(int);
        public IMessage? Message;
    }
    public class Packet<T> : PacketBase
        where T : class, IMessage
    {
        public T? ExactMessage => Message as T;
    }
}
