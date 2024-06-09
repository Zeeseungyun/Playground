using Microsoft.Extensions.Logging;
using Microsoft.Extensions.Logging.Console;

namespace Zee
{
    public sealed class Logger 
    {
        // Customized ILoggerProvider, writes logs to text files
        private class CustomFileLoggerProvider : ILoggerProvider
        {
            private readonly StreamWriter _logFileWriter;

            public CustomFileLoggerProvider(StreamWriter logFileWriter)
            {
                _logFileWriter = logFileWriter ?? throw new ArgumentNullException(nameof(logFileWriter));
            }

            public ILogger CreateLogger(string categoryName)
            {
                return new CustomFileLogger(categoryName, _logFileWriter);
            }

            public void Dispose()
            {
                _logFileWriter.Dispose();
            }
        }

        // Customized ILogger, writes logs to text files
        public class CustomFileLogger : ILogger
        {
            private readonly string _categoryName;
            public readonly StreamWriter LogFileWriter;

            public CustomFileLogger(string categoryName, StreamWriter logFileWriter)
            {
                _categoryName = categoryName;
                LogFileWriter = logFileWriter;
            }

            private class EndScope : IDisposable
            {
                private string? _state;
                public EndScope(CustomFileLogger logger, string? state)
                {
                    Logger = logger;
                    _state = state;
                }
                private CustomFileLogger? Logger;
                public void Dispose()
                {
                    Logger!.LogFileWriter.WriteLine($"{DateTime.Now.ToString("HH:mm:ss ")}[Scope Finished] {_state}");
                }
            }

            public IDisposable? BeginScope<TState>(TState state) where TState : notnull
            {
                LogFileWriter.WriteLine($"{DateTime.Now.ToString("HH:mm:ss ")}[Scope Started] {state.ToString()}");
                return new EndScope(this, state.ToString());
            }

            public bool IsEnabled(LogLevel logLevel)
            {
                // Ensure that only information level and higher logs are recorded
                return logLevel >= LogLevel.Information;
            }

            public void Log<TState>(
                LogLevel logLevel,
                EventId eventId,
                TState state,
                Exception? exception,
                Func<TState, Exception?, string> formatter)
            {
                // Ensure that only information level and higher logs are recorded
                if (!IsEnabled(logLevel))
                {
                    return;
                }

                // Get the formatted log message
                var message = formatter(state, exception);

                //Write log messages to text file

                LogFileWriter.WriteLine($"{DateTime.Now.ToString("HH:mm:ss ")}[{logLevel}] [{_categoryName}] {message}");
                LogFileWriter.Flush();
            }
        }
        private StreamWriter logFileWriter;
        private ILogger logger;
        // private 생성자
        private Logger() 
        { 
            int cnt = 0;
            Directory.CreateDirectory(Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "LogFiles", $"{DateTime.Now.Year}-{DateTime.Now.Month}-{DateTime.Now.Day}"));
            
            while(true)
            {
                try
                {
                    var logfilePath = Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "LogFiles", $"{DateTime.Now.Year}-{DateTime.Now.Month}-{DateTime.Now.Day}", $"Log{cnt}.txt");
                    logFileWriter = new StreamWriter(logfilePath!, append: true);
                }
                catch(IOException ex)
                {

                }

                if(logFileWriter != null)
                {
                    break;
                }
                cnt++;
            }

            //Create an ILoggerFactory
            using (ILoggerFactory loggerFactory = LoggerFactory.Create(builder =>
                {
                    //Add console output
                    builder.AddSimpleConsole(options =>
                    {
                        options.IncludeScopes = true;
                        options.SingleLine = true;
                        options.TimestampFormat = "HH:mm:ss ";
                    });

                    //Add a custom log provider to write logs to text files
                    builder.AddProvider(new CustomFileLoggerProvider(logFileWriter));
                }))
            {
                //Create an ILogger
                logger = loggerFactory.CreateLogger<Logger>();
            }
        }

        // private static 인스턴스 객체
        private static readonly Lazy<Logger> _instance = new Lazy<Logger>(() => new Logger());

        // public static의 객체 반환 함수
        private static Logger Instance => _instance.Value;
        public static ILogger Get => Instance.logger;
        
        //
        // Summary:
        //     Formats and writes a debug log message.
        //
        // Parameters:
        //   logger:
        //     The Microsoft.Extensions.Logging.ILogger to write to.
        //
        //   eventId:
        //     The event id associated with the log.
        //
        //   exception:
        //     The exception to log.
        //
        //   message:
        //     Format string of the log message in message template format. Example: "User {User}
        //     logged in from {Address}"
        //
        //   args:
        //     An object array that contains zero or more objects to format.
        public static void LogDebug(EventId eventId, Exception? exception, string? message, params object?[] args)
        {
            Get.Log(LogLevel.Debug, eventId, exception, message, args);
        }
    
        //
        // Summary:
        //     Formats and writes a debug log message.
        //
        // Parameters:
        //   logger:
        //     The Microsoft.Extensions.Logging.ILogger to write to.
        //
        //   eventId:
        //     The event id associated with the log.
        //
        //   message:
        //     Format string of the log message in message template format. Example: "User {User}
        //     logged in from {Address}"
        //
        //   args:
        //     An object array that contains zero or more objects to format.
        public static void LogDebug(EventId eventId, string? message, params object?[] args)
        {
            Get.Log(LogLevel.Debug, eventId, message, args);
        }
    
        //
        // Summary:
        //     Formats and writes a debug log message.
        //
        // Parameters:
        //   logger:
        //     The Microsoft.Extensions.Logging.ILogger to write to.
        //
        //   exception:
        //     The exception to log.
        //
        //   message:
        //     Format string of the log message in message template format. Example: "User {User}
        //     logged in from {Address}"
        //
        //   args:
        //     An object array that contains zero or more objects to format.
        public static void LogDebug(Exception? exception, string? message, params object?[] args)
        {
            Get.Log(LogLevel.Debug, exception, message, args);
        }
    
        //
        // Summary:
        //     Formats and writes a debug log message.
        //
        // Parameters:
        //   logger:
        //     The Microsoft.Extensions.Logging.ILogger to write to.
        //
        //   message:
        //     Format string of the log message in message template format. Example: "User {User}
        //     logged in from {Address}"
        //
        //   args:
        //     An object array that contains zero or more objects to format.
        public static void LogDebug(string? message, params object?[] args)
        {
            Get.Log(LogLevel.Debug, message, args);
        }
    
        //
        // Summary:
        //     Formats and writes a trace log message.
        //
        // Parameters:
        //   logger:
        //     The Microsoft.Extensions.Logging.ILogger to write to.
        //
        //   eventId:
        //     The event id associated with the log.
        //
        //   exception:
        //     The exception to log.
        //
        //   message:
        //     Format string of the log message in message template format. Example: "User {User}
        //     logged in from {Address}"
        //
        //   args:
        //     An object array that contains zero or more objects to format.
        public static void LogTrace(EventId eventId, Exception? exception, string? message, params object?[] args)
        {
            Get.Log(LogLevel.Trace, eventId, exception, message, args);
        }
    
        //
        // Summary:
        //     Formats and writes a trace log message.
        //
        // Parameters:
        //   logger:
        //     The Microsoft.Extensions.Logging.ILogger to write to.
        //
        //   eventId:
        //     The event id associated with the log.
        //
        //   message:
        //     Format string of the log message in message template format. Example: "User {User}
        //     logged in from {Address}"
        //
        //   args:
        //     An object array that contains zero or more objects to format.
        public static void LogTrace(EventId eventId, string? message, params object?[] args)
        {
            Get.Log(LogLevel.Trace, eventId, message, args);
        }
    
        //
        // Summary:
        //     Formats and writes a trace log message.
        //
        // Parameters:
        //   logger:
        //     The Microsoft.Extensions.Logging.ILogger to write to.
        //
        //   exception:
        //     The exception to log.
        //
        //   message:
        //     Format string of the log message in message template format. Example: "User {User}
        //     logged in from {Address}"
        //
        //   args:
        //     An object array that contains zero or more objects to format.
        public static void LogTrace(Exception? exception, string? message, params object?[] args)
        {
            Get.Log(LogLevel.Trace, exception, message, args);
        }
    
        //
        // Summary:
        //     Formats and writes a trace log message.
        //
        // Parameters:
        //   logger:
        //     The Microsoft.Extensions.Logging.ILogger to write to.
        //
        //   message:
        //     Format string of the log message in message template format. Example: "User {User}
        //     logged in from {Address}"
        //
        //   args:
        //     An object array that contains zero or more objects to format.
        public static void LogTrace(string? message, params object?[] args)
        {
            Get.Log(LogLevel.Trace, message, args);
        }
    
        //
        // Summary:
        //     Formats and writes an informational log message.
        //
        // Parameters:
        //   logger:
        //     The Microsoft.Extensions.Logging.ILogger to write to.
        //
        //   eventId:
        //     The event id associated with the log.
        //
        //   exception:
        //     The exception to log.
        //
        //   message:
        //     Format string of the log message in message template format. Example: "User {User}
        //     logged in from {Address}"
        //
        //   args:
        //     An object array that contains zero or more objects to format.
        public static void LogInformation(EventId eventId, Exception? exception, string? message, params object?[] args)
        {
            Get.Log(LogLevel.Information, eventId, exception, message, args);
        }
    
        //
        // Summary:
        //     Formats and writes an informational log message.
        //
        // Parameters:
        //   logger:
        //     The Microsoft.Extensions.Logging.ILogger to write to.
        //
        //   eventId:
        //     The event id associated with the log.
        //
        //   message:
        //     Format string of the log message in message template format. Example: "User {User}
        //     logged in from {Address}"
        //
        //   args:
        //     An object array that contains zero or more objects to format.
        public static void LogInformation(EventId eventId, string? message, params object?[] args)
        {
            Get.Log(LogLevel.Information, eventId, message, args);
        }
    
        //
        // Summary:
        //     Formats and writes an informational log message.
        //
        // Parameters:
        //   logger:
        //     The Microsoft.Extensions.Logging.ILogger to write to.
        //
        //   exception:
        //     The exception to log.
        //
        //   message:
        //     Format string of the log message in message template format. Example: "User {User}
        //     logged in from {Address}"
        //
        //   args:
        //     An object array that contains zero or more objects to format.
        public static void LogInformation(Exception? exception, string? message, params object?[] args)
        {
            Get.Log(LogLevel.Information, exception, message, args);
        }
    
        //
        // Summary:
        //     Formats and writes an informational log message.
        //
        // Parameters:
        //   logger:
        //     The Microsoft.Extensions.Logging.ILogger to write to.
        //
        //   message:
        //     Format string of the log message in message template format. Example: "User {User}
        //     logged in from {Address}"
        //
        //   args:
        //     An object array that contains zero or more objects to format.
        public static void LogInformation(string? message, params object?[] args)
        {
            Get.Log(LogLevel.Information, message, args);
        }
    
        //
        // Summary:
        //     Formats and writes a warning log message.
        //
        // Parameters:
        //   logger:
        //     The Microsoft.Extensions.Logging.ILogger to write to.
        //
        //   eventId:
        //     The event id associated with the log.
        //
        //   exception:
        //     The exception to log.
        //
        //   message:
        //     Format string of the log message in message template format. Example: "User {User}
        //     logged in from {Address}"
        //
        //   args:
        //     An object array that contains zero or more objects to format.
        public static void LogWarning(EventId eventId, Exception? exception, string? message, params object?[] args)
        {
            Get.Log(LogLevel.Warning, eventId, exception, message, args);
        }
    
        //
        // Summary:
        //     Formats and writes a warning log message.
        //
        // Parameters:
        //   logger:
        //     The Microsoft.Extensions.Logging.ILogger to write to.
        //
        //   eventId:
        //     The event id associated with the log.
        //
        //   message:
        //     Format string of the log message in message template format. Example: "User {User}
        //     logged in from {Address}"
        //
        //   args:
        //     An object array that contains zero or more objects to format.
        public static void LogWarning(EventId eventId, string? message, params object?[] args)
        {
            Get.Log(LogLevel.Warning, eventId, message, args);
        }
    
        //
        // Summary:
        //     Formats and writes a warning log message.
        //
        // Parameters:
        //   logger:
        //     The Microsoft.Extensions.Logging.ILogger to write to.
        //
        //   exception:
        //     The exception to log.
        //
        //   message:
        //     Format string of the log message in message template format. Example: "User {User}
        //     logged in from {Address}"
        //
        //   args:
        //     An object array that contains zero or more objects to format.
        public static void LogWarning(Exception? exception, string? message, params object?[] args)
        {
            Get.Log(LogLevel.Warning, exception, message, args);
        }
    
        //
        // Summary:
        //     Formats and writes a warning log message.
        //
        // Parameters:
        //   logger:
        //     The Microsoft.Extensions.Logging.ILogger to write to.
        //
        //   message:
        //     Format string of the log message in message template format. Example: "User {User}
        //     logged in from {Address}"
        //
        //   args:
        //     An object array that contains zero or more objects to format.
        public static void LogWarning(string? message, params object?[] args)
        {
            Get.Log(LogLevel.Warning, message, args);
        }
    
        //
        // Summary:
        //     Formats and writes an error log message.
        //
        // Parameters:
        //   logger:
        //     The Microsoft.Extensions.Logging.ILogger to write to.
        //
        //   eventId:
        //     The event id associated with the log.
        //
        //   exception:
        //     The exception to log.
        //
        //   message:
        //     Format string of the log message in message template format. Example: "User {User}
        //     logged in from {Address}"
        //
        //   args:
        //     An object array that contains zero or more objects to format.
        public static void LogError(EventId eventId, Exception? exception, string? message, params object?[] args)
        {
            Get.Log(LogLevel.Error, eventId, exception, message, args);
        }
    
        //
        // Summary:
        //     Formats and writes an error log message.
        //
        // Parameters:
        //   logger:
        //     The Microsoft.Extensions.Logging.ILogger to write to.
        //
        //   eventId:
        //     The event id associated with the log.
        //
        //   message:
        //     Format string of the log message in message template format. Example: "User {User}
        //     logged in from {Address}"
        //
        //   args:
        //     An object array that contains zero or more objects to format.
        public static void LogError(EventId eventId, string? message, params object?[] args)
        {
            Get.Log(LogLevel.Error, eventId, message, args);
        }
    
        //
        // Summary:
        //     Formats and writes an error log message.
        //
        // Parameters:
        //   logger:
        //     The Microsoft.Extensions.Logging.ILogger to write to.
        //
        //   exception:
        //     The exception to log.
        //
        //   message:
        //     Format string of the log message in message template format. Example: "User {User}
        //     logged in from {Address}"
        //
        //   args:
        //     An object array that contains zero or more objects to format.
        public static void LogError(Exception? exception, string? message, params object?[] args)
        {
            Get.Log(LogLevel.Error, exception, message, args);
        }
    
        //
        // Summary:
        //     Formats and writes an error log message.
        //
        // Parameters:
        //   logger:
        //     The Microsoft.Extensions.Logging.ILogger to write to.
        //
        //   message:
        //     Format string of the log message in message template format. Example: "User {User}
        //     logged in from {Address}"
        //
        //   args:
        //     An object array that contains zero or more objects to format.
        public static void LogError(string? message, params object?[] args)
        {
            Get.Log(LogLevel.Error, message, args);
        }
    
        //
        // Summary:
        //     Formats and writes a critical log message.
        //
        // Parameters:
        //   logger:
        //     The Microsoft.Extensions.Logging.ILogger to write to.
        //
        //   eventId:
        //     The event id associated with the log.
        //
        //   exception:
        //     The exception to log.
        //
        //   message:
        //     Format string of the log message in message template format. Example: "User {User}
        //     logged in from {Address}"
        //
        //   args:
        //     An object array that contains zero or more objects to format.
        public static void LogCritical(EventId eventId, Exception? exception, string? message, params object?[] args)
        {
            Get.Log(LogLevel.Critical, eventId, exception, message, args);
        }
    
        //
        // Summary:
        //     Formats and writes a critical log message.
        //
        // Parameters:
        //   logger:
        //     The Microsoft.Extensions.Logging.ILogger to write to.
        //
        //   eventId:
        //     The event id associated with the log.
        //
        //   message:
        //     Format string of the log message in message template format. Example: "User {User}
        //     logged in from {Address}"
        //
        //   args:
        //     An object array that contains zero or more objects to format.
        public static void LogCritical(EventId eventId, string? message, params object?[] args)
        {
            Get.Log(LogLevel.Critical, eventId, message, args);
        }
    
        //
        // Summary:
        //     Formats and writes a critical log message.
        //
        // Parameters:
        //   logger:
        //     The Microsoft.Extensions.Logging.ILogger to write to.
        //
        //   exception:
        //     The exception to log.
        //
        //   message:
        //     Format string of the log message in message template format. Example: "User {User}
        //     logged in from {Address}"
        //
        //   args:
        //     An object array that contains zero or more objects to format.
        public static void LogCritical(Exception? exception, string? message, params object?[] args)
        {
            Get.Log(LogLevel.Critical, exception, message, args);
        }
    
        //
        // Summary:
        //     Formats and writes a critical log message.
        //
        // Parameters:
        //   logger:
        //     The Microsoft.Extensions.Logging.ILogger to write to.
        //
        //   message:
        //     Format string of the log message in message template format. Example: "User {User}
        //     logged in from {Address}"
        //
        //   args:
        //     An object array that contains zero or more objects to format.
        public static void LogCritical(string? message, params object?[] args)
        {
            Get.Log(LogLevel.Critical, message, args);
        }
    
        //
        // Summary:
        //     Formats and writes a log message at the specified log level.
        //
        // Parameters:
        //   logger:
        //     The Microsoft.Extensions.Logging.ILogger to write to.
        //
        //   logLevel:
        //     Entry will be written on this level.
        //
        //   message:
        //     Format string of the log message.
        //
        //   args:
        //     An object array that contains zero or more objects to format.
        public static void Log(LogLevel logLevel, string? message, params object?[] args)
        {
            Get.Log(logLevel, message, args);
        }
    
        //
        // Summary:
        //     Formats and writes a log message at the specified log level.
        //
        // Parameters:
        //   logger:
        //     The Microsoft.Extensions.Logging.ILogger to write to.
        //
        //   logLevel:
        //     Entry will be written on this level.
        //
        //   eventId:
        //     The event id associated with the log.
        //
        //   message:
        //     Format string of the log message.
        //
        //   args:
        //     An object array that contains zero or more objects to format.
        public static void Log(LogLevel logLevel, EventId eventId, string? message, params object?[] args)
        {
            Get.Log(logLevel, eventId, message, args);
        }
    
        //
        // Summary:
        //     Formats and writes a log message at the specified log level.
        //
        // Parameters:
        //   logger:
        //     The Microsoft.Extensions.Logging.ILogger to write to.
        //
        //   logLevel:
        //     Entry will be written on this level.
        //
        //   exception:
        //     The exception to log.
        //
        //   message:
        //     Format string of the log message.
        //
        //   args:
        //     An object array that contains zero or more objects to format.
        public static void Log(LogLevel logLevel, Exception? exception, string? message, params object?[] args)
        {
            Get.Log(logLevel, exception, message, args);
        }
    
        //
        // Summary:
        //     Formats and writes a log message at the specified log level.
        //
        // Parameters:
        //   logger:
        //     The Microsoft.Extensions.Logging.ILogger to write to.
        //
        //   logLevel:
        //     Entry will be written on this level.
        //
        //   eventId:
        //     The event id associated with the log.
        //
        //   exception:
        //     The exception to log.
        //
        //   message:
        //     Format string of the log message.
        //
        //   args:
        //     An object array that contains zero or more objects to format.
        public static void Log(LogLevel logLevel, EventId eventId, Exception? exception, string? message, params object?[] args)
        {
            Get.Log(logLevel,eventId,exception,message,args);
        }
    
        //
        // Summary:
        //     Formats the message and creates a scope.
        //
        // Parameters:
        //   logger:
        //     The Microsoft.Extensions.Logging.ILogger to create the scope in.
        //
        //   messageFormat:
        //     Format string of the log message in message template format. Example: "User {User}
        //     logged in from {Address}"
        //
        //   args:
        //     An object array that contains zero or more objects to format.
        //
        // Returns:
        //     A disposable scope object. Can be null.
        public static IDisposable? BeginScope(string messageFormat, params object?[] args)
        {
            return Get.BeginScope(messageFormat, args);
        }
    }
}
