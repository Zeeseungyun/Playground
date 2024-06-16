using System.Net.Sockets;
using Google.Protobuf;

namespace Zee.Net.Message
{
    static public class PacketSerializer
    {
        static public void SerializePacket(this Stream stream, PacketBase p)
        {
            Int32 headerSize = p.Header.CalculateSize();
            stream.Write(BitConverter.GetBytes(headerSize));
            p.Header.PacketSize = p.Message!.CalculateSize();
            p.Header.MergeFrom(stream);
            p.Message.MergeFrom(stream);
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
            ret.Message.MergeFrom(buffer, 0, Header.PacketSize);
            return ret;
        }
    }
    public class PacketBase
    {
        //Packet데이터에서 Header데이터는 보여선 안됨.
        //이건 수정해야하지만, 일단 남겨둠.
        public Zee.Proto.Packet.Header Header = new();
        public int Point => Header.Point;
        public int Sequence => Header.Sequence;
        public Proto.Packet.Type Type => Header.PacketType;
        public int CalculateSize => Message!.CalculateSize() + Header.CalculateSize();
        public IMessage? Message;
    }
    public class Packet<T> : PacketBase
        where T : class, IMessage
    {
        public T? ExactMessage => Message as T;
    }
}
