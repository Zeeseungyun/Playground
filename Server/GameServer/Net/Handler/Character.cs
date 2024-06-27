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

            p.Message.Character.UID = Account.UID;
            p.Message = Database.Character.Create(p.Message);
            r.Response(p); 
        }

        public void OnRequest(Message.IResponser r, Message.Packet<Zee.Proto.UserCharacter.Select> p)
        {
            //need to server travel
            r.Response(p);
        }
    }
}
