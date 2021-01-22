#ifndef __CLOCK__
#define __CLOCK__
#include <chrono>
#include <iostream>
#include <string>
class Clock {
private:
    const std::string _info;
    unsigned int _cut;
    // bool _startFlag;
    std::chrono::steady_clock::time_point _startTime;
    std::chrono::steady_clock::time_point _endTime;
    std::chrono::microseconds _usedTime;
public:
    Clock();
    Clock(const std::string& info);
    void start();
    void end();
    std::string getTime() const;
};

#endif /*CLOCK*/