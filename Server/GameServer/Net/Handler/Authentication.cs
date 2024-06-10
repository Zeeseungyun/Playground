using Google.Protobuf;
using Zee.Message;

namespace Zee.Net
{
    public partial class ClientHandler
    {
        public void OnMessage(Packet<Proto.Authentication.Login> packet)
        {
            var msg = packet.ExactMessage!;
            Name = msg.Id;
            var rnd = new Random();
            UID = rnd.NextInt64();
            msg.UID = UID;
            msg.RC = Proto.Authentication.ReturnCode.RcSuccesss;
            NotifyMessage(msg);
        }

        public void OnMessage(Packet<Proto.Authentication.Logout> packet)
        {

        }
    }
}
