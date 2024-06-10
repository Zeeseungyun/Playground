using Zee.Message;
using Zee.Net;

Zee.Net.Server server = new(port: 20500);
server.Start();

while(true)
{
    var tmp = Console.ReadLine();
    switch(tmp)
    {
        case "quit":
        Console.WriteLine("program exit.");
        return;

        default:

        break;
    }
}
 
