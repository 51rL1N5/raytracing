cmake_minimum_required(VERSION 2.8)

project(raytracing)
message(STATUS ">>> scene subdirectory")



set(RAYTRACING_SCENE_SRC scene.cpp)

set(RAYTRACING_SCENE_INCLUDES scene.h)

add_library(raytracing_scene SHARED ${RAYTRACING_SCENE_SRC})

target_link_libraries(raytracing_scene)

install(FILES ${RAYTRACING_SCENE_INCLUDES} DESTINATION include)
