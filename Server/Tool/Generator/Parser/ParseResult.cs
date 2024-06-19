using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using Zee.Common;

namespace Zee
{
    public class MessageProperty
    {
        public MessageProperty(Message msg)
        {
            ParentMessage = msg;
        }
        public Message ParentMessage;
        public string Type = string.Empty;
        public string Name = string.Empty;
        public bool IsArray = false;
        public bool IsEnum = false;
        public bool IsStruct 
        {
            get
            {
                return !IsEnum && !IsStandardType;
            }
        }
        public int OrderOrEnumValue = 0;
        private bool isStandardType = false;
        private bool hasExternalDependency = false;
        private string typeNameWithScope = string.Empty;
        public void Build()
        {
            switch(Type)
            {
                case "string": 
                case "int64": 
                case "int32": 
                case "uint64": 
                case "uint32": 
                case "sint64": 
                case "sint32": 
                case "bool": 
                case "float": 
                case "double": 
                    isStandardType = true;
                    return;

                default:
                    isStandardType = false;
                    break;
            }
            
            foreach(var msg in ParentMessage.ParentProto.Messages)
            {
                if(Type == msg.Name)
                {
                    int FoundIndex = msg.NameWithScope.IndexOf(Type);
                    if(FoundIndex != -1)
                    {
                        typeNameWithScope = msg.NameWithScope;
                        if(typeNameWithScope.Substring(FoundIndex) == Type)
                        {
                            IsEnum = msg.IsEnum;
                            ParentMessage.InternalDependencyMessages.Add(msg);
                            return;
                        }
                    }
                }
            }

            hasExternalDependency = true;
            
            foreach(var dependency in ParentMessage.ParentProto.ProtoFileDependencies)
            {
                foreach(var msg in dependency.Proto!.Messages)
                {
                    int FoundIndex = msg.NameWithScope.IndexOf(Type);
                    if(FoundIndex != -1)
                    {
                        typeNameWithScope = msg.NameWithScope;
                        if(typeNameWithScope.Substring(FoundIndex) == Type)
                        {
                            IsEnum = msg.IsEnum;
                            return;
                        }
                    }
                }
            }
        }

        public bool IsStandardType => isStandardType;
        public bool IsStringType => Type == "string";
        public bool HasDependency => !IsStandardType;
        public bool HasExternalDependency => hasExternalDependency;
        public bool HasInternalDependency => !HasExternalDependency && HasDependency;
        private string unrealProtoTypeName = string.Empty;
        public string TypeToUnrealProto 
        {
            get 
            {
                if(Type == "string")
                {
                    return "std::string";
                }
                
                if(IsStandardType)
                {
                    return Type;
                }

                if(!string.IsNullOrEmpty(unrealProtoTypeName))
                {
                    return unrealProtoTypeName;
                }

                unrealProtoTypeName = string.Join("::",typeNameWithScope.Split('.'));
                return unrealProtoTypeName;
            }
        }
        private string unrealTypeName = string.Empty;
        public string TypeToUnreal
        {
            get 
            {
                if(Type == "string")
                {
                    return "FString";
                }
                
                if(IsStandardType)
                {
                    return Type;
                }

                if(!string.IsNullOrEmpty(unrealTypeName))
                {
                    return unrealTypeName;
                }

                var names = typeNameWithScope.Split('.');
                if(IsEnum)
                {
                    unrealTypeName = "EZeeNet";
                    for(int i = 2; i < names.Length; ++i)
                    {
                        unrealTypeName += names[i];
                    }
                }
                else
                {
                    unrealTypeName = "FZeeNet";
                    for(int i = 2; i < names.Length; ++i)
                    {
                        unrealTypeName += names[i];
                    }
                }
                
                return unrealTypeName;
            }
        }
    }

    public class Message
    {
        public readonly ProtoFile ParentProto;
        public int Point = 0;
        public readonly string Name = string.Empty;
        public string NameWithScope => ParentProto.ScopeString + "." +Name;
        private string unrealName = string.Empty;
        public string UnrealName 
        {
            get 
            {
                if(!string.IsNullOrEmpty(unrealName))
                {
                    return unrealName;
                }

                var names = NameWithScope.Split('.');
                if(IsEnum)
                {
                    unrealName = "EZeeNet";
                    for(int i = 2; i < names.Length; ++i)
                    {
                        unrealName += names[i];
                    }
                }
                else
                {
                    unrealName = "FZeeNet";
                    for(int i = 2; i < names.Length; ++i)
                    {
                        unrealName += names[i];
                    }
                }
                
                return unrealName;
            }
        }
        private string unrealProtoName = string.Empty;
        public string UnrealProtoName 
        {
            get 
            {
                if(!string.IsNullOrEmpty(unrealProtoName))
                {
                    return unrealProtoName;
                }

                unrealProtoName = string.Join("::", NameWithScope.Split('.'));
                return unrealProtoName;
            }
        }
        public readonly List<MessageProperty> Properties = new();
        public readonly bool IsEnum = false;
        public HashSet<Message> InternalDependencyMessages = new();
        public HashSet<Message>? tempInternalDependencyMessages = new();
        public int DependencyOrder = 0;
        public bool HasInternalDependency
        {
            get
            {
                foreach(var prop in Properties)
                {
                    if(prop.HasInternalDependency)
                    {
                        return true;
                    }
                }

                return false;
            }
        }
        public bool HasMessageDependency 
        {
            get
            {
                foreach(var prop in Properties)
                {
                    if(!prop.IsStandardType)
                    {
                        return true;
                    }
                }

                return false;
            }
        }

        public bool HasExternalDependency
        {
            get 
            {
                if(HasMessageDependency)
                {
                    foreach(var prop in Properties)
                    {
                        if(prop.IsStandardType)
                        {
                            continue;
                        }

                        if(prop.HasExternalDependency)
                        {
                            return true;
                        }
                    }
                }

                return false;
            }
        }
        
        private Message(ProtoFile proto, string name, bool isEnum) 
        { 
            ParentProto = proto; 
            Name = name;  
            IsEnum = isEnum;
        }

        static public Message Parse(ProtoFile proto, string name, string[] lines, bool isEnum, ref int index)
        {
            Message ret = new(proto, name, isEnum);
            for(; index < lines.Length; ++index)
            {
                int messageEndIdx = lines[index].IndexOf('}');
                if(messageEndIdx != -1)
                {
                    break;
                }

                var messageProperty = new MessageProperty(ret);
                if(isEnum)
                {
                    string ptnField = @"\s*(\w+)*\s*=\s*(\d)\s*;";
                    var match = Regex.Match(lines[index], ptnField);
                    if(match.Success)
                    {
                        messageProperty.Name = match.Groups[1].Value;
                        messageProperty.OrderOrEnumValue = int.Parse(match.Groups[2].Value);
                        ret.Properties.Add(messageProperty);
                    }
                }
                else
                {
                    string ptnField = @"\s*(\w+\s+)*([\w.]+)\s+(\w+)\s*=\s*(\d)\s*;";
                    var match = Regex.Match(lines[index], ptnField);
                    if(match.Success)
                    {
                        messageProperty.IsArray = match.Groups[1].Value.Length > 0;
                        messageProperty.Type = match.Groups[2].Value;
                        messageProperty.Name = match.Groups[3].Value;
                        messageProperty.OrderOrEnumValue = int.Parse(match.Groups[4].Value);
                        ret.Properties.Add(messageProperty);
                    }
                }
            }
            return ret;
        }
    }
    public class ProtoFileDependency
    {
        public readonly string FileName;
        public ProtoFile? Proto;
        public ProtoFileDependency(string fileName)
        {
            FileName = fileName;
        }
    }
    public class ProtoFile
    {
        public readonly string FileFullPath;
        public readonly string FileName;
        public string FileNameWithoutProto => FileName.Substring(0, FileName.IndexOf('.'));
        public readonly List<string> Scope = new();
        public readonly string ScopeString = string.Empty;
        public readonly List<ProtoFileDependency> ProtoFileDependencies = new();
        public List<Message> Messages = new();
        public List<Message> NonEnumMessages = new();
        private readonly ParseResult parseResult;
        public void BindDependcy()
        {
            foreach(var dependency in ProtoFileDependencies)
            {
                dependency.Proto = parseResult.ProtoFiles.Find((e)=>{
                    return e.FileName == dependency.FileName;
                });
            }
        }
        public void Update(int point)
        {
            foreach(var msg in Messages)
            {
                if(msg.IsEnum)
                {
                    continue;
                }
                msg.Point = ++point;
                foreach(var prop in msg.Properties)
                {
                    prop.Build();
                }
                
                NonEnumMessages.Add(msg);
            }
        }
        static private List<Message> sortMessageByInternalDependency(List<Message> messages)
        {
            var sortedMessages = new List<Message>();
            var pendingMessages = new List<Message>();

            for(int i = 0; i < messages.Count; i++)
            {
                var msg = messages[i];
                if(msg.HasInternalDependency)
                {
                    //remove all already sorted dependecies
                    for(int j = i - 1; j >= 0; j--)
                    {
                        msg.InternalDependencyMessages.Remove(messages[j]);
                    }

                    if(msg.InternalDependencyMessages.Count == 0)
                    {
                        sortedMessages.Add(msg);
                    }
                    else
                    {
                        pendingMessages.Add(msg);
                    }
                }
                else
                {
                    sortedMessages.Add(msg);
                }
            }

            if(pendingMessages.Count > 0)
            {
                sortedMessages.AddRange(pendingMessages);
                return sortMessageByInternalDependency(sortedMessages);
            }

            return sortedMessages;
        }

        public void SortMessageByInternalDependency()
        {
            foreach(var msg in Messages)
            {
                foreach(var elem in msg.InternalDependencyMessages)
                {
                    msg.tempInternalDependencyMessages!.Add(elem);
                }
            }
            
            Messages = sortMessageByInternalDependency(Messages);

            foreach(var msg in Messages)
            {
                msg.InternalDependencyMessages = msg.tempInternalDependencyMessages!;
                msg.tempInternalDependencyMessages = null;
            }
        }
        public ProtoFile(ParseResult parseResult, string filePath)
        {   
            this.parseResult = parseResult;
            FileFullPath = filePath;
            FileName = Path.GetRelativePath(parseResult.RootDir, FileFullPath);

            string[] lines;

            //remove all comments
            {
                string pattern = @"//.*$|/\*[\s\S]*?\*/";
                Regex regex = new Regex(pattern, RegexOptions.Multiline);
                var result = Regex.Replace(File.ReadAllText(filePath), pattern, "\r\n", RegexOptions.Multiline);
                lines = result.Split("\r\n");
            }
            
            string ptnPackage = @"package\s(?:(\w+)[.]*)+;";
            string ptnDendency= @"import\s\""((?:(?:\w+)[.\/]*)+.proto)\"";";
            string ptnMessage = @"message\s+(\w+)\s*";
            string ptnEnum = @"enum\s+(\w+)\s*";

            for(int i = 0; i < lines.Length; ++i)
            {
                var match = Regex.Match(lines[i], ptnPackage);
                if(match.Success)
                {
                    foreach(Capture capture in match.Groups[1].Captures)
                    {
                        Scope.Add(capture.Value);
                    }
                    continue;
                }

                match = Regex.Match(lines[i], ptnDendency);
                if(match.Success)
                {
                    ProtoFileDependencies.Add(new ProtoFileDependency(match.Groups[1].Value));
                    continue;
                }

                match = Regex.Match(lines[i], ptnMessage);
                if(match.Success)
                {
                    var msg = Message.Parse(this, match.Groups[1].Value, lines, /*is enum?*/ false, ref i);
                    Messages.Add(msg);
                    continue;
                }
                
                match = Regex.Match(lines[i], ptnEnum);
                if(match.Success)
                {
                    var msg = Message.Parse(this, match.Groups[1].Value, lines, /*is enum?*/ true, ref i);
                    Messages.Add(msg);
                    continue;
                }
            }

            {
                StringBuilder stringBuilder = new StringBuilder();
                foreach(var elem in Scope)
                {
                    stringBuilder.Append(elem);
                    stringBuilder.Append('.');
                }

                if(stringBuilder.Length > 0)
                {
                    stringBuilder.Remove(stringBuilder.Length - 1, 1);
                    ScopeString = stringBuilder.ToString();
                }
            }
        }
    }
    public class ParseResult
    {
        public List<ProtoFile> ProtoFiles = new();
        public readonly string RootDir = string.Empty;
        public readonly string[] FilePaths;
        public ParseResult(string rootDir, string[] files)
        {
            RootDir = rootDir;
            FilePaths = files;
            Start();
        }
        public void Start()
        {
            foreach(var file in FilePaths)
            {
                ProtoFiles.Add(new ProtoFile(this, file));
            }

            int point = 0x1000;
            foreach(var file in ProtoFiles)
            {
                file.BindDependcy();
                file.Update(point);
                file.SortMessageByInternalDependency();
                point += 0x1000;
            }
        }
    }
}
