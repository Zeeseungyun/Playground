using System.Diagnostics;
using MySql.Data.MySqlClient;
using Zee.Net;

namespace Zee.Database
{
    public static class Character
    {
        public static Zee.Proto.UserCharacter.Get GetCharacter(this ClientHandler Handler,Int64 userId)
        {
            Zee.Proto.UserCharacter.Get ret = new();
            ret.User = userId;
            
            using (var cmd = new MySqlCommand("SELECT * FROM zee_database_1.character WHERE user = @user;", Handler.DbConnection))
            {
                cmd.Parameters.AddWithValue("user", userId);
                var reader = cmd.ExecuteReader();
                while(reader.Read())
                {
                    var character = new Zee.Proto.Data.Character();
                    character.User = userId;
                    character.UID = (Int64)reader["uid"];
                    character.Name = reader["name"].ToString();
                    character.Id = (Int32)reader["id"];
                    character.Slot = (Int32)reader["slot"];
                    ret.Characters.Add(character);
                }
            }

            return ret;
        }
        public static Zee.Proto.UserCharacter.Create CreateCharacter(this ClientHandler Handler, Zee.Proto.UserCharacter.Create req)
        {
            Zee.Proto.UserCharacter.Create ret = new();
            using var transaction = Handler.DbConnection!.BeginTransaction();
            try
            {
                using (var cmd = new MySqlCommand("INSERT INTO zee_database_1.character (uid, user, id, name, slot) VALUES (@uid, @user, @id, @name, @slot);", Handler.DbConnection!))
                {
                    Int64 uid = Common.CreateUID;
                    cmd.Parameters.AddWithValue("user", req.Character.User);
                    cmd.Parameters.AddWithValue("uid", uid);
                    cmd.Parameters.AddWithValue("id", req.Character.Id);
                    cmd.Parameters.AddWithValue("name", req.Character.Name);
                    cmd.Parameters.AddWithValue("slot", req.Character.Slot);
                    if(cmd.ExecuteNonQuery() == 1)
                    {
                        transaction.Commit();
                        ret.Character = req.Character.Clone();
                        ret.Character.UID = uid;
                        ret.RC = Proto.UserCharacter.ReturnCode.RcSuccess;
                        return ret;
                    }
                }
            }
            catch (MySqlException e)
            {
                Logger.LogWarning(e.Message);
                ret.RC = Proto.UserCharacter.ReturnCode.RcFailedUnknown;
                if(e.Message.IndexOf("Duplicate") != -1)
                {
                    if(e.Message.IndexOf("name") != -1)
                    {
                        ret.RC = Proto.UserCharacter.ReturnCode.RcFailedCreateDuplicatedName;
                    }
                }
            }

            return ret;
        }
    }
}
