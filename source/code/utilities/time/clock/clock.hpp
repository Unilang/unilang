#pragma once

#include <chrono>

template<typename Clock_t = std::chrono::steady_clock>
class Clock
{
public:
    using TimePoint = decltype(Clock_t::now());
private:
    TimePoint m_start;
public:
    Clock() : m_start(Clock_t::now()) {

    }
    ~Clock() {

    }

    void reset() {
        m_start = Clock_t::now();
    }

    float getSeconds() const {
        return std::chrono::duration_cast<std::chrono::duration<float>>(Clock_t::now() - m_start).count();
    }

    long long getMilliseconds() const {
        return std::chrono::duration_cast<std::chrono::milliseconds>(Clock_t::now() - m_start).count();
    }
    long getMinutes() const {
        return std::chrono::duration_cast<std::chrono::minutes>(Clock_t::now() - m_start).count();
    }
};
