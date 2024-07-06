using Google.Protobuf;
using Zee.Database;

namespace Zee.Net
{
    public partial class ClientHandler
    {
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

            p.Message = this.Login(p.Message.Account.Id, p.Message.Account.Password);
            if(p.Message.RC == Proto.Authentication.ReturnCode.RcSuccess)
            {
                p.Message.CollectionIds.AddRange(this.GetCollection(p.Message.Account.UID));
                Account = p.Message.Account;
                Logger.LogInformation($"[{Account.Id} logged in.]");
            }

            r.Response(p);
        }
    }
}
