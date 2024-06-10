using System.Net;
using Zee.Message;

Zee.Net.Client client = new Zee.Net.Client("127.0.0.1", 20500);
string tmp = string.Empty;
while(true)
{
    Thread.Sleep(100);
    //waiting..
    if(client.IsLogin == false)
    {
        if(client.IsConnected == false)
        {
            client.OnConnected += (s,e) =>
            {
                Console.WriteLine("Enter your name: ");
                var tt = Console.ReadLine();
                if(client.IsConnected)
                {
                    Zee.Proto.Authentication.Login msg = new();
                    msg.Id = tt;
                    client.SendMessage(msg);
                }
            };
            
            var tt = Console.ReadLine();
            client.Start();
        }
    }
    else
    {
        var tt = Console.ReadLine();
        Zee.Proto.Chat.Speak msg = new();
        msg.Content = tt;
        client.NotifyMessage(msg);
    }
}
