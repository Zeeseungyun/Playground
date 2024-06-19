using Google.Protobuf;

namespace Zee.Net
{
    public partial class ClientHandler
    {
        public void OnNotify(Message.Packet<Proto.Authentication.Login> packet)
        {
            var msg = packet.ExactMessage!;
            Name = msg.Id;
            var rnd = new Random();
            UID = rnd.NextInt64();
            msg.UID = UID;
            msg.RC = Proto.Authentication.ReturnCode.RcSuccesss;
            Notify(msg);
        }

        public void OnNotify(Message.Packet<Proto.Authentication.Logout> packet)
        {

        }

    }
}
