using System.Net;
using Google.Protobuf;
using Zee.Database;
namespace Zee.Net
{
    public partial class ClientHandler
    {
		public void OnRequest(Message.IResponser r, Message.Packet<Zee.Proto.Collection.Collect> p) 
        { 
            p.Message.RC = this.Collect(Account.UID, p.Message.Id) ? Proto.Collection.ReturnCode.RcSuccess : Proto.Collection.ReturnCode.RcFailedAlreadyCollected;
            r.Response(p);
        }
    }
}
