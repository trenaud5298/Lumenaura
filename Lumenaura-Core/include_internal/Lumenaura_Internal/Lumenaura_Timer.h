#ifndef LUMENAURA_TIMER_H
#define LUMENAURA_TIMER_H

#include <chrono>

namespace Lumenaura::Timer {

    void startTimer() noexcept;

    template <typename DurationType = std::chrono::milliseconds>
    long long stopTimer() noexcept;

    template <typename DurationType = std::chrono::milliseconds>
    long long peekTimer() noexcept;

    template <typename DurationType = std::chrono::milliseconds>
    long long timeElapsedSinceProgramStart() noexcept;

    void clearTimers() noexcept;

}

#endif