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
        private int Sequence = 0;
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
        private Dictionary<int, Action<IMessage>> callbackMaps = new();
        virtual public void SendMessage<T>(T msg, Action<T> callback) where T : IMessage
        {
            var packet = new PacketBase();
            packet.Message = msg;
            packet.Sequence = Interlocked.Increment(ref Sequence);
            packet.IsRespond = true;
            callbackMaps.Add(packet.Sequence, (IMessage msg)=>
            {
                T va = (T)msg;
                callback.Invoke(va);
            });

            PacketWrite(packet, client!.GetStream());
        }
    }
}
