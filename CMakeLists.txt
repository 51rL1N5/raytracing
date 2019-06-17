project(raytracing)
cmake_minimum_required(VERSION 2.8)

find_package(OpenGL)
find_package(GLUT)
find_package (Eigen3 REQUIRED)
include_directories(EIGEN3_INCLUDE_DIR)

add_subdirectory(objects)
add_subdirectory(scene)
add_subdirectory(light)
add_subdirectory(camera)

add_executable(raytracing main.cpp)

find_library(RAYTRACING_OBJECTS NAMES raytracing_objects)
find_library(RAYTRACING_SCENE NAMES raytracing_scene)

target_link_libraries(

    ${PROJECT_NAME}
    ${OPENGL_LIBRARIES}
    ${GLUT_LIBRARIES}
    ${RAYTRACING_OBJECTS}
    ${RAYTRACING_SCENE}

 )
