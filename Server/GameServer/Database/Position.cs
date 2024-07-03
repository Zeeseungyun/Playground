using System.Diagnostics;
using MySql.Data.MySqlClient;

namespace Zee.Database
{
    public static class Position
    {
        public static Zee.Proto.Data.Position Get(Int64 characterUID)
        {
            Common.ConnectIfNot();
            Zee.Proto.Data.Position ret = new();
            ret.UID = characterUID;

            {         
                bool bFound = false;
                //first. select 
                using (var cmd = new MySqlCommand("SELECT * FROM zee_database_1.position WHERE uid = @characterUID;", Common.connection))
                {
                    cmd.Parameters.AddWithValue("characterUID", characterUID);
                    var reader = cmd.ExecuteReader();
                    if(bFound = reader.Read())
                    {
                        ret.MapName = reader.GetString("map_name");
                        ret.Pos = new();
                        ret.Pos.X = reader.GetFloat("pos_x");
                        ret.Pos.Y = reader.GetFloat("pos_y");
                        ret.Pos.Z = reader.GetFloat("pos_z");
                        ret.Rot = new();
                        ret.Rot.Yaw = reader.GetFloat("rot_yaw");
                        ret.Rot.Roll = reader.GetFloat("rot_roll");
                        ret.Rot.Pitch = reader.GetFloat("rot_pitch");
                        return ret;
                    }
                }

                if(!bFound)
                {
                    ret = Common.DefaultPosition.Clone();
                    ret.UID = characterUID;
                    if(!Update(ret))
                    {
                        Logger.LogWarning($"'{characterUID}' can't update but return default position. maybe invalid UID.");
                    }
                }
            }

            return ret;
        }
        public static bool Update(Zee.Proto.Data.Position position)
        {
            Common.ConnectIfNot();
            {
                using var transaction = Common.connection!.BeginTransaction();
                try
                {
                    var cmdText = "INSERT INTO zee_database_1.position (uid, map_name, pos_x, pos_y, pos_z, rot_yaw, rot_pitch, rot_roll) " 
                    + "VALUES(@uid, @map_name, @pos_x, @pos_y, @pos_z, @rot_yaw, @rot_pitch, @rot_roll) "
                    + "ON DUPLICATE KEY UPDATE uid = @uid, map_name = @map_name, pos_x = @pos_x, pos_y = @pos_y, pos_z = @pos_z, rot_yaw = @rot_yaw, rot_pitch = @rot_pitch, rot_roll = @rot_roll;";

                    using (var cmd = new MySqlCommand(cmdText, Common.connection))
                    {
                        cmd.Parameters.AddWithValue("uid", position.UID);
                        cmd.Parameters.AddWithValue("map_name", position.MapName);

                        cmd.Parameters.AddWithValue("pos_x", position.Pos.X);
                        cmd.Parameters.AddWithValue("pos_y", position.Pos.Y);
                        cmd.Parameters.AddWithValue("pos_z", position.Pos.Z);
                        
                        cmd.Parameters.AddWithValue("rot_yaw", position.Rot.Yaw);
                        cmd.Parameters.AddWithValue("rot_roll", position.Rot.Roll);
                        cmd.Parameters.AddWithValue("rot_pitch", position.Rot.Pitch);
                        cmd.ExecuteNonQuery();
                        transaction.Commit();
                    }
                    
                }
                catch (Exception ex)
                {
                    Logger.LogWarning(ex.Message);
                }
            }

            return true;
        }
    }
}
