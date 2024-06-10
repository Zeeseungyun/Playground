using System.Data.Common;
using Google.Protobuf;
using Zee.Message;

namespace Zee.Net
{
    public partial class ClientHandler
    {
        public void OnMessage(Packet<Proto.Chat.Speak> packet)
        {
            var msg = packet.ExactMessage!;
            msg.RC = Proto.Chat.ReturnCode.RcSuccesss;
            msg.Id = Name;
            msg.UID = UID;
            Console.WriteLine($"{Name}: {msg.Content}");
            server.BroadcastPacket(msg);
        }
    }
}
