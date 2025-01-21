//C++ Includes

//Lumenaura Includes
#include <Lumenaura_Internal/Lumenaura_HostMemory.h>

namespace Lumenaura::Memory {
    bool lumenauraInitialized = false;
}

namespace Lumenaura::Timer::Memory {
    std::chrono::steady_clock::time_point programStartTime = std::chrono::steady_clock::now();
    std::stack<std::chrono::steady_clock::time_point> timerStack = std::stack<std::chrono::steady_clock::time_point>();
};

namespace Lumenaura::Logging::Memory {
    ConfigStruct loggingSettings;
    std::vector<LogEntry> log;
};

namespace Lumenaura::Debug::Memory {
    ConfigStruct debugSettings;
};

namespace Lumenaura::Scene::Memory {
    ConfigStruct sceneSettings;
    Camera sceneCamera;
    std::vector<Sphere> sceneSpheres;
    std::vector<Triangle> sceneTriangles;
    Material sceneMaterials[256] = {
        Material(),
        Material()
    };
};

namespace Lumenaura::ResourceManager::Memory {
    ConfigStruct resourceManagerSettings;
};



