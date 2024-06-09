
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
        }
        protected void PacketMerge(PacketBase packet, Stream stream)
        {
            int readBytes = stream.Read(buffer, 0, sizeof(int));
            packet.Size = BitConverter.ToInt32(buffer);
            readBytes = stream.Read(buffer, 0, sizeof(int));
            packet.Point = BitConverter.ToInt32(buffer);
            packet.Message = PacketMapping.MakeMessage(packet.Point);
            readBytes = stream.Read(buffer, 0, packet.Size - sizeof(int) * 2);
            packet.Message.MergeFrom(buffer, 0, packet.Size - sizeof(int) * 2);
        }
    }
}
