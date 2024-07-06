using System.Net;
using System.Net.Sockets;
using System.Text;
using Google.Protobuf;
using MySql.Data.MySqlClient;
using Zee.Net.Message;

namespace Zee.Net
{
    public partial class ClientHandler 
        : ClientBase
        , Message.INotifyHandler
        , Message.IRequestHandler
    {
        static private readonly string connectionString = "server=zee-database-inst-1.czog0kiey03w.ap-northeast-2.rds.amazonaws.com;database=zee_database_1;uid=admin;password=dnfltkdl12";
        public MySqlConnection? DbConnection;
        private readonly Server server;
        public Zee.Proto.Data.Account Account = new();
        public Zee.Proto.Data.DedicateServer DedicateServer = new();
        public EndPoint RemoteEndPoint => client!.Client.RemoteEndPoint!;
        public string RemoteIp => RemoteEndPoint.ToString()!.Substring(0, RemoteEndPoint.ToString()!.IndexOf(':'));
        public int RemotePort => int.Parse(RemoteEndPoint.ToString()!.Substring(RemoteEndPoint.ToString()!.IndexOf(':')+1));
        override public string Name { 
            get {
                if(Account.Id.Length > 0)
                {
                    return Account.Id;
                }
                
                if(DedicateServer.MapName.Length > 0)
                {
                    return DedicateServer.MapName;
                }

                return "Noname";
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
            DbConnection = new(connectionString);
            DbConnection.Open();
            var stream = client!.GetStream();
            while (client.Connected)
            {
                var packet = stream.DeserializePacket(buffer, buffer.Length);
                if(packet == null)
                {
                    break;
                }
                ProcessPacket(packet);
            }

            DbConnection.Close();
            ReceiveMessagesFinished();
        }

        protected override void ReceiveMessagesFinished()
        {
            Logger.LogInformation($"[{Name}] ReceiveMessagesFinished.");
            Stop();
        }
    }
}
