#include <algorithm>
#include <vector>
#include <fstream>
#include <string>
#include "utils.h"

#ifndef RASTERIZER_GEOMETRY_H
#define RASTERIZER_GEOMETRY_H

struct Vec2 {
    float x, y;

    Vec2() {}

    Vec2(float _x, float _y) {x = _x, y = _y;}

    Vec2 operator+(const Vec2 v) {
        return {x + v.x, y + v.y};
    }

    Vec2& operator+=(const Vec2 v) {
        this->x += v.x;
        this->y += v.y;
        return *this;
    }

    bool operator==(const Vec2 v) {
        return x == v.x && y == v.y;
    }

    bool operator!=(const Vec2 v) {
        return x != v.x || y != v.y;
    }
};

struct Vec3 {
    float x, y, z;

    Vec3() {
        x = y = z = 0;
    }

    Vec3(float _x, float _y, float _z) { x = _x, y = _y; z = _z; }

    float length() {
        return sqrt(x * x + y * y + z * z);
    }

    void normalize() {
        float l = length();
        if (l != 0) {
            x /= l;
            y /= l;
            z /= l;
        }
    }

    float dotProduct(const Vec3& v) {
        return x * v.x + y * v.y + z * v.z;
    }

    Vec3 crossProduct(const Vec3& v) {
        return {
            y * v.z - z * v.y,
            z * v.x - x * v.z,
            x * v.y - y * v.x
        };
    }

    Vec3 operator+(const Vec3 v) {
        return {x + v.x, y + v.y, z + v.z};
    }

    Vec3 operator-(const Vec3 v) {
        return {x - v.x, y - v.y, z - v.z};
    }

    Vec3 operator*(const float v) {
        return {x * v, y * v, z * v};
    }

    Vec3& operator+=(const Vec3 v) {
        this->x += v.x;
        this->y += v.y;
        this->z += v.z;
        return *this;
    }

    Vec3& operator+=(const float v) {
        this->x += v;
        this->y += v;
        this->z += v;

        return *this;
    }

    bool operator==(const Vec3 v) {
        return x == v.x && y == v.y && z == v.z;
    }

    bool operator!=(const Vec3 v) {
        return x != v.x || y != v.y || z != v.z;
    }
};

class Triangle2d {
public:
    Vec2 v[3];

    Triangle2d() {}

    Triangle2d(Vec2 _v0, Vec2 _v1, Vec2 _v2) {
        v[0] = _v0;
        v[1] = _v1;
        v[2] = _v2;
    }

    Triangle2d(Vec2 _v[3]) {
        v[0] = _v[0];
        v[1] = _v[1];
        v[2] = _v[2];
    }

    bool operator==(const Triangle2d t) {
        return v[0] == t.v[0] && v[1] == t.v[1] && v[2] == t.v[2];
    }

    bool operator!=(const Triangle2d t) {
        return v[0] != t.v[0] || v[1] != t.v[1] || v[2] != t.v[2];
    }
};

struct Triangle {
    Vec3 v[3];
    Triangle() {}

    Triangle(Vec3 _v0, Vec3 _v1, Vec3 _v2) {
        v[0] = _v0;
        v[1] = _v1;
        v[2] = _v2;
    }

    bool operator==(const Triangle t) {
        return v[0] == t.v[0] && v[1] == t.v[1] && v[2] == t.v[2];
    }

    bool operator!=(const Triangle t) {
        return v[0] != t.v[0] || v[1] != t.v[1] || v[2] != t.v[2];
    }

    Triangle2d toTriangle2d() {
        return {
                {v[0].x, v[0].y},
                {v[1].x, v[1].y},
                {v[2].x, v[2].y}
        };
    }
};

struct Plane {
    Vec3 point, normal;

    Plane() {}

    Plane(Vec3 _point, Vec3 _normal) {
        point = _point;
        normal = _normal;
    }
};

struct Mesh {
    std::vector<Triangle> tris;

    Mesh() {}

    Mesh(std::vector<Triangle> v) {
        tris.swap(v);
    }

    static Mesh loadFromFile(const char *filename) {
        std::ifstream obj(filename);
        if (!obj.is_open())
            return Mesh();

        Mesh ret;
        std::string line;
        std::vector<Vec3> vertices;

        while(std::getline(obj, line)) {
            if (line[0] == 'v') {
                // read a vertex
                std::vector <std::string> values = splitString(line, " ");
                float v0 = std::stof(values[1]);
                float v1 = std::stof(values[2]);
                float v2 = std::stof(values[3]);

                vertices.emplace_back(Vec3(v0, v1, v2));
            } else if (line[0] == 'f') {
                std::vector <std::string> values = splitString(line, " ");
                int v0 = std::stoi(values[1]);
                int v1 = std::stoi(values[2]);
                int v2 = std::stoi(values[3]);

                ret.tris.emplace_back(Triangle(vertices[v0 - 1], vertices[v1 - 1], vertices[v2 - 1]));
            }
        }

        obj.close();

        return ret;
    }
};

#endif //RASTERIZER_GEOMETRY_H
