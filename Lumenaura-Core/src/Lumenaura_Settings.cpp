#include <Lumenaura/Lumenaura_Settings.h>
#include <Lumenaura/Lumenaura_Logging.h>

#pragma region Logging

LoggingSettings::LoggingSettings() : 
m_minimumLogLevel(LOG_TYPE_DEBUG), m_saveLogOnShutdown(true), m_recordTimeOnLogs(true) {

}

LoggingSettings::LoggingSettings(unsigned char minimumLogLevel, bool saveLogOnShutdown, bool recordTimeOnLogs) :
m_minimumLogLevel(minimumLogLevel), m_saveLogOnShutdown(saveLogOnShutdown), m_recordTimeOnLogs(recordTimeOnLogs) {
    
}


#pragma endregion