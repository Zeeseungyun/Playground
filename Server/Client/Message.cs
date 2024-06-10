using Google.Protobuf;
using Zee.Message;

namespace Zee.Net
{
    public sealed partial class Client
    {
        public bool IsLogin = false;
        public void OnMessage(Packet<Proto.Authentication.Login> packet)
        {
            var msg = packet.ExactMessage!;
            Console.WriteLine(msg);
            Name = msg.Id;
            id = msg.UID;
            if(msg.RC == Proto.Authentication.ReturnCode.RcSuccesss)
            {
                IsLogin = true;
            }
        }
        public void OnMessage(Packet<Proto.Chat.Speak> packet)
        {
            var msg = packet.ExactMessage!;
            if(msg.UID != id)
            {
                Console.WriteLine($"{msg.Id}:{msg.Content}");
            }
        }
    }
}
