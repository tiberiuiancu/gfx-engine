#include <math.h>
#include <algorithm>

#include "geometry.h"

#ifndef RASTERIZER_MAFS_H
#define RASTERIZER_MAFS_H

Vec3 matmul(float m[3][3], Vec3 v);
Vec3 matmul(float m[4][4], Vec3 v, bool use4d = false);
void matmul(float [3][3], float [3][3], float [3][3]);

bool intersects(Vec2, Vec2, float);
bool intersects(Vec2, Vec2, Vec2, Vec2);
Vec3 intersection(Vec3, Vec3, Plane);

float distance(Vec2, Vec2);
float distanceSquared(Vec2, Vec2);

float slope(Vec2, Vec2);
Vec3 getNormal(Triangle t);

void getProjectionMatrix(float m[4][4], int W, int H, float fNear, float fFar, float fFov);
void getPointAtMatrix(float m[4][4], Vec3 pos, Vec3 target, Vec3 up);
void getLookAtMatrix(float m[4][4], float pointAt[4][4]);

float degToRad(float);


#endif //RASTERIZER_MAFS_H
