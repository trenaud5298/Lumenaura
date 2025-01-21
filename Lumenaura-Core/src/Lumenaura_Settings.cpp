#include <Lumenaura/Lumenaura_Settings.h>
#include <Lumenaura/Lumenaura_Logging.h>


namespace Lumenaura::Logging {

    ConfigStruct::ConfigStruct() : 
    m_minimumLogLevel(LOG_TYPE_DEBUG), m_saveLogOnShutdown(true), m_recordTimeOnLogs(true) 
    {

    }

    ConfigStruct::ConfigStruct(unsigned char minimumLogLevel, bool saveLogOnShutdown, bool recordTimeOnLogs) :
    m_minimumLogLevel(minimumLogLevel), m_saveLogOnShutdown(saveLogOnShutdown), m_recordTimeOnLogs(recordTimeOnLogs) 
    {
    
    }

};




namespace Lumenaura::Debug {

    ConfigStruct::ConfigStruct() : 
    m_debugRenderType(DIFFUSE_COLOR_MAP), m_debugRenderResolutionX(1200), m_debugRenderResolutionY(800)
    {
        
    }

    ConfigStruct::ConfigStruct(DEBUG_RENDER_TYPE debugRenderType, int debugRenderResolutionX, int debugRenderResolutionY) : 
    m_debugRenderType(debugRenderType), m_debugRenderResolutionX(debugRenderResolutionX), m_debugRenderResolutionY(debugRenderResolutionY)
    {
    
    }

};




namespace Lumenaura::Scene {

    ConfigStruct::ConfigStruct() : 
    m_minimumLogLevel(LOG_TYPE_DEBUG), m_saveLogOnShutdown(true), m_recordTimeOnLogs(true) 
    {

    }

    ConfigStruct::ConfigStruct(unsigned char minimumLogLevel, bool saveLogOnShutdown, bool recordTimeOnLogs) :
    m_minimumLogLevel(minimumLogLevel), m_saveLogOnShutdown(saveLogOnShutdown), m_recordTimeOnLogs(recordTimeOnLogs) 
    {
    
    }

};




namespace Lumenaura::ResourceManager {

    ConfigStruct::ConfigStruct() : 
    m_minimumLogLevel(LOG_TYPE_DEBUG), m_saveLogOnShutdown(true), m_recordTimeOnLogs(true) 
    {

    }

    ConfigStruct::ConfigStruct(unsigned char minimumLogLevel, bool saveLogOnShutdown, bool recordTimeOnLogs) :
    m_minimumLogLevel(minimumLogLevel), m_saveLogOnShutdown(saveLogOnShutdown), m_recordTimeOnLogs(recordTimeOnLogs) 
    {
    
    }

};
