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
            if(p.Message.Account.Id.Length == 0)
            {
                p.Message.RC = Proto.Authentication.ReturnCode.RcFailedLoginWrongId;
                r.Response(p);
                return;
            }

            if(p.Message.Account.Password.Length == 0)
            {
                p.Message.RC = Proto.Authentication.ReturnCode.RcFailedLoginWrongPassword;
                r.Response(p);
                return;
            }

            p.Message = Zee.Database.Account.Login(p.Message.Account.Id, p.Message.Account.Password); 
            if(p.Message.RC == Proto.Authentication.ReturnCode.RcSuccess)
            {
                Account = p.Message.Account;
            }

            r.Response(p);
        }
    }
}
