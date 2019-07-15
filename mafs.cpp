#include "mafs.h"

Vec3 matmul(float m[4][4], Vec3 v, bool use4d) {
    Vec3 out = Vec3();
    out.x = v.x * m[0][0] + v.y * m[1][0] + v.z * m[2][0] + m[3][0];
    out.y = v.x * m[0][1] + v.y * m[1][1] + v.z * m[2][1] + m[3][1];
    out.z = v.x * m[0][2] + v.y * m[1][2] + v.z * m[2][2] + m[3][2];

    if (use4d) {
        float w = v.x * m[0][3] + v.y * m[1][3] + v.z * m[2][3] + m[3][3];

        if (w != 0.0f) {
            out.x /= w;
            out.y /= w;
            out.z /= w;
        }
    }

    return out;
}

Vec3 matmul(float m[3][3], Vec3 v) {
    Vec3 out;
    out.x = v.x * m[0][0] + v.y * m[0][1] + v.z * m[0][2];
    out.y = v.x * m[1][0] + v.y * m[1][1] + v.z * m[1][2];
    out.z = v.x * m[2][0] + v.y * m[2][1] + v.z * m[2][2];

    return out;
}

void matmul(float m[3][3], float m0[3][3], float m1[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            m[i][j] = m0[i][0] * m1[0][j] + m0[i][1] * m1[1][j] + m0[i][2] * m1[2][j];
        }
    }
}

bool intersects(Vec2 v0, Vec2 v1, float m) {
    /*
     * checks if the line of slope m that passes through v0 also passes through v1
     * same as checks if the line v0 v1 has slope m
     */

    return m == slope(v0, v1);
}

bool intersects(Vec2 v0, Vec2 v1, Vec2 v2, Vec2 v3) {
    /*
     * checks if the segments v0 v1 and v2 v3 intersect
     */

    if (v0.x > v1.x) std::swap(v0, v1);
    if (v2.x > v3.x) std::swap(v2, v3);

    float m01 = slope(v0, v1);
    float m23 = slope(v2, v3);

    float n01 = v0.y - m01 * v0.x;
    float n23 = v2.y - m23 * v1.y;

    if (m01 == m23) {
        if (n01 != n23) // parallel
            return false;
        else {
            return (v0.x <= v2.x && v2.x <= v1.x) || (v2.x <= v0.x && v0.x <= v3.x);
        }
    }

    float xIntersect = (n23 - n01) / (m01 - m23);
    return (v0.x <= xIntersect <= v1.x) && (v2.x <= xIntersect <= v3.x);
}

Vec3 intersection(Vec3 A, Vec3 B, Plane p) {
    /*
     * return the point of intersection between the line v0v1 and plane p
     * !: does not check for parallel lines to the plane
     */

    float a = p.normal.x;
    float b = p.normal.y;
    float c = p.normal.z;
    float d = -p.point.dotProduct(p.normal);

    float t = - (a * A.x + b * A.y + c * A.z + d) / (a * (B.x - A.x) + b * (B.y - A.y) + c * (B.z - A.z));

    return {A + (B - A) * t};
}

float distance(Vec2 v0, Vec2 v1) {
    return sqrt(distanceSquared(v0, v1));
}

float distanceSquared(Vec2 v0, Vec2 v1) {
    return pow(v0.x - v1.x, 2) + pow(v0.y - v1.y, 2);
}

float slope(Vec2 v0, Vec2 v1) {
    /*
     * WARNING! NO 0 DEVIDE CHECKING!
     */
    return (v0.y - v1.y) / (v0.x - v1.x);
}

Vec3 getNormal(Triangle t) {

    Vec3 line1 = t.v[0] - t.v[1];
    Vec3 line2 = t.v[1] - t.v[2];
    Vec3 normal = line1.crossProduct(line2);
    normal.normalize();
    return normal;
}

void getProjectionMatrix(float m[4][4], int W, int H, float fNear, float fFar, float fFov) {

    float fAspectRatio = (float)W / (float)H;
    float fFovRad = 1.0f / tan(fFov * 0.5f / 180.0f * M_PI);
    m[0][0] = fAspectRatio * fFovRad;
    m[1][1] = fFovRad;
    m[2][2] = fFar / (fFar - fNear);
    m[3][2] = (-fFar * fNear) / (fFar - fNear);
    m[2][3] = 1.0f;
}

void getPointAtMatrix(float m[4][4], Vec3 pos, Vec3 target, Vec3 up) {

    // new forward direction
    Vec3 newForward = target - pos;
    newForward.normalize();

    // new up direction
    Vec3 a = newForward * up.dotProduct(newForward);
    Vec3 newUp = up - a;
    newUp.normalize();

    // new right direction
    Vec3 newRight = newUp.crossProduct(newForward);

    m[0][0] = newRight.x;    m[0][1] = newRight.y;    m[0][2] = newRight.z;    m[0][3] = 0.0f;
    m[1][0] = newUp.x;       m[1][1] = newUp.y;       m[1][2] = newUp.z;       m[1][3] = 0.0f;
    m[2][0] = newForward.x;  m[2][1] = newForward.y;  m[2][2] = newForward.z;  m[2][3] = 0.0f;
    m[3][0] = pos.x;         m[3][1] = pos.y;         m[3][2] = pos.z;         m[3][3] = 1.0f;
}

void getLookAtMatrix(float m[4][4], float pointAt[4][4]) {
    m[0][0] = pointAt[0][0]; m[0][1] = pointAt[1][0]; m[0][2] = pointAt[2][0]; m[0][3] = 0.0f;
    m[1][0] = pointAt[0][1]; m[1][1] = pointAt[1][1]; m[1][2] = pointAt[2][1]; m[1][3] = 0.0f;
    m[2][0] = pointAt[0][2]; m[2][1] = pointAt[1][2]; m[2][2] = pointAt[2][2]; m[2][3] = 0.0f;

    m[3][0] = -(pointAt[3][0] * m[0][0] + pointAt[3][1] * m[1][0] + pointAt[3][2] * m[2][0]);
    m[3][1] = -(pointAt[3][0] * m[0][1] + pointAt[3][1] * m[1][1] + pointAt[3][2] * m[2][1]);
    m[3][2] = -(pointAt[3][0] * m[0][2] + pointAt[3][1] * m[1][2] + pointAt[3][2] * m[2][2]);
    m[3][3] = 1.0f;
}

float degToRad(float deg) {
    return M_PI / 180 * deg;
}