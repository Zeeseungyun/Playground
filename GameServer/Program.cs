using Zee.Message;

namespace Zee
{
    static public class Program
    {
        public static void Start()
        {
            PacketMapping.Start();
            Logger.LogInformation("Framework Started.");
        }
    }
}
