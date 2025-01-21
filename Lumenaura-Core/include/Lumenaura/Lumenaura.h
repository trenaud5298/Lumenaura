#ifndef LUMENAURA_H
#define LUMENAURA_H


//C++ Includes
#include <optional>

//Lumenaura Includes
#include <Lumenaura/Lumenaura_Logging.h>
#include <Lumenaura/Lumenaura_Settings.h>
#include <Lumenaura/Lumenaura_ResourceManager.h>
#include <Lumenaura/Lumenaura_Scene.h>
#include <Lumenaura/Lumenaura_Debug.h>



namespace Lumenaura {

    bool init(
        std::optional<Logging::ConfigStruct> loggingConfig = std::nullopt,
        std::optional<Debug::ConfigStruct> debugConfig = std::nullopt,
        std::optional<Scene::ConfigStruct> sceneConfig = std::nullopt,
        std::optional<ResourceManager::ConfigStruct> resourceManagerConfig = std::nullopt
    );

    bool shutdown();

};


#endif