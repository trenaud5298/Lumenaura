//C++ Includes

//Lumenaura Includes
#include <Lumenaura_Internal/Lumenaura_HostMemory.h>

namespace Lumenaura::HostMemory {
    /* Lumenaura Timer */
    std::chrono::steady_clock::time_point programStartTime = std::chrono::steady_clock::now();
    std::stack<std::chrono::steady_clock::time_point> timerStack = std::stack<std::chrono::steady_clock::time_point>();

    /* Lumenaura Logging */
    bool loggingInitialized = false;
    LoggingSettings loggingSettings = LoggingSettings();
    std::vector<LogEntry> log = std::vector<LogEntry>(0);
}