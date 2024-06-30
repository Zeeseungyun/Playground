using Google.Protobuf;

namespace Zee.Net
{
    public partial class ClientHandler
    {
		public void OnRequest(Message.IResponser r, Message.Packet<Zee.Proto.UserCharacter.Create> p) 
        { 
            if(Account.UID == 0)
            {
                Logger.LogWarning("request character create. login first.");
                p.Message = new();
                p.Message.RC = Proto.UserCharacter.ReturnCode.RcFailedUnknown;
                r.Response(p);
            }

            p.Message.Character.User = Account.UID;
            p.Message = Database.Character.Create(p.Message);
            r.Response(p); 
        }

    }
}
