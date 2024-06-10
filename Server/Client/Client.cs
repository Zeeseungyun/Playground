
using System.Net.Sockets;

namespace Zee.Net
{
    public sealed partial class Client : ClientBase, Message.IHandler
    {
        private readonly string ipAddress;
        private readonly int port;
        private Int64 id = 0;
        public Client(string ipAddress, int port)
            : base(null)
        {
            this.ipAddress = ipAddress;
            this.port = port;
        }
        protected override void ReceiveMessagesFinished()
        {
            Logger.LogInformation($"[{Name}]: ReceiveMessagesFinished");
            Stop();
            IsLogin = false;
        }
        protected override void ReceiveMessages()
        {
            if(client == null)
            {
                client = new();
            }

            try
            {
                client.Connect(ipAddress, port);
                ExecuteConnected();

                var stream = client.GetStream();
                while (client.Connected)
                {
                    Zee.Message.PacketBase packet = PacketMerge(stream);
                    Message.PacketMapping.HandleMessage(this, packet);
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
    }
}
