using Google.Protobuf;
using Zee.Database;
namespace Zee.Net
{
    public partial class ClientHandler
    {
		public void OnRequest(Message.IResponser r, Message.Packet<Zee.Proto.UserCharacter.Create> p) 
        { 
            if(Account.UID == 0)
            {
                Logger.LogWarning("request character create. login first.");
                p.Message = new();
                p.Message.RC = Proto.UserCharacter.ReturnCode.RcFailedUnknown;
                r.Response(p);
            }

            p.Message.Character.User = Account.UID;
            p.Message = this.CreateCharacter(p.Message);
            r.Response(p); 
        }

		public void OnRequest(Message.IResponser r, Message.Packet<Zee.Proto.UserCharacter.Select> p) 
        { 
            Logger.LogInformation("character select. begin");
            p.Message.RC = Proto.UserCharacter.ReturnCode.RcSuccess;
            bool bFound = false;
            var characterGet = this.GetCharacter(Account.UID);
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
                p.Message.RC = Proto.UserCharacter.ReturnCode.RcFailedUnknown;
                r.Response(p);
                Logger.LogInformation($"character select. not found character {p.Message.Character.Slot}");
                return;
            }
            
            p.Message.Position = this.GetPosition(p.Message.Character.UID);
            p.Message.UserIp = RemoteIp;

            ClientHandler? foundDedi = server.FindDedi(p.Message.Position.MapName);
            if( foundDedi == null)
            {
                p.Message.RC = Proto.UserCharacter.ReturnCode.RcFailedUnknown;
                r.Response(p);
                Logger.LogInformation($"character select. not found dedi {p.Message.Character.Slot}");
                return;
            }

            Logger.LogInformation($"request dedi {p.Message}");
            foundDedi.Request(p.Message, (Message.Packet<Zee.Proto.UserCharacter.Select> res)=>
            {
                var newPacket = new Message.Packet<Zee.Proto.UserCharacter.Select>();
                newPacket.Header = p.Header;
                if(res.Message.RC == Proto.UserCharacter.ReturnCode.RcSuccess)
                {
                    newPacket.Message.ToServer = foundDedi.DedicateServer;
                    newPacket.Message.Character = p.Message.Character;
                    Logger.LogInformation($"character select. res success {newPacket.Message} ");
                    r.Response(newPacket);
                }
                else
                {
                    newPacket.Message.RC = res.Message.RC;
                    Logger.LogInformation($"character select. failed. {res.Message.RC}");
                    r.Response(newPacket);
                }
            });
        }
    }
}
