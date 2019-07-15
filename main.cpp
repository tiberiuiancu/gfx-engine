#include <iostream>
#include <unistd.h>
#include <cstdlib>

#include "wrapper.h"
#include "colors.h"
#include "graphics.h"
#include "utils.h"
#include "mafs.h"
#include "geometry.h"

#define SECOND 1000 * 1000

int fps = 60;
int width = 600;
int height = 600;

int main(int argc, char** argv) {

    initOpenGL(width, height, argc, argv, fps);

    const char* filename = "../assets/monky.obj";
    Mesh m = Mesh::loadFromFile(filename);

//    Mesh m = cube;

    int frames = 0;
    Timer t = Timer();
    t.start();
    for (int i = 0; i < 2; ++i) {
        for (float cnt = 0.0f; cnt < 4.0f; cnt += 0.005f) {
            float rotateAmt = (float)t.stop() / 1000;

            // TODO: clean code above for
            globalCamera.pos = {0, 0, cnt};
            globalCamera.lookDir = {0, 0, 1};
            Vec3 up = {0, 1, 0};
            Vec3 target = globalCamera.pos + globalCamera.lookDir;

            float matCamera[4][4]; getPointAtMatrix(matCamera, globalCamera.pos, target, up);
            float matView[4][4]; getLookAtMatrix(matView, matCamera);

            for (auto tri: m.tris) {
                Triangle cpy = tri;
                cpy = rotate(cpy, 0, 0, 0);
                cpy = translate(cpy, {0, 0, 2});

                if (isVisible(cpy, globalCamera.pos)) {
                    renderTriangle(cpy, matView, width, height);
                }
            }

            frames++;
            render();
        }
    }

    std::cout << (float)frames / t.stop() * 1000;
    return 0;
}

