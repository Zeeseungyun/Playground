using System.Net.Sockets;
using Google.Protobuf;
using Zee.Net.Message;

namespace Zee.Net
{
    public abstract class ClientBase 
        : TcpBase
        , Message.IResponser
    {
        protected TcpClient? client;        
        public event EventHandler? OnConnected;
        private HashSet<Message.INotifyHandler> notifyHandlers = new();
        private HashSet<Message.IRequestHandler> requestHandlers = new();
        public bool RegisterNotifyHandler(Message.INotifyHandler handler) => notifyHandlers.Add(handler);
        public bool UnregisterNotifyHandler(Message.INotifyHandler handler)=> notifyHandlers.Remove(handler);
        public bool RegisterRequestHandler(Message.IRequestHandler handler)=> requestHandlers.Add(handler);
        public bool UnregisterNotifyHandler(Message.IRequestHandler handler)=> requestHandlers.Remove(handler);
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
        virtual public void Notify(IMessage msg)
        {
            var packet = new Message.PacketBase();
            packet.InternalMessage = msg;
            packet.Header.PacketType = Proto.Packet.Type.Notify;
            client!.GetStream().SerializePacket(packet);
        }
        protected Dictionary<int, Action<PacketBase>> callbackMaps = new();
        virtual public void Request<T>(T msg, Action<Packet<T>> callback) where T : class, IMessage, new()
        {
            var packet = new Message.PacketBase();
            packet.InternalMessage = msg;
            packet.Header.Sequence = Interlocked.Increment(ref Sequence);
            packet.Header.PacketType = Proto.Packet.Type.Request;

            callbackMaps.Add(packet.Header.Sequence, (PacketBase msg)=>
            {
                callback.Invoke((Packet<T>)msg);
            });

            client!.GetStream().SerializePacket(packet);
        }
        public void Response(PacketBase p)
        {
            if(p.Header.PacketType != Proto.Packet.Type.Request)
            {
                throw new ArgumentException("must be call request packet type.");
            }
            p.Header.PacketType = Proto.Packet.Type.Response;
            client!.GetStream().SerializePacket(p);
        }

        public void ProcessPacket(PacketBase packet)
        {
            switch(packet.Header.PacketType)
            {
                case Proto.Packet.Type.Notify:
                    foreach(var elem in notifyHandlers)
                    {
                        INotifyHandler.HandleNotify(elem, packet);
                    }
                break;

                case Proto.Packet.Type.Request:
                    foreach(var elem in requestHandlers)
                    {
                        IRequestHandler.HandleRequest(this, elem, packet);
                    }
                break; 

                case Proto.Packet.Type.ResponseTimeout:
                case Proto.Packet.Type.NoResponse:
                case Proto.Packet.Type.Response:
                    {
                        if(callbackMaps.TryGetValue(packet.Header.Sequence, out var handler))
                        {
                            handler.Invoke(packet);
                        }
                    }
                break;

                case Proto.Packet.Type.None:
                default:
                    {
                        throw new Exception("invalid packet type");
                    }
            }
        }
    }
}
