
using System.Text;

namespace Zee
{
    static public partial class Generator
    {
        static public readonly string DescriptionGenerated = 
@"////////////////////////////////////////////////////////
// This file is generated by Zeenerator.
////////////////////////////////////////////////////////
";
        
        public static string ProtoExeFilePath = string.Empty;
        public static string ProtoMessageDir = string.Empty;
        public static readonly List<string> ProtoSrcFilePaths = new();

        ////////////////////////////////////////////////////////////////
        //// Unreal path
        ////////////////////////////////////////////////////////////////
        public static string UnrealZeeNetDir = string.Empty;
        public static string UnrealProtoMessageDir => Path.GetFullPath(Path.Combine(UnrealZeeNetDir, "Private/Messages/"));
        public static string UnrealMessageConvertDir => Path.GetFullPath(Path.Combine(UnrealZeeNetDir, "Private/Convert/"));
        public static string UnrealMessageSerializerSrcFile => Path.GetFullPath(Path.Combine(UnrealZeeNetDir, "Private/ZeeNetMessageSerializer.g.cpp"));
        public static string UnrealMessageDir => Path.GetFullPath(Path.Combine(UnrealZeeNetDir, "Public/Messages/"));
        public static string UnrealInterfaceDir => Path.GetFullPath(Path.Combine(UnrealZeeNetDir, "Public", "Interface"));
        public static string UnrealInterfaceHandlerDir => Path.GetFullPath(Path.Combine(UnrealInterfaceDir, "Handler"));
        public static string UnrealInterfaceNotifyHandlerDir => Path.GetFullPath(Path.Combine(UnrealInterfaceHandlerDir, "Notify"));
        public static string UnrealInterfaceRequestHandlerDir => Path.GetFullPath(Path.Combine(UnrealInterfaceHandlerDir, "Request"));
        public static string UnrealResponserFile => Path.GetFullPath(Path.Combine(UnrealInterfaceDir, "ZeeNetResponser.h"));
        public static string UnrealNotifyHandlerFile => Path.GetFullPath(Path.Combine(UnrealInterfaceHandlerDir, "ZeeNetNotifyHandler.h"));
        public static string UnrealRequestHandlerFile => Path.GetFullPath(Path.Combine(UnrealInterfaceHandlerDir, "ZeeNetRequestHandler.h"));
        public static string UnrealConsumeNotifyHandlerPrivateDir => Path.GetFullPath(Path.Combine(UnrealZeeNetDir, "Private", "Handler", "Notify"));
        public static string UnrealConsumeNotifyHandlerPublicDir => Path.GetFullPath(Path.Combine(UnrealZeeNetDir, "Public", "Interface", "Handler", "Notify"));
        public static string UnrealConsumeNotifyPrivateFile => Path.GetFullPath(Path.Combine(UnrealZeeNetDir, "Private", "Handler", "Notify.g.cpp"));
        public static string UnrealConsumeRequestHandlerPrivateDir => Path.GetFullPath(Path.Combine(UnrealZeeNetDir, "Private", "Handler", "Request"));
        public static string UnrealConsumeRequestHandlerPublicDir => Path.GetFullPath(Path.Combine(UnrealZeeNetDir, "Public", "Interface", "Handler", "Request"));
        public static string UnrealConsumeRequestPrivateFile => Path.GetFullPath(Path.Combine(UnrealZeeNetDir, "Private", "Handler", "Request.g.cpp"));

        ////////////////////////////////////////////////////////////////
        //// CSharp path
        ////////////////////////////////////////////////////////////////
        public static string CSharpProtoMessageDir = string.Empty;
        public static string CSharpNetDir => Path.GetFullPath(Path.Combine(CSharpProtoMessageDir, "..", "..", "Net")); 
        public static string CSharpNetInterfaceDir => Path.GetFullPath(Path.Combine(CSharpNetDir, "Interface")); 
        static public string CSharpNotifierFile => Path.GetFullPath(Path.Combine(CSharpNetInterfaceDir, "INotifyHandler.g.cs"));
        static public string CSharpRequestHandlerFile => Path.GetFullPath(Path.Combine(CSharpNetInterfaceDir, "IRequestHandler.g.cs"));
        public static string CSharpMessageDir => Path.GetFullPath(Path.Combine(CSharpNetDir, "..", "Message")); 
        static public string CSharpPacketMapFile => Path.GetFullPath(Path.Combine(CSharpMessageDir, "PacketMap.g.cs"));
        static public string[] GetCleanupFiles()
        {
            var files = new List<string>();
            files.AddRange(Directory.GetFiles(UnrealProtoMessageDir, "*.*", SearchOption.AllDirectories));
            files.AddRange(Directory.GetFiles(UnrealMessageConvertDir, "*.*", SearchOption.AllDirectories));
            files.AddRange(Directory.GetFiles(UnrealMessageDir, "*.*", SearchOption.AllDirectories));
            files.Add(UnrealMessageSerializerSrcFile);
            files.AddRange(Directory.GetFiles(UnrealConsumeNotifyHandlerPrivateDir, "*.*", SearchOption.AllDirectories));
            files.AddRange(Directory.GetFiles(UnrealConsumeNotifyHandlerPublicDir, "*.*", SearchOption.AllDirectories));
            files.Add(UnrealConsumeNotifyPrivateFile);
            files.AddRange(Directory.GetFiles(UnrealConsumeRequestHandlerPrivateDir, "*.*", SearchOption.AllDirectories));
            files.AddRange(Directory.GetFiles(UnrealConsumeRequestHandlerPublicDir, "*.*", SearchOption.AllDirectories));
            files.Add(UnrealConsumeRequestPrivateFile);

            files.AddRange(Directory.GetFiles(CSharpProtoMessageDir, "*.*", SearchOption.AllDirectories));
            files.Add(CSharpNotifierFile);
            files.Add(CSharpRequestHandlerFile);
            files.Add(CSharpPacketMapFile);
            return files.ToArray();
        }
    }
}
