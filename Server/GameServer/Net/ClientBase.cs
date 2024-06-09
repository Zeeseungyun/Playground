using System.Net.Sockets;
using Google.Protobuf;
using Zee.Message;

namespace Zee.Net
{
    public abstract class ClientBase : TcpBase
    {
        protected readonly TcpClient client;
        protected ClientBase(TcpClient client)
        {
            this.client = client;
        }
        override public void Start()
        {
            new Thread(ReceiveMessages).Start();
        }
        public override void Stop()
        {
            if(client.Connected)
            {
                client.Close();
            }
            HandleDisconnected(this, this);
            Logger.LogInformation($"[{Name}] disconnected.");
        }
        virtual protected void ReceiveMessagesFinished()
        {
        }
        virtual protected void ReceiveMessages()
        {
            try
            {
                var stream = client.GetStream();
                while (client.Connected)
                {
                    PacketBase packet = new();
                    PacketMerge(packet, stream);
                    // TODO:: Client 클래스 동작안함.
                    // HandleMessageReceived(this, packet.Message!);
                }
            }
            catch (Exception ex)
            {
                Logger.LogInformation($"exception occured: [{Name}] {ex.Message}.");
            }
            finally
            {
                ReceiveMessagesFinished();
            }
        }
        virtual public void SendMessage(IMessage message)
        {
            var packet = new PacketBase();
            packet.Message = message;
            var stream = client.GetStream();
            PacketWrite(packet, stream);
            stream.Flush();
        }
    }
}
