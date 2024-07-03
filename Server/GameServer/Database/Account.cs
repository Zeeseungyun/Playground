using MySql.Data.MySqlClient;

namespace Zee.Database
{
    public static class Account
    {
        private static Zee.Proto.Data.Account? createAccount(string id, string pw)
        {
            Common.ConnectIfNot();
            Zee.Proto.Data.Account? ret = null;
            if(Common.connection == null)
            {
                return ret;
            }

            using var transaction = Common.connection.BeginTransaction();
            try
            {
                using (var cmd = new MySqlCommand("INSERT INTO account (uid, id, pw) VALUES (@uid, @id, @pw);", Common.connection!))
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

        public static Zee.Proto.Data.Account? CreateAccount(string id, string pw)
        {
            Zee.Proto.Data.Account? ret = null;
            //5번만 반복해서 만들어봄.
            for(int i = 0 ; i != 5; ++i)
            {
                ret = createAccount(id, pw);
                if(ret != null)
                {
                    return ret;
                }
            }

            return ret;//maybe failed.
        }

        public static Zee.Proto.Authentication.Login Login(string id, string pw)
        {
            Common.ConnectIfNot();
            Zee.Proto.Authentication.Login ret = new();
            ret.RC = Proto.Authentication.ReturnCode.RcFailedUnknown;
            Int64 uid = 0;
            {
                using (var cmd = new MySqlCommand("SELECT * FROM account WHERE id = @id;", Common.connection))
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
                var characterGet = Character.Get(uid);
                ret.Characters.AddRange(characterGet.Characters);
            }
            else
            {
                var newAccount = CreateAccount(id, pw);
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
