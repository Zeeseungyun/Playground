using System.Net.Sockets;
using System.Text;

namespace Zee.Net
{
    public class Client : ClientBase
    {
        private readonly string ipAddress;
        private readonly int port;
        public Client(string ipAddress, int port)
            : base(new TcpClient())
        {
            this.ipAddress = ipAddress;
            this.port = port;
        }
        protected override void ReceiveMessagesFinished()
        {
            Logger.LogInformation($"[{Name}]: ReceiveMessagesFinished");
            Stop();
        }
        override protected void ReceiveMessages()
        {
            try
            {
                client.Connect(ipAddress, port);
                base.ReceiveMessages();
            }
            catch (Exception ex)
            {
                Logger.LogInformation($"exception occured: [{Name}]: {ex.Message}");
                ReceiveMessagesFinished();
            }
            finally
            {
                
            }
        }
    }
}
