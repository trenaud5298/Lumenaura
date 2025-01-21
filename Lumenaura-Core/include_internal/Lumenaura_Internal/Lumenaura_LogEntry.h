#ifndef LUMENAURA_LOGENTRY_H
#define LUMENAURA_LOGENTRY_H


//Defines Macros For Different Log Types
#ifndef LOG_TYPE_DEBUG
    #define LOG_TYPE_DEBUG    0x01
#endif

#ifndef LOG_TYPE_INFO
    #define LOG_TYPE_INFO     0x02
#endif

#ifndef LOG_TYPE_WARNING
    #define LOG_TYPE_WARNING  0x04
#endif    

#ifndef LOG_TYPE_ERROR
    #define LOG_TYPE_ERROR    0x08
#endif

#ifndef LOG_TYPE_FATAL
    #define LOG_TYPE_FATAL    0x80
#endif

#ifndef LOG_TYPE_ALL
    #define LOG_TYPE_ALL (LOG_TYPE_DEBUG | LOG_TYPE_INFO | LOG_TYPE_WARNING | LOG_TYPE_ERROR | LOG_TYPE_FATAL)
#endif


struct LogEntry {

    //Primary Constructors For Creating A Log Entry Object
    LogEntry();
    LogEntry(unsigned char logType, const char* rawLogMessage);
    LogEntry(unsigned char logType, const char* rawLogMessage, long long logTime);
    
    //Destructor To Handle Proper Memory Cleanup Of LogEntry Objects
    ~LogEntry();

    //Copy Constructors Allow For Proper Deep Copying
    LogEntry(const LogEntry& other);
    LogEntry& operator=(const LogEntry& other);

    //Move Constructors Allow For Proper Transfering Of Ownership Avoiding Invalid Pointers
    LogEntry(LogEntry&& other) noexcept;
    LogEntry& operator=(LogEntry&& other) noexcept;

    //Provides Static Methods To Convert The Raw Log Message Into A Formatted One Based On Settings
    static const char* formatLogMessageWithoutTime(unsigned char logType, const char* rawLogMessage);
    static const char* formatLogMessageWithTime(unsigned char logType, const char* rawLogMessage, long long logTime); 

    //Internal Values For LogEntry Object
    unsigned char m_logType;
    const char* m_logMessage;
    
};








#endif