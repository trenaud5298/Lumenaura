#ifndef LUMENAURA_HOSTMEMORY_H
#define LUMENAURA_HOSTMEMORY_H

//C++ Includes
#include <vector>
#include <chrono>
#include <stack>

//Lumeanaura Includes
#include <Lumenaura_Internal/Lumenaura_LogEntry.h>
#include <Lumenaura/Lumenaura_Settings.h>

namespace Lumenaura::HostMemory {
    /* Lumenaura Timer */
    extern std::chrono::steady_clock::time_point programStartTime;
    extern std::stack<std::chrono::steady_clock::time_point> timerStack;

    /* Lumenaura Logging */
    extern bool loggingInitialized;
    extern LoggingSettings loggingSettings;
    extern std::vector<LogEntry> log;
}



#endif