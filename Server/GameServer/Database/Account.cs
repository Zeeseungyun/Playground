using MySql.Data.MySqlClient;

namespace Zee.Database
{
    public static class Account
    {
        public static Zee.Proto.Authentication.ReturnCode newAccount(string id, string pw, int d = 0)
        {
            Common.ConnectIfNot();
            if(d == 5)
            {
                return Zee.Proto.Authentication.ReturnCode.RcFailedLoginCantCreateAccount;
            }
            try
            {
                using (var cmd = new MySqlCommand("INSERT INTO account (uid, id, pw) VALUES (@uid, @id, @pw);", Common.connection))
                {
                    cmd.Parameters.AddWithValue("id", id);
                    cmd.Parameters.AddWithValue("pw", pw);
                    cmd.Parameters.AddWithValue("uid", Common.CreateUID);
                    int numAffected = cmd.ExecuteNonQuery();
                    if(numAffected == 1)
                    {
                        return Zee.Proto.Authentication.ReturnCode.RcSuccesss;
                    }
                }
            }
            catch(MySqlException e)
            {
                Logger.LogWarning(e.Message);
            }
            
            return newAccount(id, pw, d+1);
        }

        public static Zee.Proto.Authentication.ReturnCode Login(string id, string pw)
        {
            Common.ConnectIfNot();
            using (var cmd = new MySqlCommand("SELECT * FROM account WHERE id = @id;", Common.connection))
            {
                cmd.Parameters.AddWithValue("id", id);
                var reader = cmd.ExecuteReader();
                if(reader.Read())
                {
                    var readId = reader["id"].ToString();
                    var readPw = reader["pw"].ToString();
                    if(readPw != pw)
                    {
                        return Zee.Proto.Authentication.ReturnCode.RcFailedLoginWrongPassword;
                    }

                    return Zee.Proto.Authentication.ReturnCode.RcSuccesss;
                }
            }

            return newAccount(id, pw);
        }
    }
}
