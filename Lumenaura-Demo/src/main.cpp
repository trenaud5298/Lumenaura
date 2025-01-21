#include <iostream>
#include <Lumenaura/Lumenaura.h>

#include <chrono>
#include <string>
#include <thread>

int main(int argc, char* argv[]) {
    std::cout<<"This Is The Lumenaura-Demo Executable"<<std::endl;
    Lumenaura::init(Lumenaura::Logging::ConfigStruct(LOG_TYPE_DEBUG,true,true));
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime = std::chrono::high_resolution_clock::now();
    
    for(size_t i = 0; i < 250; i++) {
        Lumenaura::Logging::log(LOG_TYPE_DEBUG, "This Is A Test Log");
    }
    
    std::chrono::time_point<std::chrono::high_resolution_clock> endTime1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsedTime1 = endTime1 - startTime;
    std::cout<<"1Mil Logs Elapsed Time "<<elapsedTime1.count()<<" ms\n";
    
    Lumenaura::shutdown();

    std::chrono::time_point<std::chrono::high_resolution_clock> endTime2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsedTime2 = endTime2 - startTime;
    std::cout<<"Main Thread Finished Time "<<elapsedTime2.count()<<" ms\n";
    return 0;
}