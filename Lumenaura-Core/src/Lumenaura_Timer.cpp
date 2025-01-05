//C++ Includes


//Lumenaura Includes
#include <Lumenaura_Internal/Lumenaura_Timer.h>
#include <Lumenaura_Internal/Lumenaura_HostMemory.h>

namespace Lumenaura::Timer {

    void startTimer() noexcept {
        Lumenaura::HostMemory::timerStack.push(std::chrono::steady_clock::now());
    }

    template <typename DurationType>
    long long stopTimer() noexcept {
        if(Lumenaura::HostMemory::timerStack.empty()) {
            return 0;
        }
        long long elapsedTime = (std::chrono::duration_cast<DurationType>(std::chrono::steady_clock::now() - Lumenaura::HostMemory::timerStack.top())).count();
        Lumenaura::HostMemory::timerStack.pop();
        return elapsedTime;
    }

    template <typename DurationType>
    long long peekTimer() noexcept {
        if(Lumenaura::HostMemory::timerStack.empty()) {
            return 0;
        }
        return (std::chrono::duration_cast<DurationType>(std::chrono::steady_clock::now() - Lumenaura::HostMemory::timerStack.top())).count();
    }

    template <typename DurationType>
    long long timeElapsedSinceProgramStart() noexcept {
        return (std::chrono::duration_cast<DurationType>(std::chrono::steady_clock::now() - Lumenaura::HostMemory::programStartTime)).count();
    }

    void clearTimers() noexcept {
        while(!Lumenaura::HostMemory::timerStack.empty()) {
            Lumenaura::HostMemory::timerStack.pop();
        }
    }

}

template long long Lumenaura::Timer::stopTimer<std::chrono::seconds>();
template long long Lumenaura::Timer::stopTimer<std::chrono::milliseconds>();
template long long Lumenaura::Timer::stopTimer<std::chrono::microseconds>();
template long long Lumenaura::Timer::stopTimer<std::chrono::nanoseconds>();

template long long Lumenaura::Timer::peekTimer<std::chrono::seconds>();
template long long Lumenaura::Timer::peekTimer<std::chrono::milliseconds>();
template long long Lumenaura::Timer::peekTimer<std::chrono::microseconds>();
template long long Lumenaura::Timer::peekTimer<std::chrono::nanoseconds>();

template long long Lumenaura::Timer::timeElapsedSinceProgramStart<std::chrono::seconds>();
template long long Lumenaura::Timer::timeElapsedSinceProgramStart<std::chrono::milliseconds>();
template long long Lumenaura::Timer::timeElapsedSinceProgramStart<std::chrono::microseconds>();
template long long Lumenaura::Timer::timeElapsedSinceProgramStart<std::chrono::nanoseconds>();
