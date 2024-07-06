using MySql.Data.MySqlClient;

namespace Zee.Database
{
    public static partial class Common
    {
        public static Zee.Proto.Data.Position DefaultPosition => defaultPosition;
        private static Zee.Proto.Data.Position defaultPosition = new(){
            MapName = "/Game/InGame/Maps/MapFirst",
            Pos = new() {X = 1000.0f, Y = 1810.0f, Z = 92.1f},
            Rot = new()
        };
        private static Random random = new Random();
        public static Int64 CreateUID => random.NextInt64();
    }
}
