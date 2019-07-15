#include "utils.h"

void Timer::start() {
    startTime = getTime();
}

int Timer::stop() {
    return getTime() - startTime;
}

unsigned long long Timer::getTime() {
    return (unsigned long long)std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

std::vector<std::string> splitString(const std::string &s, const std::string &delimiter) {

    size_t lastPos = 0;
    size_t pos = 0;
    std::vector<std::string> res;

    pos = s.find(delimiter, lastPos);
    while (pos != std::string::npos) {
        res.push_back(s.substr(lastPos, pos - lastPos));
        lastPos = pos + delimiter.length();
        pos = s.find(delimiter, lastPos);
    }

    res.push_back(s.substr(lastPos));
    return res;
}

float clip(float n, float min, float max) {
    if (n < min) return min;
    if (n > max) return max;
    return n;
}

