using System.Net.Sockets;
using Google.Protobuf;

namespace Zee.Net.Message
{
    static public class PacketSerializer
    {
        static public void SerializePacket(this Stream stream, PacketBase p)
        {
            p.Header.PacketSize = p.InternalMessage!.CalculateSize();
            p.Header.Point = PacketMap.GetMessagePoint(p.InternalMessage.GetType());
            if(p.Header.PacketType == Proto.Packet.Type.None)
            {
                throw new InvalidDataException("must be set packet type.");
            }

            stream.Write(BitConverter.GetBytes(p.Header.CalculateSize()), 0, sizeof(Int32));
            p.Header.WriteTo(stream);
            p.InternalMessage.WriteTo(stream);
            stream.Flush();
        }

        static public PacketBase DeserializePacket(this Stream stream, byte[] buffer, Int32 bufferSize)
        {
            int readBytes = stream.Read(buffer, 0, sizeof(Int32));
            if(sizeof(Int32) != readBytes) throw new InvalidDataException("invalid data.");       
            Proto.Packet.Header Header = new();
            
            int headerSize = BitConverter.ToInt32(buffer);
            readBytes = stream.Read(buffer, 0, headerSize);
            if(headerSize != readBytes) throw new InvalidDataException("invalid header size.");
            Header.MergeFrom(buffer, 0, headerSize);
            
            readBytes = stream.Read(buffer, 0, Header.PacketSize);
            if(Header.PacketSize != readBytes) throw new InvalidDataException("invalid packet size.");
            var ret = PacketMap.MakePacket(Header.Point);
            ret!.Header = Header;
            ret.InternalMessage.MergeFrom(buffer, 0, Header.PacketSize);
            return ret;
        }
    }
    public class PacketBase
    {
        //Packet데이터에서 Header데이터는 보여선 안됨.
        //이건 수정해야하지만, 일단 남겨둠.
        public Zee.Proto.Packet.Header Header = new();
        public int Point => Header.Point;
        public IMessage? InternalMessage;
    }
    public class Packet<T> : PacketBase
        where T : class, IMessage, new()
    {
        public Packet()
        {
            InternalMessage = new T();
        }
        public T Message 
        {
            get {
               return (T)InternalMessage!;
            }
            set {
                InternalMessage = value;
            }
        }
    }
}
