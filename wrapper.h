#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>
#include <math.h>
#include <string.h>

#include "colors.h"
#include "mafs.h"
#include "geometry.h"

#ifndef RASTERIZER_WRAPPER_H
#define RASTERIZER_WRAPPER_H

extern float fNear;
extern float fFar;
extern float fFov;
extern float fAspectRatio;
extern float fFovRad;
extern float matProj[4][4];

void initOpenGL(
        int _W,
        int _H,
        int argc,
        char **argv,
        int _framerate = 60);


void putPixel(int x, int y, RGBColor c);
void putPixel(int x, int y, float z, RGBColor c);

void render();

#endif //RASTERIZER_WRAPPER_H
