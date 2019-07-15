#include "graphics.h"

Mesh cube = Mesh({
        // SOUTH
        { {0.0f, 0.0f, 0.0f},   {0.0f, 1.0f, 0.0f},   {1.0f, 1.0f, 0.0f} },
        { {0.0f, 0.0f, 0.0f},   {1.0f, 1.0f, 0.0f},   {1.0f, 0.0f, 0.0f} },

        // EAST
        { {1.0f, 0.0f, 0.0f},   {1.0f, 1.0f, 0.0f},   {1.0f, 1.0f, 1.0f} },
        { {1.0f, 0.0f, 0.0f},   {1.0f, 1.0f, 1.0f},   {1.0f, 0.0f, 1.0f} },

        // NORTH
        { {1.0f, 0.0f, 1.0f},   {1.0f, 1.0f, 1.0f},   {0.0f, 1.0f, 1.0f} },
        { {1.0f, 0.0f, 1.0f},   {0.0f, 1.0f, 1.0f},   {0.0f, 0.0f, 1.0f} },

        // WEST
        { {0.0f, 0.0f, 1.0f},   {0.0f, 1.0f, 1.0f},   {0.0f, 1.0f, 0.0f} },
        { {0.0f, 0.0f, 1.0f},   {0.0f, 1.0f, 0.0f},   {0.0f, 0.0f, 0.0f} },

        // TOP
        { {0.0f, 1.0f, 0.0f},   {0.0f, 1.0f, 1.0f},   {1.0f, 1.0f, 1.0f} },
        { {0.0f, 1.0f, 0.0f},   {1.0f, 1.0f, 1.0f},   {1.0f, 1.0f, 0.0f} },

        // BOTTOM
        { {1.0f, 0.0f, 1.0f},   {0.0f, 0.0f, 1.0f},   {0.0f, 0.0f, 0.0f} },
        { {1.0f, 0.0f, 1.0f},   {0.0f, 0.0f, 0.0f},   {1.0f, 0.0f, 0.0f} }
});

camera globalCamera = camera();

void drawLine(Vec2 v0, Vec2 v1, RGBColor c) {

    bool rightCorner;
    if (v0.x == v1.x) {  // vertical
        rightCorner = true;
    } else {
        float m = (v0.y - v1.y) / (v0.x - v1.x);
        rightCorner = !(-1.0f <= m && m <= 1.0f);
    }

    if (rightCorner)
        drawYMajorLine(v0, v1, c);
    else drawXMajorLine(v0, v1, c);

}

void drawXMajorLine(Vec2 v0, Vec2 v1, RGBColor c) {
    /*
     * lower-left edge
     * lower-right edge
     * bottom corner
     */

    // sort by x
    if (v0.x > v1.x) std::swap(v0, v1);

    // get the slope
    float m = slope(v0, v1);

    // move along the x axis
    int xStart = (int)ceil(v0.x - 0.5f);
    int xEnd = (int)ceil(v1.x - 0.5f);

    for (int x = xStart; x < xEnd; ++x) {
        // determine the y of the current pixel
        int y = (int)floor(v0.y + m * ((float)x - v0.x + 0.5f));

        Vec2 leftCorner = Vec2((float)x, (float)y + 0.5f);
        Vec2 bottomCorner = Vec2((float)x + 0.5f, (float)y);
        Vec2 rightCorner = Vec2((float)x + 1.0f, (float)y + 0.5f);

        if (intersects(bottomCorner, v0, m)) {
            putPixel(x, y, c);
        } else if (intersects(v0, v1, bottomCorner, rightCorner)) {
            putPixel(x, y, c);
        } else if (intersects(v0, v1, bottomCorner, leftCorner)) {
            putPixel(x, y, c);
        }
    }
}

void drawYMajorLine(Vec2 v0, Vec2 v1, RGBColor c) {
    /*
     * lower-left edge
     * lower-right edge
     * bottom corner
     * right corner
     */

    // sort by y
    if (v0.y > v1.y) std::swap(v0, v1);

    // get the inverse slope to avoid dividing by 0
    float m = (v0.x - v1.x) / (v0.y - v1.y);

    // move along the y axis
    int yStart = (int)ceil(v0.y - 0.5f);
    int yEnd = (int)ceil(v1.y - 0.5f);

    for (int y = yStart; y < yEnd; ++y) {
        // determine the x of the current pixel
        int x = (int)floor(v0.x + m * ((float)y - v0.y));

        Vec2 leftCorner = Vec2((float)x, (float)y + 0.5f);
        Vec2 bottomCorner = Vec2((float)x + 0.5f, (float)y);
        Vec2 rightCorner = Vec2((float)x + 1.0f, (float)y + 0.5f);

        if (intersects(bottomCorner, v0, m)) {
            putPixel(x, y, c);
        } else if (intersects(rightCorner, v0, m)) {
            putPixel(x, y, c);
        } else if (intersects(v0, v1, bottomCorner, rightCorner)) {
            putPixel(x, y, c);
        } else if (intersects(v0, v1, bottomCorner, leftCorner)) {
            putPixel(x, y, c);
        }
    }
}

void drawMeshTriangle(Triangle2d t, RGBColor c) {
    drawLine(t.v[0], t.v[1], c);
    drawLine(t.v[0], t.v[2], c);
    drawLine(t.v[1], t.v[2], c);
}

//void drawTriangle(Triangle2d t, RGBColor c) {
//    if (t.v[0].y == t.v[1].y) {
//        drawFlatBottomTriangle(t, c);
//    } else if (t.v[1].y == t.v[2].y) {
//        drawFlatTopTriangle(t, c);
//    } else {
//        Vec2 vi = Vec2(0, t.v[1].y);
//        if (t.v[0].x == t.v[2].x)
//            vi.x = t.v[0].x;
//        else {
//            vi.x = t.v[0].x + (t.v[1].y - t.v[0].y) * (t.v[2].x - t.v[0].x) / (t.v[2].y - t.v[0].y);
//        }
//
//        drawFlatTopTriangle(Triangle2d(t.v[0], t.v[1], vi), c);
//        drawFlatBottomTriangle(Triangle2d(t.v[1], vi, t.v[2]), c);
//    }
//}
//
//void drawFlatBottomTriangle(Triangle2d t, RGBColor c) {
//    // calculate the slopes of v0 v2, v1 v2
//    float m0 = (t.v[0].x - t.v[2].x) / (t.v[0].y - t.v[2].y);
//    float m1 = (t.v[1].x - t.v[2].x) / (t.v[1].y - t.v[2].y);
//
//    int yStart = ceil(t.v[0].y - 0.5f);
//    int yEnd = ceil(t.v[2].y - 0.5f);
//
//    for (int y = yStart; y < yEnd; ++y) {
//
//        int xStart = (int)ceil(m0 * (float(y) + 0.5f - t.v[0].y) + t.v[0].x - 0.5f);
//        int xEnd = (int)ceil(m1 * (float(y) + 0.5f - t.v[1].y) + t.v[1].x - 0.5f);
//
//        for (int x = xStart; x < xEnd; ++x) {
//            putPixel(x, y, c);
//        }
//    }
//}
//
//void drawFlatTopTriangle(Triangle2d t, RGBColor c) {
//
//    // calculate the slopes of v0 v1, v0 v2
//    float m0 = (t.v[0].x - t.v[1].x) / (t.v[0].y - t.v[1].y);
//    float m1 = (t.v[0].x - t.v[2].x) / (t.v[0].y - t.v[2].y);
//
//    int yStart = ceil(t.v[0].y - 0.5f);
//    int yEnd = ceil(t.v[1].y - 0.5f);
//
//    for (int y = yStart; y < yEnd; ++y) {
//
//        int xStart = (int)ceil(m0 * (float(y) + 0.5f - t.v[0].y) + t.v[0].x - 0.5f);
//        int xEnd = (int)ceil(m1 * (float(y) + 0.5f - t.v[0].y) + t.v[0].x - 0.5f);
//
//        for (int x = xStart; x < xEnd; ++x) {
//            putPixel(x, y, c);
//        }
//    }
//}

void drawTriangle(Triangle2d t, Triangle tri, RGBColor c) {

    // sort triangle vertices
    if (t.v[0].y > t.v[1].y) {
        std::swap(t.v[0], t.v[1]);
        std::swap(tri.v[0], tri.v[1]);
    }
    if (t.v[0].y > t.v[2].y) {
        std::swap(t.v[0], t.v[2]);
        std::swap(tri.v[0], tri.v[2]);
    }
    if (t.v[1].y > t.v[2].y) {
        std::swap(t.v[1], t.v[2]);
        std::swap(tri.v[1], tri.v[2]);
    }

    if (t.v[0].y == t.v[1].y && t.v[0].x > t.v[1].x) {
        std::swap(t.v[0], t.v[1]);
        std::swap(tri.v[0], tri.v[1]);
    }
    if (t.v[1].y == t.v[2].y && t.v[1].x > t.v[2].x) {
        std::swap(t.v[1], t.v[2]);
        std::swap(tri.v[1], tri.v[2]);
    }


    if (t.v[0].y == t.v[1].y) {
        drawFlatBottomTriangle(t, tri, c);
    } else if (t.v[1].y == t.v[2].y) {
        drawFlatTopTriangle(t, tri, c);
    } else {
        // split 2d triangle
        Vec2 vi = Vec2(0, t.v[1].y);
        vi.x = t.v[0].x + (t.v[1].y - t.v[0].y) * (t.v[2].x - t.v[0].x) / (t.v[2].y - t.v[0].y);

        // split 3d triangle
        Vec3 v0_v2_3d = tri.v[2] - tri.v[0];
        Vec3 vi_3d = tri.v[0] + v0_v2_3d * (distance(t.v[0], vi) / distance(t.v[0], t.v[2]));

        // sort v1 and vi
        if (t.v[1].x > vi.x) {
            std::swap(t.v[1], vi);
            std::swap(tri.v[1], vi_3d);
        }

        drawFlatTopTriangle( {t.v[0], t.v[1], vi}, {tri.v[0], tri.v[1], vi_3d}, c );
        drawFlatBottomTriangle( {t.v[1], vi, t.v[2]}, {tri.v[1], vi_3d, tri.v[2]}, c) ;
    }
}

void drawFlatBottomTriangle(Triangle2d t, Triangle tri, RGBColor c) {

    // calculate the slopes of v0 v2, v1 v2
    float m0 = (t.v[0].x - t.v[2].x) / (t.v[0].y - t.v[2].y);
    float m1 = (t.v[1].x - t.v[2].x) / (t.v[1].y - t.v[2].y);

    int yStart = ceil(t.v[0].y - 0.5f);
    int yEnd = ceil(t.v[2].y - 0.5f);

    Vec3 v2_v0_3d = tri.v[0] - tri.v[2];
    Vec3 v2_v1_3d = tri.v[1] - tri.v[2];

    for (int y = yStart; y < yEnd; ++y) {

        int xStart = (int)ceil(m0 * (float(y) + 0.5f - t.v[0].y) + t.v[0].x - 0.5f);
        int xEnd = (int)ceil(m1 * (float(y) + 0.5f - t.v[1].y) + t.v[1].x - 0.5f);

        Vec3 horizontal_3d_start = tri.v[2] + v2_v0_3d * (distance(t.v[2], {(float)xStart, (float)y}) / distance(t.v[2], t.v[0]));
        Vec3 horizontal_3d_end = tri.v[2] + v2_v1_3d * (distance(t.v[2], {(float)xEnd, (float)y}) / distance(t.v[2], t.v[1]));
        Vec3 start_end_3d = horizontal_3d_end - horizontal_3d_start;

        for (int x = xStart; x < xEnd; ++x) {

            Vec3 currentPixel3dEquivalent = horizontal_3d_start + start_end_3d * ((float)(x - xStart) / (float)(xEnd - xStart));
            float zValue = currentPixel3dEquivalent.z;

            putPixel(x, y, zValue, c);
        }
    }
}

void drawFlatTopTriangle(Triangle2d t, Triangle tri, RGBColor c) {

    // calculate the slopes of v0 v1, v0 v2
    float m0 = (t.v[0].x - t.v[1].x) / (t.v[0].y - t.v[1].y);
    float m1 = (t.v[0].x - t.v[2].x) / (t.v[0].y - t.v[2].y);

    int yStart = ceil(t.v[0].y - 0.5f);
    int yEnd = ceil(t.v[1].y - 0.5f);

    Vec3 v0_v1_3d = tri.v[1] - tri.v[0];
    Vec3 v0_v2_3d = tri.v[2] - tri.v[0];

    for (int y = yStart; y < yEnd; ++y) {

        int xStart = (int)ceil(m0 * (float(y) + 0.5f - t.v[0].y) + t.v[0].x - 0.5f);
        int xEnd = (int)ceil(m1 * (float(y) + 0.5f - t.v[0].y) + t.v[0].x - 0.5f);

        Vec3 horizontal_3d_start = tri.v[0] + v0_v1_3d * (distance(t.v[0], {(float)xStart, (float)y}) / distance(t.v[0], t.v[1]));
        Vec3 horizontal_3d_end = tri.v[0] + v0_v2_3d * (distance(t.v[0], {(float)xEnd, (float)y}) / distance(t.v[0], t.v[2]));
        Vec3 start_end_3d = horizontal_3d_end - horizontal_3d_start;

        for (int x = xStart; x < xEnd; ++x) {
            Vec3 currentPixel3dEquivalent = horizontal_3d_start + start_end_3d * ((float)(x - xStart) / (float)(xEnd - xStart));
            float zValue = currentPixel3dEquivalent.z;

            putPixel(x, y, zValue, c);
        }
    }
}


Triangle toViewSpace(Triangle t, float m[4][4]) {
    return {
        matmul(m, t.v[0]),
        matmul(m, t.v[1]),
        matmul(m, t.v[2])
    };
}

Vec2 project(Vec3 v) {
    Vec3 aux = matmul(matProj, v, true);
    return {aux.x, aux.y};
}

Triangle2d project(Triangle t) {
    Vec2 v0 = project(t.v[0]);
    Vec2 v1 = project(t.v[1]);
    Vec2 v2 = project(t.v[2]);

    return {v0, v1, v2};
}

Triangle project3d(Triangle t) {
    Triangle2d projected = project(t);
    return {
        { projected.v[0].x, projected.v[0].y, t.v[0].z },
        { projected.v[1].x, projected.v[1].y, t.v[1].z },
        { projected.v[2].x, projected.v[2].y, t.v[2].z }
    };
}

Triangle2d scaleIntoView(Triangle2d t, int W, int H) {
    t.v[0].x += 1.0f; t.v[0].y += 1.0f;
    t.v[1].x += 1.0f; t.v[1].y += 1.0f;
    t.v[2].x += 1.0f; t.v[2].y += 1.0f;

    t.v[0].x *= 0.5f * (float)W; t.v[0].y *= 0.5f * (float)H;
    t.v[1].x *= 0.5f * (float)W; t.v[1].y *= 0.5f * (float)H;
    t.v[2].x *= 0.5f * (float)W; t.v[2].y *= 0.5f * (float)H;

    return t;
}

void renderTriangle(Triangle t, float matView[4][4], int width, int height) {

    t = toViewSpace(t, matView);

    Triangle right = { {1, 0, 0}, {1, 0, 1}, {1, 1, 0} };
    Triangle left = { {-1, 0, 0}, {-1, 0, 1}, {-1, 1, 0} };
    Triangle up = { {0, 1, 0}, {1, 1, 0}, {0, 1, 1} };
    Triangle down = { {0, -1, 0}, {1, -1, 0}, {0, -1, 1} };

    Plane cameraPlane = Plane( {0, 0, 0.1f}, {0, 0, 1} );
    Plane rightPlane = Plane( {1, 0, 0}, getNormal(right) );
    Plane upPlane = Plane( {0, 1, 0}, getNormal(up) );
    Plane leftPlane = Plane( {-1, 0, 0}, Vec3(0, 0, 0) - getNormal(left) );
    Plane downPlane = Plane( {0, -1, 0}, Vec3(0, 0, 0) - getNormal(down) );

    // clip against the camera plane
    std::vector<Triangle> triangles = clip(t, cameraPlane);

    for (auto triangle : triangles) {

        drawTriangle(scaleIntoView(project(triangle), width, height), triangle);
//        drawMeshTriangle(scaleIntoView(project(triangle), width, height), BLACK);
    }

    // TODO: clipping

//    for (auto triangle:triangles) {
//        Triangle projected = project3d(triangle);
//
//        // clip against the screen edges
//        std::vector <Triangle> clippedTriangles = { projected };
//        clippedTriangles = clip(clippedTriangles, rightPlane);
//        clippedTriangles = clip(clippedTriangles, leftPlane);
//        clippedTriangles = clip(clippedTriangles, upPlane);
//        clippedTriangles = clip(clippedTriangles, downPlane);
//
//        for (auto clippedTriangle: clippedTriangles) {
//            drawTriangle(scaleIntoView(clippedTriangle.toTriangle2d(), width, height), clippedTriangle, RGBColor::randomColor());
//            drawMeshTriangle(scaleIntoView(clippedTriangle.toTriangle2d(), width, height), BLACK);
//        }
//    }
}

std::vector<Triangle> clip(Triangle t, Plane p) {

    std::vector<Triangle> v;

    p.normal.normalize();

    float d = -p.point.dotProduct(p.normal);

    float sign0 = t.v[0].dotProduct(p.normal) + d;
    float sign1 = t.v[1].dotProduct(p.normal) + d;
    float sign2 = t.v[2].dotProduct(p.normal) + d;

    if (sign0 < 0 && sign1 < 0 && sign2 < 0) {
        // all points are on invisible side of the plane
        return {}; // delete
    } else if (sign0 > 0 && sign1 > 0 && sign2 > 0) {
        // all points are on the visible side of the plane
        v.emplace_back(t);
    } else if (sign0 * sign1 * sign2 > 0) {
        // one point is on the visible part of the plane
        if (sign1 > 0)      std::swap(t.v[0], t.v[1]);
        else if (sign2 > 0) std::swap(t.v[0], t.v[2]);


        v.emplace_back( Triangle({0, 0, 0}, {0, 0, 0}, {0, 0, 0}) );
        v.emplace_back( Triangle(t.v[0], intersection(t.v[0], t.v[1], p), intersection(t.v[0], t.v[2], p)) );
    } else if (sign0 * sign1 * sign2 < 0) {
        if (sign1 < 0)      std::swap(t.v[0], t.v[1]);
        else if (sign2 < 0) std::swap(t.v[0], t.v[2]);

        Vec3 i0 = intersection(t.v[0], t.v[1], p);
        Vec3 i1 = intersection(t.v[0], t.v[2], p);

        Triangle t1(t.v[1], i0, t.v[2]);
        Triangle t2(t.v[2], i0, i1);

        v.emplace_back( Triangle({1, 1, 1}, {1, 1, 1}, {1, 1, 1}) );
        v.emplace_back(t1);
        v.emplace_back(t2);
    }

    return v;
}

std::vector<Triangle> clip(const std::vector<Triangle> &tris, Plane p) {

    std::vector<Triangle> v;

    p.normal.normalize();

    float d = -p.point.dotProduct(p.normal);

    for (auto t: tris) {
        float sign0 = t.v[0].dotProduct(p.normal) + d;
        float sign1 = t.v[1].dotProduct(p.normal) + d;
        float sign2 = t.v[2].dotProduct(p.normal) + d;

        if (sign0 < 0 && sign1 < 0 && sign2 < 0) {
            // all points are on invisible side of the plane
            return {}; // delete
        } else if (sign0 > 0 && sign1 > 0 && sign2 > 0) {
            // all points are on the visible side of the plane
            v.emplace_back(t);
        } else if (sign0 * sign1 * sign2 > 0) {
            // one point is on the visible part of the plane
            if (sign1 > 0) std::swap(t.v[0], t.v[1]);
            else if (sign2 > 0) std::swap(t.v[0], t.v[2]);


            v.emplace_back(Triangle({0, 0, 0}, {0, 0, 0}, {0, 0, 0}));
            v.emplace_back(Triangle(t.v[0], intersection(t.v[0], t.v[1], p), intersection(t.v[0], t.v[2], p)));
        } else if (sign0 * sign1 * sign2 < 0) {
            if (sign1 < 0) std::swap(t.v[0], t.v[1]);
            else if (sign2 < 0) std::swap(t.v[0], t.v[2]);

            Vec3 i0 = intersection(t.v[0], t.v[1], p);
            Vec3 i1 = intersection(t.v[0], t.v[2], p);

            Triangle t1(t.v[1], i0, t.v[2]);
            Triangle t2(t.v[2], i0, i1);

            v.emplace_back(Triangle({1, 1, 1}, {1, 1, 1}, {1, 1, 1}));
            v.emplace_back(t1);
            v.emplace_back(t2);
        }
    }

    return v;
}

Triangle translate(Triangle t, Vec3 amt) {
    return {t.v[0] + amt, t.v[1] + amt, t.v[2] + amt};
}

Triangle rotate(Triangle t, float a0, float a1, float a2) {
    return {rotate(t.v[0], a0, a1, a2), rotate(t.v[1], a0, a1, a2), rotate(t.v[2], a0, a1, a2)};
}

Vec3 rotate(Vec3 v, float a0, float a1, float a2) {

    float c0 = cos(a0);
    float c1 = cos(a1);
    float c2 = cos(a2);
    float s0 = sin(a0);
    float s1 = sin(a1);
    float s2 = sin(a2);

    float rot[3][3] = {
            {c1*c2, -s2*c0 + s0*s1*c2, s0*s2 + c0*s1*c2},
            {c1*s2, c0*c2 + s0*s1*s2, -s0*c2 + c0*s1*s2},
            {-s1, s0*c1, c0*c1}
    };

    return matmul(rot, v);

//
//    float rot[3][3] = {
//            {c0*c1, -s0*c2 + c0*s1*s2, s0*s2 + c0*s1*c2},
//            {s0*c1, c0*c2 + s0*s1*s2, -c0*s2 + s0*s1*c2},
//            {-s1, c1*s2, c1*c2}
//    };
//
//    return matmul(rot, v);

//    float rotX[3][3] = { {1, 0, 0},
//                         {0, cosf(a0), -sinf(a0)},
//                         {0, sinf(a0), cosf(a0)}};
//
//    float rotY[3][3] = { {cosf(a1), 0, sinf(a1)  },
//                         {0, 1, 0},
//                         {-sinf(a1), 0, cosf(a1)}};
//
//    float rotZ[3][3] = { {cosf(a2), -sinf(a2), 0},
//                         {sinf(a2),  cosf(a2), 0},
//                         {0, 0, 0}};

//    float rotXY[3][3] = { 0 };
//    float rot[3][3] = { 0 };
//
//    matmul(rotXY, rotZ, rotY);
//    matmul(rot, rotXY, rotX);
//    return matmul(rot, v);

//    return matmul(rotY, matmul(rotX, matmul(rotZ, v)));
}

bool isVisible(Triangle t, Vec3 camera) {
    Vec3 normal = getNormal(t);
    float flag = normal.x * (t.v[0].x - camera.x) + normal.y * (t.v[0].y - camera.y) + normal.z * (t.v[0].z - camera.z);
    return flag < 0;
}


