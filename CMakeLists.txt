project(raytracing)
cmake_minimum_required(VERSION 2.8)

find_package(OpenGL)
find_package(GLUT)
find_package (Eigen3 REQUIRED)
include_directories(EIGEN3_INCLUDE_DIR objects scene camera light raytracer)

add_subdirectory(objects)
add_subdirectory(scene)
add_subdirectory(camera)
add_subdirectory(light)
add_subdirectory(raytracer)

set(RAYTRACING_OBJECTS raytracing_objects)
set(RAYTRACING_SCENE raytracing_scene)
set(RAYTRACING_CAMERA raytracing_camera)
set(RAYTRACING_RAYTRACER raytracing_raytracer)
set(RAYTRACING_LIGHT raytracing_light)

add_executable(raytracing main.cpp)

find_library(RAYTRACING_OBJECTS NAMES raytracing_objects)
find_library(RAYTRACING_SCENE NAMES raytracing_scene)
find_library(RAYTRACING_CAMERA NAMES raytracing_camera)
find_library(RAYTRACING_LIGHT NAMES raytracing_light)
find_library(RAYTRACING_RAYTRACER NAMES raytracing_raytracer)


target_link_libraries(

    ${PROJECT_NAME}
    ${OPENGL_LIBRARIES}
    ${GLUT_LIBRARIES}
    ${RAYTRACING_OBJECTS}
    ${RAYTRACING_SCENE}
    ${RAYTRACING_CAMERA}
    ${RAYTRACING_LIGHT}
    ${RAYTRACING_RAYTRACER}
 )
