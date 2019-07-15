cmake_minimum_required(VERSION 3.13)
project(rasterizer)

find_package(GLUT REQUIRED)
find_package(OpenGL REQUIRED)

set(CMAKE_CXX_STANDARD 14)

add_executable(rasterizer main.cpp wrapper.cpp wrapper.h graphics.cpp graphics.h colors.h utils.cpp utils.h mafs.cpp mafs.h geometry.h camera.h)

target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})