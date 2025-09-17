#pragma once

#include <chrono>

class Timer{
public:
    void start(std::chrono::minutes  custom_minutes);

    bool isRunning() const;

    std::chrono::seconds getTimeLeft() const;
    
private:
    std::chrono::time_point<std::chrono::steady_clock> m_endTime;
    bool m_isRunning = false;

};