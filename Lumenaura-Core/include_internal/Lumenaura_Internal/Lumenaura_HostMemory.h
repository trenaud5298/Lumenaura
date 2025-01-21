#ifndef LUMENAURA_HOSTMEMORY_H
#define LUMENAURA_HOSTMEMORY_H

//C++ Includes
#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <chrono>

//Lumeanaura Includes
#include <Lumenaura_Internal/Lumenaura_LogEntry.h>
#include <Lumenaura/Lumenaura_Settings.h>
#include <Lumenaura/Objects/Lumenaura_Camera.h>
#include <Lumenaura/Objects/Lumenaura_Cube.h>
#include <Lumenaura/Objects/Lumenaura_Material.h>
#include <Lumenaura/Objects/Lumenaura_Quadrilateral.h>
#include <Lumenaura/Objects/Lumenaura_Sphere.h>
#include <Lumenaura/Objects/Lumenaura_Triangle.h>

namespace Lumenaura::Memory {
    extern bool lumenauraInitialized;
};

namespace Lumenaura::Timer::Memory {
    extern std::chrono::steady_clock::time_point programStartTime;
    extern std::stack<std::chrono::steady_clock::time_point> timerStack;
};


namespace Lumenaura::Logging::Memory {
    extern ConfigStruct loggingSettings;
    extern std::vector<LogEntry> log;
};

namespace Lumenaura::Debug::Memory {
    extern ConfigStruct debugSettings;
};

namespace Lumenaura::Scene::Memory {
    extern ConfigStruct sceneSettings;
    extern Camera sceneCamera;
    extern std::vector<Sphere> sceneSpheres;
    extern std::vector<Triangle> sceneTriangles;
    extern Material sceneMaterials[256];
};

namespace Lumenaura::ResourceManager::Memory {
    extern ConfigStruct resourceManagerSettings;
};


#endif