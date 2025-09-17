#include <iostream>
#include <iomanip>
#include <thread>
#include "Timer.hpp"

using namespace std::chrono;
int main(){
    Timer pomodoroTimer;

    std::cout<< "60 sec laikmatis"<<std::endl;

    pomodoroTimer.start(std::chrono::minutes(1));

    while(pomodoroTimer.isRunning()){
        auto timeLeft = pomodoroTimer.getTimeLeft();

        const auto mins = duration_cast<minutes>(timeLeft);
        const auto secs = duration_cast<seconds>(timeLeft - mins);

        std::cout << "\rLiko laiko: " 
                  << std::setfill('0') << std::setw(2) << mins.count() << ":"
                  << std::setfill('0') << std::setw(2) << secs.count() << "   " 
                  << std::flush;

        std::this_thread::sleep_for(std::chrono::microseconds(100));
    }

    std::cout << "\nLaikas baigesi!" << std::endl;

    return 0;
}