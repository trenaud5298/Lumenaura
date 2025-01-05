//C++ Includes
#include <vector>
#include <string>
#include <iostream>

//Lumenaura Includes
#include <Lumenaura/Lumenaura_Logging.h>
#include <Lumenaura_Internal/Lumenaura_HostMemory.h>

namespace Lumenaura::Logging {

    // Initializes the logging system.
    bool initLogging(LoggingSettings loggingSettings) {
        if(Lumenaura::HostMemory::loggingInitialized) {
            log(LOG_TYPE_WARNING, "Unable To Re-Initialize Logging Sub-Module Before Calling shutdownLogging() Method");
            return false;
        }

        Lumenaura::HostMemory::log.reserve(64);
        Lumenaura::HostMemory::loggingSettings = loggingSettings;
        Lumenaura::HostMemory::loggingInitialized = true;
        log(LOG_TYPE_INFO, "Logging Sub-Module Initialized");
        return true;
    }

    // Shuts down the logging system.
    bool shutdownLogging() {
        if(!Lumenaura::HostMemory::loggingInitialized) {
            return false;
        }

        Lumenaura::HostMemory::log.clear();
        Lumenaura::HostMemory::loggingInitialized = false;
        return true;
    }

    //Calls Next log() Method With C String
    void log(unsigned char logType, const std::string& logMessage) {
        log(logType, logMessage.c_str());
    }

    // Logs a message with a specific log type.
    void log(unsigned char logType, const char* logMessage) {
        //This Check Also Ensures That Logging Has Been Initialized
        //Since Otherwise Minimum Log Level Is 0xFF Preventing ALl Log
        //Messages From Being Recorded
        if(logType < Lumenaura::HostMemory::loggingSettings.m_minimumLogLevel) {
            return;
        }
        Lumenaura::HostMemory::log.emplace_back(logType, logMessage);
    }

    // Checks whether logging is enabled.
    bool isLoggingEnabled() {
        return Lumenaura::HostMemory::loggingInitialized;
    }

    // Gets the first log of a specific type.
    const char* getFirstLogOfType(unsigned char logType) {
        for(size_t i = 0; i < Lumenaura::HostMemory::log.size(); ++i) {
            if(Lumenaura::HostMemory::log[i].m_logType & logType) {
                return Lumenaura::HostMemory::log[i].m_logMessage;
            }
        }
        return nullptr; // No log found
    }

    // Gets the last log of a specific type.
    const char* getLastLogOfType(unsigned char logType) {
        for(size_t i = Lumenaura::HostMemory::log.size() - 1; i >= 0; --i) {
            if(Lumenaura::HostMemory::log[i].m_logType & logType) {
                return Lumenaura::HostMemory::log[i].m_logMessage;
            }
        }
        return nullptr; // No log found
    }

    // Gets all logs of a specific type.
    std::vector<const char*> getAllLogsOfType(unsigned char logType) {
        std::vector<const char*> results;
        for(size_t i = 0; i < Lumenaura::HostMemory::log.size(); ++i) {
            if(Lumenaura::HostMemory::log[i].m_logType & logType) {
                results.push_back(Lumenaura::HostMemory::log[i].m_logMessage);
            }
        }
        return results; 
    }

    void printLog(std::ostream& out) {
        printLogOfType(LOG_TYPE_ALL, out);
    }

    void printLogOfType(unsigned char logType, std::ostream& out) {
        out<<"---Start Of Lumenaura Log---\n";
        for(size_t i = 0; i < Lumenaura::HostMemory::log.size(); ++i) {
            if(Lumenaura::HostMemory::log[i].m_logType & logType) {
                out<<Lumenaura::HostMemory::log[i].m_logMessage<<"\n";
            }
        }
        out<<"----End Of Lumenaura Log----\n";
    }

}


namespace Lumenaura::Logging::Settings {

    void setLoggingSettings(LoggingSettings loggingSettings){ 
        Lumenaura::HostMemory::loggingSettings = loggingSettings;
    }

    LoggingSettings getLoggingSettings(){ 
        return Lumenaura::HostMemory::loggingSettings;
    }

    void setMinimumLogLevel(unsigned char logType){ 
        Lumenaura::HostMemory::loggingSettings.m_minimumLogLevel = logType;    
    }

    unsigned char getMinimumLogLevel(){ 
        return Lumenaura::HostMemory::loggingSettings.m_minimumLogLevel;
    }

    void setSaveLogOnShutdown(bool saveLogOnShutdown){ 
        Lumenaura::HostMemory::loggingSettings.m_saveLogOnShutdown = saveLogOnShutdown;
    }

    bool getSaveLogOnShutdown(){ 
        return Lumenaura::HostMemory::loggingSettings.m_saveLogOnShutdown;
    }

    void setRecordTimeOnLogs(bool recordTimeOnLogs){ 
        Lumenaura::HostMemory::loggingSettings.m_recordTimeOnLogs = recordTimeOnLogs;
    }

    bool getRecordTimeOnLogs(){ 
        return Lumenaura::HostMemory::loggingSettings.m_recordTimeOnLogs;
    }

}