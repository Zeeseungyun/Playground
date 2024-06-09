using System.Net;
using MyPack;
using Zee.Message;

Zee.Framework.Start();

// 
// var p = new Packet();
// p.Message = new Person(){
//     Name = "test"
// };
// MemoryStream ms = new();
// p.WriteTo(ms);
// var p2 = new Packet();
// ms.Seek(0, SeekOrigin.Begin);
// p2.MergeFrom(ms);
// Console.WriteLine("");
// return;

Zee.Net.Client client = new Zee.Net.Client("127.0.0.1", 20500);
client.Start();
client.MessageReceived += (sender, e) =>   
{
    Console.WriteLine(e);
};

client.PacketReceived += (sender, e) =>   
{
    Console.WriteLine(e.Message.ToString());
};

int tick = 0;
while(true)
{
    Thread.Sleep(100);
    //waiting..
    var tmp = Console.ReadLine();
    if(tmp == "quit")
    {
        client.Stop();
        break;
    }
    else
    {   
        tick++;
        if(tick % 2 == 0)
        {
            var person = new Person();
            person.Name = tmp;
            client.SendMessage(person);
        }
        else
        {
            var person = new Person2();
            person.Name = tmp;
            client.SendMessage(person);
        }
    }
}
