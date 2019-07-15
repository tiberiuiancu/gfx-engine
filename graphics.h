#include <math.h>
#include <algorithm>
#include <queue>

#include "mafs.h"
#include "wrapper.h"
#include "colors.h"
#include "geometry.h"
#include "camera.h"

#ifndef RASTERIZER_GRAPHICS_H
#define RASTERIZER_GRAPHICS_H

extern Mesh cube;
extern camera globalCamera;

void drawLine(Vec2 v0, Vec2 v1, RGBColor c);
void drawXMajorLine(Vec2 v0, Vec2 v1, RGBColor c);
void drawYMajorLine(Vec2 v0, Vec2 v1, RGBColor c);

void drawMeshTriangle(Triangle2d t, RGBColor c = WHITE);

//void drawTriangle(Triangle2d t, RGBColor c = WHITE);
//void drawFlatTopTriangle(Triangle2d t, RGBColor c);
//void drawFlatBottomTriangle(Triangle2d t, RGBColor c);

void drawTriangle(Triangle2d t, Triangle tri, RGBColor c = WHITE);
void drawFlatTopTriangle(Triangle2d t, Triangle tri, RGBColor c);
void drawFlatBottomTriangle(Triangle2d t, Triangle tri, RGBColor c);

Triangle toViewSpace(Triangle, float m[4][4]);

Vec2 project(Vec3);
Triangle2d project(Triangle t);
Triangle project3d(Triangle t);
std::vector<Triangle> clip(Triangle t, Plane p);
std::vector<Triangle> clip(const std::vector<Triangle> &tris, Plane p);

Triangle2d scaleIntoView(Triangle2d t, int W, int H);

void renderTriangle(Triangle t, float m[4][4], int width, int height);

Triangle translate(Triangle t, Vec3 amt);

Triangle rotate(Triangle t, float a0, float a1, float a2);
Triangle rotateAboutX(Triangle t, float a);
Triangle rotateAboutY(Triangle t, float a);
Triangle rotateAboutZ(Triangle t, float a);
Vec3 rotate(Vec3 v, float a0, float a1, float a2);
Vec3 rotateAboutX(Vec3 v, float a);
Vec3 rotateAboutY(Vec3 v, float a);
Vec3 rotateAboutZ(Vec3 v, float a);

bool isVisible(Triangle t, Vec3 camera);

#endif //RASTERIZER_GRAPHICS_H
