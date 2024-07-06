using System.Diagnostics;
using MySql.Data.MySqlClient;
using Zee.Net;

namespace Zee.Database
{
    public static class Collection
    {
        public static bool Collect(this ClientHandler Handler, Int64 user, Int32 id)
        {
            {
                using var transaction = Handler.DbConnection!.BeginTransaction();
                try
                {
                    var cmdText = "INSERT INTO zee_database_1.collection (uid, id) VALUES (@user, @id);";

                    using (var cmd = new MySqlCommand(cmdText, Handler.DbConnection))
                    {
                        cmd.Parameters.AddWithValue("user", user);
                        cmd.Parameters.AddWithValue("id", id);
                        if(cmd.ExecuteNonQuery() == 1)
                        {
                            transaction.Commit();
                            return true;
                        }
                    }
                    
                }
                catch (Exception ex)
                {
                    Logger.LogWarning(ex.Message);
                }
            }

            return false;
        }

        public static Int32[] GetCollection(this ClientHandler Handler, Int64 user)
        {
            List<Int32> ids = new();
            {
                try
                {
                    var cmdText = "SELECT id FROM zee_database_1.collection WHERE uid = @user;";
                    using (var cmd = new MySqlCommand(cmdText, Handler.DbConnection))
                    {
                        cmd.Parameters.AddWithValue("user", user);
                        var reader = cmd.ExecuteReader();
                        while(reader.Read())
                        {
                            ids.Add(reader.GetInt32("id"));
                        }
                    }
                }
                catch (Exception ex)
                {
                    Logger.LogWarning("CollectionGet" + ex.Message);
                }
            }

            return ids.ToArray();
        }
    }
}
