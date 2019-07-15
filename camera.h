#include "geometry.h"

#ifndef RASTERIZER_CAMERA_H
#define RASTERIZER_CAMERA_H

struct camera {
    Vec3 pos;
    Vec3 lookDir;

    camera() {
        pos = Vec3();
        lookDir = Vec3();
    }

    camera(Vec3 _pos, Vec3 _lookDir) {
        pos = _pos;
        lookDir = _lookDir;
    }
};

#endif //RASTERIZER_CAMERA_H
