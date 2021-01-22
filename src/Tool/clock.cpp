#include "clock.h"
#include <ctime>
#include <iostream>
using namespace std;
Clock::Clock()
    : _info("")
    , _cut(0)
    // , _startFlag(false)
    , _usedTime(0)

{
}
Clock::Clock(const std::string& info)
    : _info(info)
    , _cut(0)
    // , _startFlag(false)
    , _usedTime(0)

{
}
void Clock::start()
{
    _startTime = std::chrono::steady_clock::now();
}
void Clock::end()
{
    _cut++;
    _endTime = std::chrono::steady_clock::now();
    _usedTime += std::chrono::duration_cast<std::chrono::microseconds>(_endTime - _startTime);
}
std::string Clock::getTime() const
{
    std::string ret = "";
    unsigned long long allus = _usedTime.count();
    const unsigned long long us = allus % 1000;
    allus /= 1000;
    const unsigned long long ms = allus % 1000;
    allus /= 1000;
    const unsigned long long s = allus % 60;
    allus /= 60;
    const unsigned long long m = allus % 60;
    allus /= 60;
    const unsigned long long h = allus % 60;
    ret = _info + " 用时:" + to_string(h) + "h" + to_string(m) + "m" + to_string(s)
        + "s" + to_string(ms) + "ms." + to_string(us) + "次数" + to_string(_cut);
    return ret;
}
