using System.Net.Sockets;
using System.Text;
using Google.Protobuf;
using Zee.Message;

namespace Zee.Net
{
    public partial class ClientHandler : ClientBase, IHandler
    {
        private readonly Server server;
        public Int64 UID = 0;
        public ClientHandler(TcpClient client, Server server)
            :base(client)
        {
            this.server = server;
        }
        override protected void ReceiveMessages()
        {
            try
            {
                var stream = client!.GetStream();
                while (client.Connected)
                {
                    PacketBase packet = PacketMerge(stream);
                    PacketMapping.HandleMessage(this, packet);
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

        protected override void ReceiveMessagesFinished()
        {
            Logger.LogInformation($"[{Name}] ReceiveMessagesFinished.");
            Stop();
        }
    }
}
