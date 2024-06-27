using System.Net.Sockets;
using System.Text;
using Google.Protobuf;
using Zee.Net.Message;

namespace Zee.Net
{
    public partial class ClientHandler 
        : ClientBase
        , Message.INotifyHandler
        , Message.IRequestHandler
    {
        private readonly Server server;
        public Zee.Proto.Data.Account Account = new();
        public Zee.Proto.Data.DedicateServer DedicateServer = new();
        override public string Name { 
            get {
                if(Account.Id.Length > 0)
                {
                    return Account.Id;
                }
                
                if(DedicateServer.IP.Length > 0)
                {
                    return DedicateServer.IP;
                }

                return base.Name;
            } 
        }
        public ClientHandler(TcpClient client, Server server)
            :base(client)
        {
            this.server = server;
            RegisterNotifyHandler(this);
            RegisterRequestHandler(this);
        }

        override protected void ReceiveMessages()
        {
            try
            {
                var stream = client!.GetStream();
                while (client.Connected)
                {
                    ProcessPacket(stream.DeserializePacket(buffer, buffer.Length));
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
