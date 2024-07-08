using System.Net;
using System.Net.Sockets;
using Google.Protobuf;
namespace Zee.Net
{
    public class Server : TcpBase
    {
        private readonly TcpListener tcpListener;
        private readonly int port;
        private readonly List<ClientHandler> clients = new List<ClientHandler>();
        public event EventHandler? OnListen;
        public Server(int port)
        {
            this.port = port;
            string ip = "0.0.0.0";
            #if DEBUG
                ip= "127.0.0.1";
            #endif
            Logger.LogInformation($"start listen[{ip}:{port}]");
            tcpListener = new(IPAddress.Parse(ip), port);
        }
        public ClientHandler? FindDedi(string mapName)
        {
            foreach(var client in clients)
            {
                if(client.DedicateServer.MapName == mapName)
                {
                    return client;
                }
            }

            return null;
        }
        override public void Start()
        {
            new Thread(this.start).Start();
        }
        override public void Stop()
        {
            var tempClient = clients.ToArray();
            foreach(var client in tempClient)
            {
                client.Stop();
            }
            tcpListener.Stop();
        }
        private void start()
        {
            try
            {
                tcpListener.Start();
                OnListen?.Invoke(this, EventArgs.Empty);
                while (true)
                {
                    var tcpClient = tcpListener.AcceptTcpClient();
                    ClientHandler client = new ClientHandler(tcpClient, this);
                    clients.Add(client);
                    client.ExecuteConnected();
                    client.Disconnected += HandleDisconnected;
                    client.Start();
                }
            }
            catch (Exception ex)
            {
                Logger.LogWarning($"except occured: {ex.Message}");
            }

            Stop();
        }
        public void BroadcastPacket(IMessage message)
        {
            foreach (var client in clients)
            {
                client.Notify(message);
            }
        }
        override protected void HandleDisconnected(object? sender, TcpBase obj)
        {
            base.HandleDisconnected(sender, obj);
            var client = obj as ClientHandler;
            if(client == null)
            {
                throw new Exception("obj is " + obj.GetType().Name);
            }

            client.Disconnected -= HandleDisconnected;
            _ = clients.Remove(client);
        }
    }
}
