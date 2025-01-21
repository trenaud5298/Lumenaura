#ifndef LUMENAURA_SETTINGS_H
#define LUMENAURA_SETTINGS_H



namespace Lumenaura::Logging {

    struct ConfigStruct {

        unsigned char m_minimumLogLevel;
        bool m_saveLogOnShutdown;
        bool m_recordTimeOnLogs;

        ConfigStruct();
        ConfigStruct(unsigned char minimumLogLevel, bool saveLogOnShutdown, bool recordTimeOnLogs);
    };

}


namespace Lumenaura::Debug {


    enum DEBUG_RENDER_TYPE {
        DIFFUSE_COLOR_MAP = 0,
        SPECULAR_COLOR_MAP = 1,
        REFLECTIVENESS_MAP = 2,
        NORMAL_MAP = 3,
        INTERSECTION_TEST_MAP = 4
    };

    struct ConfigStruct {

        DEBUG_RENDER_TYPE m_debugRenderType;
        int m_debugRenderResolutionX;
        int m_debugRenderResolutionY;

        ConfigStruct();
        ConfigStruct(DEBUG_RENDER_TYPE debugRenderType, int debugRenderResolutionX, int debugRenderResolutionY);
    };

}

namespace Lumenaura::Scene {

    struct ConfigStruct {

        unsigned char m_minimumLogLevel;
        bool m_saveLogOnShutdown;
        bool m_recordTimeOnLogs;

        ConfigStruct();
        ConfigStruct(unsigned char minimumLogLevel, bool saveLogOnShutdown, bool recordTimeOnLogs);
    };

}

namespace Lumenaura::ResourceManager {

    struct ConfigStruct {

        unsigned char m_minimumLogLevel;
        bool m_saveLogOnShutdown;
        bool m_recordTimeOnLogs;

        ConfigStruct();
        ConfigStruct(unsigned char minimumLogLevel, bool saveLogOnShutdown, bool recordTimeOnLogs);
    };

}




#endif