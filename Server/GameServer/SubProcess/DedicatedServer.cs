
using System.ComponentModel;
using System.Diagnostics;
using System.Reflection;
using System.Security.Cryptography;
using System.Text.RegularExpressions;
using Google.Protobuf;
using Zee.Net.Message;

namespace Zee.SubProcess
{
    public class DedicatedServer : SubProcessBase
    {
        private int port;
        public DedicatedServer(int port)
            : base(new ProcessStartInfo())
        {
            this.port = port;
        }
        protected override void PreStart()
        {  
            info.FileName = "sh";
            info.Arguments = $"/home/{Environment.UserName}/DediServer/ProjectPlaygroundServer.sh -nolog -port={port}";
        }
    }
}
