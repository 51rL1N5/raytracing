cmake_minimum_required(VERSION 2.8)

project(raytracing)
message(STATUS ">>> Camera subdirectory")



set(RAYTRACING_CAMERA_SRC camera.cpp)

set(RAYTRACING_CAMERA_INCLUDES camera.h)

add_library(raytracing_camera SHARED ${RAYTRACING_CAMERA_SRC} ${RAYTRACING_OBJECTS})

target_link_libraries(raytracing_camera raytracing_objects)

install(FILES ${RAYTRACING_CAMERA_INCLUDES} DESTINATION include)
