#include <Lumenaura_Internal/Lumenaura_LogEntry.h>
#include <Lumenaura_Internal/Lumenaura_HostMemory.h>
#include <Lumenaura_Internal/Lumenaura_Timer.h>
#include <string>
#include <iostream>

LogEntry::LogEntry() {
    m_logMessage = nullptr;
    m_logType = 0x00;
}



LogEntry::LogEntry(unsigned char logType, const char* rawLogMessage) {
    m_logType = logType;
    m_logMessage = (Lumenaura::HostMemory::loggingSettings.m_recordTimeOnLogs) ? formatLogMessageWithTime(logType, rawLogMessage) : formatLogMessageWithoutTime(logType, rawLogMessage);
}

LogEntry::~LogEntry() {
    if(m_logMessage) {
        delete[] m_logMessage;
    }
}


LogEntry::LogEntry(const LogEntry& other) {
    //Deep Copies Log Entry
    m_logType = other.m_logType;

    if (other.m_logMessage) {
        char* logMessage = new char[std::strlen(other.m_logMessage) + 1];
        std::strcpy(logMessage, other.m_logMessage);
        m_logMessage = logMessage;
    } else {
        m_logMessage = nullptr;
    }
}

LogEntry& LogEntry::operator=(const LogEntry& other) {
    //Deep Copies Log Entry Avoiding Self Assignment
    if (this != &other) {
        //Cleans Up Old Memory Before Copying Other LogEntry
        delete[] m_logMessage; 

        //Performs Deep Copy
        m_logType = other.m_logType;
        if (other.m_logMessage) {
            char* logMessage = new char[std::strlen(other.m_logMessage) + 1];
            std::strcpy(logMessage, other.m_logMessage);
            m_logMessage = logMessage;
        } else {
            m_logMessage = nullptr;
        }
    }
    return *this;
}

LogEntry::LogEntry(LogEntry&& other) noexcept 
    : m_logMessage(other.m_logMessage), m_logType(other.m_logType) {
    
    other.m_logMessage = nullptr;
    other.m_logType = 0;
}

LogEntry& LogEntry::operator=(LogEntry&& other) noexcept {
    //Transfers Ownership Avoiding Self-Assignment For Move Operator
    if (this != &other) {
        //Cleans Up Old Memory Before Taking Ownership From Other LogEntry
        delete[] m_logMessage;

        //Transfer Ownership Of Resources
        m_logMessage = other.m_logMessage;
        m_logType = other.m_logType;

        //Nullify Other To Leave It In A Valid State
        other.m_logMessage = nullptr;
        other.m_logType = 0;
    }
    return *this;
}


const char* LogEntry::formatLogMessageWithoutTime(unsigned char logType, const char* rawLogMessage) {
    int messageSize = 2;

    if(logType & LOG_TYPE_FATAL  ) {messageSize += 7;}
    if(logType & LOG_TYPE_ERROR  ) {messageSize += 7;}
    if(logType & LOG_TYPE_WARNING) {messageSize += 9;}
    if(logType & LOG_TYPE_INFO   ) {messageSize += 6;}
    if(logType & LOG_TYPE_DEBUG  ) {messageSize += 7;}
    messageSize += strlen(rawLogMessage);

    char* logMessage = new char[messageSize];
    char* currentPos = logMessage;

    if (logType & LOG_TYPE_FATAL) {
        std::strcpy(currentPos, "[FATAL]");
        currentPos += 7;
    }
    if (logType & LOG_TYPE_ERROR) {
        std::strcpy(currentPos, "[ERROR]");
        currentPos += 7;
    }
    if (logType & LOG_TYPE_WARNING) {
        std::strcpy(currentPos, "[WARNING]");
        currentPos += 9;
    }
    if (logType & LOG_TYPE_INFO) {
        std::strcpy(currentPos, "[INFO]");
        currentPos += 6;
    }
    if (logType & LOG_TYPE_DEBUG) {
        std::strcpy(currentPos, "[DEBUG]");
        currentPos += 7;
    }

    currentPos[0] = ' ';
    std::strcpy(currentPos+1, rawLogMessage);
    logMessage[messageSize - 1] = '\0';

    return logMessage;
}

const char* LogEntry::formatLogMessageWithTime(unsigned char logType, const char* rawLogMessage) {
    //Calculate Message Size
    int messageSize = 15;
    if(logType & LOG_TYPE_FATAL  ) {messageSize += 7;}
    if(logType & LOG_TYPE_ERROR  ) {messageSize += 7;}
    if(logType & LOG_TYPE_WARNING) {messageSize += 9;}
    if(logType & LOG_TYPE_INFO   ) {messageSize += 6;}
    if(logType & LOG_TYPE_DEBUG  ) {messageSize += 7;}
    messageSize += strlen(rawLogMessage);

    //Allocate Memory For Log Message
    char* logMessage = new char[messageSize];
    char* currentPos = logMessage;

    //Calculate Time For Beginning Of Log Message
    long long millisecondsSinceStartOfProgram = Lumenaura::Timer::timeElapsedSinceProgramStart<std::chrono::milliseconds>();
    long long hoursSinceStartOfProgram = millisecondsSinceStartOfProgram / 3600000;
    

    //Write Time To Beginning Of Log Message
    if(hoursSinceStartOfProgram > 99) {
        currentPos[0] = '9';
        currentPos[1] = '9';
        currentPos[2] = ':';
        currentPos[3] = '9';
        currentPos[4] = '9';
        currentPos[5] = ':';
        currentPos[6] = '9';
        currentPos[7] = '9';
        currentPos[8] = '.';
        currentPos[9] = '9';
        currentPos[10] = '9';
        currentPos[11] = '9';
        currentPos[12] = ' ';
    } else {
        millisecondsSinceStartOfProgram %= 3600000;
        long long minutesSinceStartOfProgram = millisecondsSinceStartOfProgram / 60000;
        millisecondsSinceStartOfProgram %= 60000;
        long long secondsSinceStartOfProgram = millisecondsSinceStartOfProgram / 1000;
        millisecondsSinceStartOfProgram %= 1000;
        currentPos[0] = '0' + (hoursSinceStartOfProgram / 10);
        currentPos[1] = '0' + (hoursSinceStartOfProgram % 10);
        currentPos[2] = ':';
        currentPos[3] = '0' + (minutesSinceStartOfProgram / 10);
        currentPos[4] = '0' + (minutesSinceStartOfProgram % 10);
        currentPos[5] = ':';
        currentPos[6] = '0' + (secondsSinceStartOfProgram / 10);
        currentPos[7] = '0' + (secondsSinceStartOfProgram % 10);
        currentPos[8] = '.';
        currentPos[9] = '0' + (millisecondsSinceStartOfProgram / 100);
        currentPos[10] = '0' + ((millisecondsSinceStartOfProgram / 10) % 10);
        currentPos[11] = '0' + (millisecondsSinceStartOfProgram % 10);     
        currentPos[12] = ' ';  
    }
    currentPos += 13;

    //Write Log Type To Log Message
    if (logType & LOG_TYPE_FATAL) {
        std::strcpy(currentPos, "[FATAL]");
        currentPos += 7;
    }
    if (logType & LOG_TYPE_ERROR) {
        std::strcpy(currentPos, "[ERROR]");
        currentPos += 7;
    }
    if (logType & LOG_TYPE_WARNING) {
        std::strcpy(currentPos, "[WARNING]");
        currentPos += 9;
    }
    if (logType & LOG_TYPE_INFO) {
        std::strcpy(currentPos, "[INFO]");
        currentPos += 6;
    }
    if (logType & LOG_TYPE_DEBUG) {
        std::strcpy(currentPos, "[DEBUG]");
        currentPos += 7;
    }

    currentPos[0] = ' ';
    std::strcpy(currentPos+1, rawLogMessage);
    logMessage[messageSize - 1] = '\0';

    return logMessage;
}