cmake_minimum_required(VERSION 2.8)

project(raytracing)
message(STATUS ">>> scene subdirectory")



set(RAYTRACING_SCENE_SRC scene.cpp)

set(RAYTRACING_SCENE_INCLUDES scene.h)

add_library(raytracing_objects SHARED ${RAYTRACING_SCENE_SRC})

target_link_libraries(raytracing_objects)

install(FILES ${RAYTRACING_SCENE_INCLUDES} DESTINATION include)
