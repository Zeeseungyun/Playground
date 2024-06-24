using Google.Protobuf;

namespace Zee.Net
{
    public partial class ClientHandler
    {
        public void OnNotify(Message.Packet<Proto.Authentication.Login> packet)
        {
        }

        public void OnNotify(Message.Packet<Proto.Authentication.Logout> packet)
        {

        }

		public void OnRequest(Message.IResponser r, Message.Packet<Zee.Proto.Authentication.Login> p) 
        { 
            var msg = p.ExactMessage!;
            msg.RC = Zee.Database.Account.Login(msg.Account.Id, msg.Account.Password);
            r.Response(p);
        }
    }
}
