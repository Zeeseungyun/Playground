namespace Zee.Common
{
    public class CommandLineArg
    {
        static private readonly Dictionary<string, string> parsedArgs = new();// = ParseCommandLineArgs(args);
        static public void ParseCommandLineArgs(string[] args)
        {
            parsedArgs.Clear();
            for (int i = 0; i < args.Length; i++)
            {
                if (args[i].StartsWith("-") && i + 1 < args.Length)
                {
                    string key = args[i];
                    string value = args[i + 1];
                    parsedArgs[key] = value;
                    i++; // Skip the next argument (the value)
                }
            }

            Console.WriteLine("Parsing result.");
            foreach (var kvp in parsedArgs)
            {
                Console.WriteLine($"Key: {kvp.Key}, Value: {kvp.Value}");
            }
        }
        private string[] keys;
        public CommandLineArg(string[] keys)
        {
            this.keys = keys;
        }
        public bool IsEmpty => !parsedArgs.Keys.Any((k)=>keys.Contains(k));
        public bool TryGetValue(out string value)
        {
            value = string.Empty;
            foreach(var key in keys)
            {
                if (parsedArgs.TryGetValue(key, out value))
                {
                    return true;
                }
            }

            return false;
        }

        public string Value 
        { 
            get 
            {
                string? ret = null;
                if(TryGetValue(out var value))
                {
                   ret = value; 
                }

                if(ret == null)
                {
                    string msg = "not found: " + string.Concat(keys);
                    throw new Exception(msg);
                }

                return ret!;
            }
        }
    }
}
