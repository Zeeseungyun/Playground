using MySql.Data.MySqlClient;
using Zee.Net;

namespace Zee.Database
{
    public static class Account
    {
        private static Zee.Proto.Data.Account? createAccount(this ClientHandler Handler, string id, string pw)
        {
            Zee.Proto.Data.Account? ret = null;
            using var transaction = Handler.DbConnection!.BeginTransaction();
            try
            {
                using (var cmd = new MySqlCommand("INSERT INTO account (uid, id, pw) VALUES (@uid, @id, @pw);", Handler.DbConnection!))
                {
                    Int64 uid = Common.CreateUID;
                    cmd.Parameters.AddWithValue("id", id);
                    cmd.Parameters.AddWithValue("pw", pw);
                    cmd.Parameters.AddWithValue("uid", uid);
                    if(cmd.ExecuteNonQuery() == 1)
                    {
                        transaction.Commit();
                        ret = new();
                        ret.UID = uid;
                        ret.Id = id;
                        ret.Password = pw;
                        return ret;
                    }

                }
            }
            catch(MySqlException e)
            {
                Logger.LogWarning(e.Message);
            }

            return ret;
        } 

        public static Zee.Proto.Data.Account? CreateAccount(this ClientHandler Handler, string id, string pw)
        {
            Zee.Proto.Data.Account? ret = null;
            //5번만 반복해서 만들어봄.
            for(int i = 0 ; i != 5; ++i)
            {
                ret = Handler.createAccount(id, pw);
                if(ret != null)
                {
                    return ret;
                }
            }

            return ret;//maybe failed.
        }

        public static Zee.Proto.Authentication.Login Login(this ClientHandler Handler, string id, string pw)
        {
            Zee.Proto.Authentication.Login ret = new();
            ret.RC = Proto.Authentication.ReturnCode.RcFailedUnknown;
            Int64 uid = 0;
            {
                using (var cmd = new MySqlCommand("SELECT * FROM account WHERE id = @id;", Handler.DbConnection))
                {
                    cmd.Parameters.AddWithValue("id", id);
                    var reader = cmd.ExecuteReader();
                    if(reader.Read())
                    {
                        var readId = reader.GetString("id");
                        var readPw = reader.GetString("pw");
                        uid = reader.GetInt64("uid");
                        if(readPw == pw)
                        {
                            ret.Account = new();
                            ret.Account.UID = uid;
                            ret.Account.Id = id;
                            ret.Account.Password = pw;
                            ret.RC = Proto.Authentication.ReturnCode.RcSuccess;
                        }
                        else
                        {
                            ret.RC = Proto.Authentication.ReturnCode.RcFailedLoginWrongPassword;
                            return ret;
                        }
                    }
                }
            }

            if(uid != 0)
            {
                var characterGet = Handler.GetCharacter(uid);
                ret.Characters.AddRange(characterGet.Characters);
            }
            else
            {
                var newAccount = Handler.CreateAccount(id, pw);
                if(newAccount != null)
                {
                    ret.RC = Proto.Authentication.ReturnCode.RcSuccess;
                    ret.Account = newAccount;
                }
                else
                {
                    ret.RC = Proto.Authentication.ReturnCode.RcFailedLoginCantCreateAccount;
                }
            }
            
            return ret;
        }
    }
}
