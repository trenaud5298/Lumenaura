#ifndef LUMENAURA_LOGGING_H
#define LUMENAURA_LOGGING_H

#include <vector>
#include <iostream>
#include <Lumenaura/Lumenaura_Settings.h>

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

//TODO: Impliment Log Saving, And Decide 'Who' Should Be In Charge Of This Feature; Logging, or ResourceManager
namespace Lumenaura::Logging {

    bool initLogging(LoggingSettings loggingSettings = LoggingSettings());

    bool shutdownLogging();

    void log(unsigned char logType, const std::string& logMessage);

    void log(unsigned char logType, const char* logMessage);

    bool isLoggingEnabled();
    
    const char* getFirstLogOfType(unsigned char logType);

    const char* getLastLogOfType(unsigned char logType);

    std::vector<const char*> getAllLogsOfType(unsigned char logType);

    void printLog(std::ostream& out = std::cout);

    void printLogOfType(unsigned char logType, std::ostream& out = std::cout);

};

namespace Lumenaura::Logging::Settings {

    void setLoggingSettings(LoggingSettings loggingSettings);

    LoggingSettings getLoggingSettings();

    void setMinimumLogLevel(unsigned char logType = LOG_TYPE_DEBUG);

    unsigned char getMinimumLogLevel();

    void setSaveLogOnShutdown(bool saveLogOnShutdown = true);

    bool getSaveLogOnShutdown();

    void setRecordTimeOnLogs(bool recordTimeOnLogs = true);

    bool getRecordTimeOnLogs();

};




#endif