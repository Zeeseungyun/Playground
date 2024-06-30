using System.Net;
using Google.Protobuf;

namespace Zee.Net
{
    public partial class ClientHandler
    {
        public void OnNotify(Message.Packet<Zee.Proto.Dedicate.Leave> p) 
        { 
            if(!Database.Position.Update(p.Message.Position))
            {
                Logger.LogWarning($"position update failed.{p.Message.Position}");
            }
        }

		public void OnRequest(Message.IResponser r, Message.Packet<Zee.Proto.Dedicate.Login> p) 
        { 
            p.Message.RC = Proto.Dedicate.ReturnCode.RcSuccess;
            DedicateServer.MapName = "/Game/InGame/Maps/TopDownMap";
            DedicateServer.Port = 20499;
            DedicateServer.Ip = RemoteIp;
            Logger.LogInformation($"dedicated server login {DedicateServer}");
            p.Message.DedicateServer = DedicateServer;
            r.Response(p);
        }
        
		public void OnRequest(Message.IResponser r, Message.Packet<Zee.Proto.Dedicate.Move> p) 
        { 
            p.Message.RC = Proto.Dedicate.ReturnCode.RcSuccess;
            bool bFound = false;
            var characterGet = Database.Character.Get(Account.UID);
            foreach(var character in characterGet.Characters)
            {
                if(character.Slot == p.Message.Character.Slot)
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
            
            p.Message.Position = Database.Position.Get(p.Message.Character.UID);
            p.Message.UserIp = RemoteIp;

            ClientHandler? foundDedi = server.FindDedi(p.Message.Position.MapName);
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
                    //로케이션 조회한 뒤 로케이션 보내줘야함.
                    newPacket.Message.ToServer = foundDedi.DedicateServer;
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
