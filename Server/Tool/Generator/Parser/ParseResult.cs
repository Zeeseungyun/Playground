using System.Linq;
using System.Text;
using System.Text.RegularExpressions;

namespace Zee
{
    public class MessageProperty
    {
        public string Type = string.Empty;
        public string Name = string.Empty;
        public bool IsArray = false;
        public bool IsEnum = false;
        public int Order = 0;
    }
    public class Message
    {
        public int Point = 0;
        public readonly string Name = string.Empty;
        public readonly List<MessageProperty> Properties = new();
        private Message(string name) { Name = name; }
        static public Message Parse(string name, string[] lines, bool isEnum, ref int index)
        {
            Message ret = new(name);
            string ptnField = @"\s*(\w+\s+)*([\w.]+)\s+(\w+)\s+=\s*(\d)\s*;";
            for(; index < lines.Length; ++index)
            {
                int messageEndIdx = lines[index].IndexOf('}');
                if(messageEndIdx != -1)
                {
                    break;
                }

                var messageProperty = new MessageProperty();
                var match = Regex.Match(lines[index], ptnField);
                if(match.Success)
                {
                    messageProperty.IsArray = match.Groups[1].Value.Length > 0;
                    messageProperty.Type = match.Groups[2].Value;
                    messageProperty.Name = match.Groups[3].Value;
                    messageProperty.Order = int.Parse(match.Groups[4].Value);
                    ret.Properties.Add(messageProperty);
                }
            }
            return ret;
        }
    }
    public class ProtoFileDependency
    {
        public readonly string FileName;
        public ProtoFile? TargetPage;
        public ProtoFileDependency(string fileName)
        {
            FileName = fileName;
        }
    }
    public class ProtoFile
    {
        public readonly string FileFullPath;
        public readonly string FileName;
        public readonly List<string> Scope = new();
        public readonly string ScopeString = string.Empty;
        public readonly List<ProtoFileDependency> ProtoFileDependencies = new();
        public readonly List<Message> Messages = new();
        private readonly ParseResult parseResult;
        public void BindDependcy()
        {
            foreach(var dependency in ProtoFileDependencies)
            {
                dependency.TargetPage = parseResult.ProtoFiles.Find((e)=>{
                    return e.FileName == dependency.FileName;
                });
            }
        }
        public void Update(int point)
        {
            foreach(var msg in Messages)
            {
                msg.Point = ++point;
            }
        }
        public ProtoFile(ParseResult parseResult, string filePath)
        {   
            this.parseResult = parseResult;
            FileFullPath = filePath;
            FileName = Path.GetRelativePath(parseResult.RootDir, FileFullPath);
            var lines = File.ReadAllLines(filePath);
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
                    var msg = Message.Parse(match.Groups[1].Value, lines, /*is enum?*/ false, ref i);
                    Messages.Add(msg);
                    continue;
                }
                
                match = Regex.Match(lines[i], ptnEnum);
                if(match.Success)
                {
                    var msg = Message.Parse(match.Groups[1].Value, lines, /*is enum?*/ true, ref i);
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
                point += 0x1000;
            }
        }
    }
}
