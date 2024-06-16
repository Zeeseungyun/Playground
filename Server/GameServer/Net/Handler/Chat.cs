using System.Data.Common;
using Google.Protobuf;

namespace Zee.Net
{
    public partial class ClientHandler
    {
        public void OnNotify(Message.Packet<Proto.Chat.Speak> packet)
        {
            var msg = packet.ExactMessage!;
            msg.RC = Proto.Chat.ReturnCode.RcSuccesss;
            msg.Id = Name;
            msg.UID = UID;
            
            Console.WriteLine($"{Name}: {msg.Content}");
            // server.BroadcastPacket(msg);
        }
    }
}
