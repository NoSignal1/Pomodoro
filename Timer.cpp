#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>
#include "Timer.hpp"

using namespace std::chrono_literals;
using namespace std::chrono;

void Timer::start(std::chrono::minutes  duration){

    const auto end_time = steady_clock::now() + duration;

    m_endTime = steady_clock::now() + duration;
    m_isRunning = true;
}

bool Timer::isRunning() const{

    return m_isRunning && steady_clock::now() < m_endTime;
}

std::chrono::seconds Timer::getTimeLeft() const{
    if(!isRunning()){
        return seconds(0);
    }
    return duration_cast<seconds>(m_endTime - steady_clock::now());
}