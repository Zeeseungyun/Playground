using MySql.Data.MySqlClient;

namespace Zee.Database
{
    public static partial class Common
    {
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
