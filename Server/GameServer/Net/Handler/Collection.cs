using System.Net;
using Google.Protobuf;

namespace Zee.Net
{
    public partial class ClientHandler
    {
		public void OnRequest(Message.IResponser r, Message.Packet<Zee.Proto.Collection.Collect> p) 
        { 
            p.Message.RC = Database.Collection.Collect(Account.UID, p.Message.Id) ? Proto.Collection.ReturnCode.RcSuccess : Proto.Collection.ReturnCode.RcFailedAlreadyCollected;
            r.Response(p);
        }
    }
}
