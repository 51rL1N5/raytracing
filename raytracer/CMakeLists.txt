cmake_minimum_required(VERSION 2.8)

project(raytracing)
message(STATUS ">>> Raytracing subdirectory")


set(RAYTRACING_RAYTRACER_SRC raytracer.cpp)

set(RAYTRACING_RAYTRACER_INCLUDES raytracer.h)

add_library(raytracing_raytracer SHARED ${RAYTRACING_RAYTRACER_SRC} ${RAYTRACING_SCENE} ${RAYTRACING_LIGHT} ${RAYTRACING_OBJECTS})

target_link_libraries(raytracing_raytracer raytracing_scene raytracing_light raytracing_objects)

install(FILES ${RAYTRACING_RAYTRACER_INCLUDES} DESTINATION include)
