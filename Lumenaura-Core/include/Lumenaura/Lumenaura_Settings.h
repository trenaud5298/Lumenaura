#ifndef LUMENAURA_SETTINGS_H
#define LUMENAURA_SETTINGS_H

struct LoggingSettings {
  
  
    unsigned char m_minimumLogLevel;
    bool m_saveLogOnShutdown;
    bool m_recordTimeOnLogs;

    LoggingSettings();
    LoggingSettings(unsigned char minimumLogLevel, bool saveLogOnShutdown, bool recordTimeOnLogs);

};

#endif