using System.Diagnostics;
using MySqlX.XDevAPI.Common;
using Zee.Common;
using Zee.Net;

CommandLineArg.ParseCommandLineArgs(args);
Console.WriteLine("game server started.");
Zee.Net.Server server = new(port: 20500);
List<Zee.SubProcess.DedicatedServer> subProcessList = new();
#if !DEBUG
    server.OnListen += (e, arg)=>
    {
        subProcessList.Add(new Zee.SubProcess.DedicatedServer(20499));
        subProcessList.Add(new Zee.SubProcess.DedicatedServer(20498));
        foreach(var elem in subProcessList)
        {
            elem.Start();
        }
    };
#endif

server.Start();
while(true)
{
    var tmp = Console.ReadLine();
    switch(tmp)
    {
        case "quit":
        server.Stop();
        foreach(var elem in subProcessList)
        {
            elem.Kill();
        }
        Console.WriteLine("program exit.");
        return;

        default:
        break;
    }
}
 
