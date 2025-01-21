//C++ Includes


//Lumenaura Includes
#include <Lumenaura_Internal/Lumenaura_Timer.h>
#include <Lumenaura_Internal/Lumenaura_HostMemory.h>

namespace Lumenaura::Timer {

    void startTimer() noexcept {
        Memory::timerStack.push(std::chrono::steady_clock::now());
    }

    template <typename DurationType>
    long long stopTimer() noexcept {
        if(Memory::timerStack.empty()) {
            return 0;
        }
        long long elapsedTime = (std::chrono::duration_cast<DurationType>(std::chrono::steady_clock::now() - Memory::timerStack.top())).count();
        Memory::timerStack.pop();
        return elapsedTime;
    }

    template <typename DurationType>
    long long peekTimer() noexcept {
        if(Memory::timerStack.empty()) {
            return 0;
        }
        return (std::chrono::duration_cast<DurationType>(std::chrono::steady_clock::now() - Memory::timerStack.top())).count();
    }

    template <typename DurationType>
    long long timeElapsedSinceProgramStart() noexcept {
        return (std::chrono::duration_cast<DurationType>(std::chrono::steady_clock::now() - Memory::programStartTime)).count();
    }

    void clearTimers() noexcept {
        while(!Memory::timerStack.empty()) {
            Memory::timerStack.pop();
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
