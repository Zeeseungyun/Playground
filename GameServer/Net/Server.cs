using System;
using System.Collections.Generic;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using Google.Protobuf;
using Zee.Message;
namespace Zee.Net
{
    public class Server : TcpBase
    {
        private readonly TcpListener tcpListener;
        private readonly int port;
        private readonly List<ClientHandler> _clients = new List<ClientHandler>();
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
            foreach(var client in _clients)
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
                    ClientHandler client = new ClientHandler(tcpClient);
                    _clients.Add(client);
                    client.Disconnected += HandleDisconnected;
                    client.Name = "client" + _clients.Count; // todo
                    client.Start();
                }
            }
            catch (Exception ex)
            {

            }

            Stop();
        }

        public void BroadcastMessage(string message)
        {
            foreach (var client in _clients)
            {
                //client.SendMessage(message);
            }
        }
        public void BroadcastPacket(IMessage message)
        {
            foreach (var client in _clients)
            {
                client.SendMessage(message);
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
            _ = _clients.Remove(client);
            Logger.LogInformation("client disconnected.");
        }
    }
}
