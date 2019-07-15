#ifndef RASTERIZER_COLORS_H
#define RASTERIZER_COLORS_H

#include "utils.h"

struct RGBColor {
    float r, g, b;

    RGBColor () {
        r = 0;
        g = 0;
        b = 0;
    }

    RGBColor (float _r, float _g, float _b){
        r = _r;
        g = _g;
        b = _b;
    }

    static RGBColor randomColor() {
        return {
            Random::rand(),
            Random::rand(),
            Random::rand()
        };
    }
};

#define RED RGBColor(1, 0, 0)
#define GREEN RGBColor(0, 1, 0)
#define BLUE RGBColor(0, 0, 1)
#define YELLOW RGBColor(1, 1, 0)
#define BLACK RGBColor(0, 0, 0)
#define WHITE RGBColor(1, 1, 1)
#define GRAY RGBColor(128, 128, 128)
#define PURPLE RGBColor(128, 0, 128)
#define FUSCHIA RGBColor(255, 0, 255)

#endif //RASTERIZER_COLORS_H
