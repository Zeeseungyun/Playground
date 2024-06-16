
using System.ComponentModel;
using System.Reflection;
using Google.Protobuf;
using Zee.Net.Message;

namespace Zee.Net
{
    public abstract class TcpBase
    {
        public event EventHandler<TcpBase>? Disconnected;
        public string Name = "Noname";
        public TcpBase()
        {
            Message.PacketMap.Start();
        }
        virtual protected void HandleDisconnected(object? sender, TcpBase obj)
        {
            Disconnected?.Invoke(sender, obj);
        }
        virtual public void Start()
        {

        }
        virtual public void Stop()
        {

        }
        protected readonly byte[] buffer = new byte[1024];
    }
}
