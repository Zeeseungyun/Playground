using System.Net;
using Google.Protobuf;
using Zee.Database;

namespace Zee.Net
{
    public partial class ClientHandler
    {
        public void OnNotify(Message.Packet<Zee.Proto.Dedicate.Leave> p) 
        { 
            if(!this.UpdatePosition(p.Message.Position))
            {
                Logger.LogWarning($"position update failed.{p.Message.Position}");
            }
        }

		public void OnRequest(Message.IResponser r, Message.Packet<Zee.Proto.Dedicate.Login> p) 
        { 
            p.Message.RC = Proto.Dedicate.ReturnCode.RcSuccess;
            Console.WriteLine(p.Message.DedicateServer.Port);
            
            switch(p.Message.DedicateServer.Port)
            {
                case 20499:
                    DedicateServer.MapName = "/Game/InGame/Maps/MapFirst";
                break;

                case 20498:
                    DedicateServer.MapName = "/Game/InGame/Maps/MapSecond";
                break;

                default:
                    p.Message.RC = Proto.Dedicate.ReturnCode.RcFailedUnknown;
                break;
            }

            DedicateServer.Port = p.Message.DedicateServer.Port;
            DedicateServer.Ip = RemoteIp;

            Logger.LogInformation($"dedicated server login {DedicateServer}");
            p.Message.DedicateServer = DedicateServer;
            r.Response(p);
        }
        
		public void OnRequest(Message.IResponser r, Message.Packet<Zee.Proto.Dedicate.Move> p) 
        { 
            p.Message.RC = Proto.Dedicate.ReturnCode.RcSuccess;
            bool bFound = false;
            var characterGet = this.GetCharacter(Account.UID);
            foreach(var character in characterGet.Characters)
            {
                if(character.UID == p.Message.Character.UID)
                {
                    p.Message.Character = character;
                    bFound = true;
                    break;
                }
            }

            //캐릭터 정보를 찾을 수 없음.
            if(!bFound)
            {
                p.Message.RC = Proto.Dedicate.ReturnCode.RcFailedUnknown;
                r.Response(p);
                return;
            }
            
            p.Message.UserIp = RemoteIp;

            ClientHandler? foundDedi = server.FindDedi(p.Message.ToServer.MapName);
            if( foundDedi == null)
            {
                p.Message.RC = Proto.Dedicate.ReturnCode.RcFailedDediNotFound;
                r.Response(p);
                return;
            }

            foundDedi.Request(p.Message, (Message.Packet<Zee.Proto.Dedicate.Move> res)=>
            {
                var newPacket = new Message.Packet<Zee.Proto.Dedicate.Move>();
                newPacket.Header = p.Header;
                if(res.Message.RC == Proto.Dedicate.ReturnCode.RcSuccess)
                {
                    newPacket.Message.ToServer = foundDedi.DedicateServer;
                    newPacket.Message.Character = p.Message.Character;
                    r.Response(newPacket);
                }
                else
                {
                    newPacket.Message.RC = res.Message.RC;
                    r.Response(newPacket);
                }
            });
        }
    }
}
