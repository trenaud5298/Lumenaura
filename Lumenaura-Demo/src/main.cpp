#include <iostream>
#include <Lumenaura/Lumenaura_Logging.h>
#include <Lumenaura/Lumenaura_Settings.h>

#include <chrono>
#include <string>

int main(int argc, char* argv[]) {
    std::cout<<"This Is The Lumenaura-Demo Executable"<<std::endl;

    Lumenaura::Logging::initLogging();
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime = std::chrono::high_resolution_clock::now();
    
    Lumenaura::Logging::log(LOG_TYPE_DEBUG, "My Test Log 1");
    Lumenaura::Logging::log(LOG_TYPE_WARNING, "My Test Log 2");
    Lumenaura::Logging::log(LOG_TYPE_WARNING, "My Test Log 3");
    Lumenaura::Logging::log(LOG_TYPE_INFO, "My Test Log 4");
    Lumenaura::Logging::log(LOG_TYPE_INFO, "My Test Log 5");
    Lumenaura::Logging::log(LOG_TYPE_ERROR, "My Test Log 6");
    Lumenaura::Logging::log(LOG_TYPE_ERROR, "My Test Log 7");
    Lumenaura::Logging::log(LOG_TYPE_FATAL, "My Test Log 8");

    Lumenaura::Logging::Settings::setMinimumLogLevel(LOG_TYPE_ERROR);

    Lumenaura::Logging::log(LOG_TYPE_DEBUG, "My Test Log 9");
    Lumenaura::Logging::log(LOG_TYPE_WARNING, "My Test Log 10");
    Lumenaura::Logging::log(LOG_TYPE_WARNING, "My Test Log 11");
    Lumenaura::Logging::log(LOG_TYPE_INFO, "My Test Log 12");
    Lumenaura::Logging::log(LOG_TYPE_INFO, "My Test Log 13");
    Lumenaura::Logging::log(LOG_TYPE_ERROR | LOG_TYPE_DEBUG, "My Test Log 14");
    
    std::chrono::time_point<std::chrono::high_resolution_clock> endTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsedTime = endTime - startTime;
    std::cout<<"Time Elapsed "<<elapsedTime.count()<<" ms\n";
    
    Lumenaura::Logging::printLog();

    Lumenaura::Logging::shutdownLogging();
    return 0;
}