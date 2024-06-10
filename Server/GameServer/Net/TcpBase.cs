
using System.Reflection;
using Google.Protobuf;
using Zee.Message;

namespace Zee.Net
{
    public abstract class TcpBase
    {
        public event EventHandler<TcpBase>? Disconnected;
        public string Name = "Noname";
        public TcpBase()
        {
            PacketMapping.Start();
        }
        virtual protected void HandleDisconnected(object? sender, TcpBase obj)
        {
            Disconnected?.Invoke(sender, obj);
        }
        virtual public void Start()
        {

        }
        virtual public void Stop()
        {

        }
        private readonly byte[] buffer = new byte[1024];
        protected void PacketWrite(PacketBase packet, Stream stream)
        {
            stream.Write(BitConverter.GetBytes(packet.CalculateSize));
            packet.Point = PacketMapping.GetPacketPoint(packet.Message!.GetType());
            stream.Write(BitConverter.GetBytes(packet.Point));
            packet.Message.WriteTo(stream);
            stream.Flush();
        }
        protected PacketBase PacketMerge(Stream stream)
        {
            int readBytes = stream.Read(buffer, 0, sizeof(int));
            int Size = BitConverter.ToInt32(buffer);
            readBytes = stream.Read(buffer, 0, sizeof(int));
            int Point = BitConverter.ToInt32(buffer);
            PacketBase ret = PacketMapping.MakePacket(Point)!;
            ret.Size = Size;
            ret.Point = Point;
            readBytes = stream.Read(buffer, 0, Size - sizeof(int) * 2);
            ret.Message!.MergeFrom(buffer, 0, Size - sizeof(int) * 2);
            return ret!;
        }
    }
}
