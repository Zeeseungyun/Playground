
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
            stream.Write(BitConverter.GetBytes(packet.Sequence));
            stream.Write(BitConverter.GetBytes(packet.IsRespond));
            packet.Message.WriteTo(stream);
            stream.Flush();
        }
        protected PacketBase PacketMerge(Stream stream)
        {
            int readBytes = stream.Read(buffer, 0, sizeof(int));
            int size = BitConverter.ToInt32(buffer);
            readBytes = stream.Read(buffer, 0, sizeof(int));
            int point = BitConverter.ToInt32(buffer);
            readBytes = stream.Read(buffer, 0, sizeof(int));
            int sequence = BitConverter.ToInt32(buffer);
            readBytes = stream.Read(buffer, 0, 1 /*sizeof(bool)*/);
            bool isRespond = BitConverter.ToBoolean(buffer);
            PacketBase ret = PacketMapping.MakePacket(point)!;
            ret.Size = size;
            ret.Point = point;
            ret.Sequence = sequence;
            ret.IsRespond = isRespond;
            readBytes = stream.Read(buffer, 0, size - sizeof(int) * 2);
            ret.Message!.MergeFrom(buffer, 0, size - sizeof(int) * 2);
            return ret!;
        }
    }
}
