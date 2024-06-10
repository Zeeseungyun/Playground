using System.Net.Sockets;
using Google.Protobuf;
using Zee.Message;

namespace Zee.Net
{
    public abstract class ClientBase : TcpBase
    {
        protected TcpClient? client;        
        public event EventHandler? OnConnected;
        virtual public void ExecuteConnected()
        {
            OnConnected?.Invoke(this, EventArgs.Empty);
        }
        private int Seq = 0;
        protected ClientBase(TcpClient? client)
        {
            this.client = client;
        }
        override public void Start()
        {
            new Thread(ReceiveMessages).Start();
        }
        public bool IsConnected 
        { 
            get 
            { 
                if(client == null)
                {
                    return false;
                }
                return client!.Connected;
            }
        }
        public override void Stop()
        {
            if(client!.Connected)
            {
                client.Close();
                client = null;
            }
            HandleDisconnected(this, this);
            Logger.LogInformation($"[{Name}] disconnected.");
        }
        virtual protected void ReceiveMessagesFinished()
        {
        }
        virtual protected void ReceiveMessages()
        {
        }
        virtual public void NotifyMessage(IMessage msg)
        {
            var packet = new PacketBase();
            packet.Message = msg;
            PacketWrite(packet, client!.GetStream());
        }
        virtual public void SendMessage(IMessage msg)
        {
            var packet = new PacketBase();
            packet.Message = msg;
            packet.Seq = Seq++;
            PacketWrite(packet, client!.GetStream());
        }
    }
}
