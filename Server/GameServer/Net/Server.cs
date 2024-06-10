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
        public Server(int port)
        {
            this.port = port;
            tcpListener = new(IPAddress.Parse("127.0.0.1"), port);
        }
        override public void Start()
        {
            new Thread(this.start).Start();
        }
        override public void Stop()
        {
            foreach(var client in clients)
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
                client.NotifyMessage(message);
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
            Logger.LogInformation("client disconnected.");
        }
    }
}
