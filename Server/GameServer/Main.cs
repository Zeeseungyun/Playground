using MySqlX.XDevAPI.Common;
using Zee.Net;

Zee.Net.Server server = new(port: 20500);
//server.Start();
var ret = Zee.Database.Account.Login("test_2", "test_1");
Console.WriteLine(ret);
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
 
