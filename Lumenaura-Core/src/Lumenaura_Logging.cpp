//C++ Includes
#include <vector>
#include <string>
#include <iostream>

//Lumenaura Includes
#include <Lumenaura/Lumenaura_Logging.h>
#include <Lumenaura_Internal/Lumenaura_HostMemory.h>

namespace Lumenaura::Logging {

    //Calls Next log() Method With C String
    void log(unsigned char logType, const std::string& logMessage) {
        log(logType, logMessage.c_str());
    }

    // Logs a message with a specific log type.
    void log(unsigned char logType, const char* logMessage) {
        //This Check Also Ensures That Logging Has Been Initialized
        //Since Otherwise Minimum Log Level Is 0xFF Preventing ALl Log
        //Messages From Being Recorded
        if(logType < Memory::loggingSettings.m_minimumLogLevel) {
            return;
        }
        Memory::log.emplace_back(logType, logMessage);
    }

    // Checks whether logging is enabled.
    bool isLoggingEnabled() {
        // return Memory::loggingInitialized;
        return true;
    }

    // Gets the first log of a specific type.
    const char* getFirstLogOfType(unsigned char logType) {
        for(size_t i = 0; i < Memory::log.size(); ++i) {
            if(Memory::log[i].m_logType & logType) {
                return Memory::log[i].m_logMessage;
            }
        }
        return nullptr; // No log found
    }

    // Gets the last log of a specific type.
    const char* getLastLogOfType(unsigned char logType) {
        for(size_t i = Memory::log.size() - 1; i >= 0; --i) {
            if(Memory::log[i].m_logType & logType) {
                return Memory::log[i].m_logMessage;
            }
        }
        return nullptr; // No log found
    }

    // Gets all logs of a specific type.
    std::vector<const char*> getAllLogsOfType(unsigned char logType) {
        std::vector<const char*> results;
        for(size_t i = 0; i < Memory::log.size(); ++i) {
            if(Memory::log[i].m_logType & logType) {
                results.push_back(Memory::log[i].m_logMessage);
            }
        }
        return results; 
    }

    void printLog(std::ostream& out) {
        printLogOfType(LOG_TYPE_ALL, out);
    }

    void printLogOfType(unsigned char logType, std::ostream& out) {
        out<<"---Start Of Lumenaura Log---\n";
        for(size_t i = 0; i < Memory::log.size(); ++i) {
            if(Memory::log[i].m_logType & logType) {
                out<<Memory::log[i].m_logMessage<<"\n";
            }
        }
        out<<"----End Of Lumenaura Log----\n";
    }

    bool saveLogToFile(const std::filesystem::path& filePath) {
        std::ofstream fileOutput;
        fileOutput.open(filePath, std::ios::out);

        if (!fileOutput.is_open()) {
            log(LOG_TYPE_ERROR, "Failed To Save Log At Filepath: " + filePath.string());
            return false;
        }

        fileOutput<<"---Start Of Lumenaura Log---\n";
        for(size_t i = 0; i < Memory::log.size(); ++i) {
            fileOutput<<Memory::log[i].m_logMessage<<"\n";
        }
        fileOutput<<"----End Of Lumenaura Log----\n";

        fileOutput.close();
        return true;
    }

}


namespace Lumenaura::Logging::Settings {

    void setConfig(ConfigStruct loggingSettings){ 
        Memory::loggingSettings = loggingSettings;
    }

    ConfigStruct getConfig(){ 
        return Memory::loggingSettings;
    }

    void setMinimumLogLevel(unsigned char logType){ 
        Memory::loggingSettings.m_minimumLogLevel = logType;    
    }

    unsigned char getMinimumLogLevel(){ 
        return Memory::loggingSettings.m_minimumLogLevel;
    }

    void setSaveLogOnShutdown(bool saveLogOnShutdown){ 
        Memory::loggingSettings.m_saveLogOnShutdown = saveLogOnShutdown;
    }

    bool getSaveLogOnShutdown(){ 
        return Memory::loggingSettings.m_saveLogOnShutdown;
    }

    void setRecordTimeOnLogs(bool recordTimeOnLogs){ 
        Memory::loggingSettings.m_recordTimeOnLogs = recordTimeOnLogs;
    }

    bool getRecordTimeOnLogs(){ 
        return Memory::loggingSettings.m_recordTimeOnLogs;
    }

}
