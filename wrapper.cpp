#include "wrapper.h"

RGBColor *colorBuffer;
float *depthBuffer;
int W, H, framerate;

float fNear = 0.1f;
float fFar = 1000.0f;
float fFov = 90.0f;
float fAspectRatio;
float fFovRad;
float matProj[4][4] = { 0 };

void reshape(int,int);
void timer(int);

void putPixel(int x, int y, RGBColor c) {
    // check that the pixel is on screen
    if (x >= W || y >= H || x < 0 || y < 0) return;


    colorBuffer[W * y + x].r = c.r;
    colorBuffer[W * y + x].g = c.g;
    colorBuffer[W * y + x].b = c.b;
}

void putPixel(int x, int y, float z, RGBColor c) {
    // check that the pixel is on screen
    if (x >= W || y >= H || x < 0 || y < 0) return;

    int location = W * y + x;

    if (depthBuffer[location] == 0 || depthBuffer[location] > z) {
//    if (depthBuffer[location] == 0) {
        colorBuffer[location] = c;
        depthBuffer[location] = z;
    }
}

void initOpenGL(
        int _W,
        int _H,
        int argc,
        char **argv,
        int _framerate) {

    W = _W;
    H = _H;
    framerate = _framerate;
    fAspectRatio = (float)W / (float)H;

    unsigned int displayModeFlags = GLUT_DOUBLE | GLUT_RGB;

    glutInit(&argc, argv);
    glutInitDisplayMode(displayModeFlags);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(W, H);
    glutCreateWindow("Rasterizer");

    glViewport(0, 0, W, H);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluOrtho2D(0, W, 0, H);
    glClearColor(0.0, 0.0, 0.0, 1.0);

    glutDisplayFunc(render);
//    glutTimerFunc(1000/framerate, timer, 0);
//    glutReshapeFunc(reshape);

    // allocate buffer memory
    colorBuffer = new RGBColor[W * H];
    depthBuffer = new float[W * H];


    // initialize projection matrix
    getProjectionMatrix(matProj, W, H, fNear, fFar, fFov);
}


void render() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glDrawPixels(W, H, GL_RGB, GL_FLOAT, colorBuffer);
    glutSwapBuffers();

    // clear buffer
    memset(colorBuffer, 0, sizeof(float) * W * H * 3);
    memset(depthBuffer, 0, sizeof(float) * W * H);
}


void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluOrtho2D(0, w, 0, h);
}

void timer(int) {
    glutPostRedisplay();
    glutTimerFunc(1000/framerate, timer, 0);
}