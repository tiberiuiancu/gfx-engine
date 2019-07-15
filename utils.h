#include <chrono>
#include <stdlib.h>
#include <vector>
#include <string>

#ifndef RASTERIZER_UTILS_H
#define RASTERIZER_UTILS_H

class Timer {
private:
    int startTime;

public:
    void start();
    int stop();
    static unsigned long long getTime();
};

class Random {
public:
    static float rand() {
        return (float) std::rand() / RAND_MAX;
    }

    static float rand(float x, float y) {
        if (x >= y)
            return 0;
        return rand() * (y - x) + x;
    }
};

std::vector<std::string> splitString(const std::string&, const std::string&);
float clip(float n, float min, float max);

#endif //RASTERIZER_UTILS_H
