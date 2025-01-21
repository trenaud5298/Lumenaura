//C++ Includes

//Lumenaura Includes
#include <Lumenaura/Lumenaura.h>
#include <Lumenaura_Internal/Lumenaura_HostMemory.h>

namespace Lumenaura {

    bool init(
        std::optional<Logging::ConfigStruct> loggingConfig,
        std::optional<Debug::ConfigStruct> debugConfig,
        std::optional<Scene::ConfigStruct> sceneConfig,
        std::optional<ResourceManager::ConfigStruct> resourceManagerConfig
    ) {

        if(Lumenaura::Memory::lumenauraInitialized) {
            Lumenaura::Logging::log(LOG_TYPE_ERROR, "Failed To Initialize Lumenaura: Lumenaura Is Already Initialized. Please Call shutdown() To Properly Handle Library Shutdown Before Re-Initializing Lumenaura Library.");
            return false;
        }

        Lumenaura::Logging::Memory::loggingSettings = loggingConfig.value_or(Lumenaura::Logging::ConfigStruct());
        Lumenaura::Debug::Memory::debugSettings = debugConfig.value_or(Lumenaura::Debug::ConfigStruct());
        Lumenaura::Scene::Memory::sceneSettings = sceneConfig.value_or(Lumenaura::Scene::ConfigStruct());
        Lumenaura::ResourceManager::Memory::resourceManagerSettings = resourceManagerConfig.value_or(Lumenaura::ResourceManager::ConfigStruct());
        
        
        Logging::Memory::log.reserve(512);
        Logging::log(LOG_TYPE_INFO, "Log Created");


        Memory::lumenauraInitialized = true;
        Logging::log(LOG_TYPE_INFO, "Log Created");
        return true;
    }

    bool shutdown() {
        std::cout<<"Shutting down"<<std::endl;
        if(!Memory::lumenauraInitialized) {
            return false;
        }


        std::cout<<"Save Log: "<<Logging::Memory::loggingSettings.m_saveLogOnShutdown<<"\n";
        if(Logging::Settings::getSaveLogOnShutdown()) {
            if(!Logging::saveLogToFile()) {
                std::cerr<<"Unable To Save Log On Shutdown!"<<std::endl;
            }
        }
        Logging::Memory::log.clear();

        return true;;
    }


}
