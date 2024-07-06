using System;
using System.IO;
using System.Text;
using System.Security.AccessControl;
using Renci.SshNet;
using Zee.Common;

// 원격 디렉토리가 존재하는지 확인하는 메서드
static bool DirectoryExists(SshClient client, string directoryPath)
{
    var command = client.RunCommand($"[ -d '{directoryPath}' ] && echo 'Exists'");
    return command.Result.Trim() == "Exists";
}

// 원격 디렉토리를 생성하는 메서드
static void CreateDirectory(SshClient client, string directoryPath)
{
    client.RunCommand($"mkdir -p '{directoryPath}'");
}

// 원격 디렉토리를 제거하는 메서드
static void RemoveDirectory(SshClient client, string directoryPath)
{
    client.RunCommand($"rm -rf '{directoryPath}'");
}

CommandLineArg.ParseCommandLineArgs(args);
CommandLineArg hostArg      = new (new []{"-host", "-h"});
CommandLineArg processArg   = new (new []{"-process"});
CommandLineArg usernameArg  = new (new []{"-username", "-user", "-u"});
CommandLineArg pemArg       = new (new []{"-pem", "-p"});
CommandLineArg srcDirArg    = new (new []{"-srcdir", "-srcd"});
CommandLineArg destDirArg   = new (new []{"-destdir", "-destd"});
CommandLineArg subProcessArg   = new (new []{"-subprocess"});

string host = hostArg.Value;
string username = usernameArg.Value;
string pemFilePath = pemArg.Value;
string process = processArg.Value;

var privateKeyFileArray = new[] { new PrivateKeyFile(pemFilePath) };
var connectionInfo = new ConnectionInfo(host, username, new PrivateKeyAuthenticationMethod(username, privateKeyFileArray));

try
{
    switch(process)
    {   
        case "start":
            switch(subProcessArg.Value)
            {
                case "gameserver":
                    using (var client = new SshClient(connectionInfo))
                    {
                        client.Connect();
                        //client.RunCommand($"mkdir -p '{directoryPath}'");
                        client.Disconnect();
                    }
                break;
            }
        break;

        case "ftp":
            string srcDirPath = srcDirArg.Value;
            string destDirPath = destDirArg.Value;
            using (var client = new SshClient(connectionInfo))
            {
                client.Connect();

                if (DirectoryExists(client, destDirPath))
                {
                    RemoveDirectory(client, destDirPath);
                }

                CreateDirectory(client, destDirPath);
                Console.WriteLine($"원격 디렉토리 생성: {destDirPath}");

                // ScpClient 생성
                using (var scpClient = new ScpClient(connectionInfo))
                {
                    scpClient.Connect();
                    // 로컬 디렉토리를 원격 디렉토리로 업로드
                    var srcDirInfo = Directory.CreateDirectory(srcDirPath);
                    scpClient.Upload(srcDirInfo, destDirPath);
                    scpClient.Disconnect();
                }

                client.Disconnect();
            }
        break;

        case "install_sdk":
            using (var client = new SshClient(connectionInfo))
            {
                client.Connect();
                if(client.RunCommand("dotnet --version").Result.Trim() != "8.0.105")
                {
                    client.RunCommand( @"sudo apt-get update && sudo apt-get install -y dotnet-sdk-8.0");
                }
                Console.WriteLine("successful.");
                client.Disconnect();
            }
        break;
    }
}
catch (Exception ex)
{
    Console.WriteLine($"error occured: {ex.Message}");
}
