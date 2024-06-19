using System.Data.Common;
using System.Net.Cache;
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
        }
        public void OnRequest(Message.IResponser r, Message.Packet<Zee.Proto.Chat.Speak> p) 
        { 
            var msg = p.ExactMessage!;
            Console.WriteLine($"{Name}: {msg.Content}");
            msg.Content = "good job.";
            r.Response(p);
            Request(p.ExactMessage!, (e)=>
            {
                Console.WriteLine($"{Name}: OnResponse{e.Header}");
                msg.Content = "test finished.";
                Notify(msg);
            });
        }
    }
}
