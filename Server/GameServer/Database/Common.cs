using MySql.Data.MySqlClient;

namespace Zee.Database
{
    public static partial class Common
    {
        public static Zee.Proto.Data.Position DefaultPosition => defaultPosition;
        private static Zee.Proto.Data.Position defaultPosition = new(){
            MapName = "/Game/InGame/Maps/TopDownMap",
            Pos = new() {X = 1000.0f, Y = 1810.0f, Z = 92.1f},
            Rot = new()
        };
        private static Random random = new Random();
        public static Int64 CreateUID => random.NextInt64();
        public static MySqlConnection? connection;
        static private readonly string connectionString = "server=zee-database-inst-1.czog0kiey03w.ap-northeast-2.rds.amazonaws.com;database=zee_database_1;uid=admin;password=dnfltkdl12";
        public static void ConnectIfNot()
        {
            if( connection == null )
            {
                connection = new(connectionString);
                connection.Open();
            }
        }
    }
}
