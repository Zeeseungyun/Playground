
using System.ComponentModel;
using System.Diagnostics;
using System.Reflection;
using Google.Protobuf;
using Zee.Net.Message;

namespace Zee.SubProcess
{
    abstract public class SubProcessBase
    {
        protected ProcessStartInfo info;
        private Process? process;
        protected SubProcessBase(ProcessStartInfo info)
        {
            this.info = info;
        }
        abstract protected void PreStart();
        public void Kill()
        {
            process?.Kill(true);
        }
        public void Start()
        {
            new Thread(()=>
            {
                PreStart();
                using (process = Process.Start(info))
                {
                    if(process == null)
                    {
                        throw new Exception("if(exeProcess == null)");
                    }
                    process.WaitForExit();
                }
            }).Start();
        }
    }
}
