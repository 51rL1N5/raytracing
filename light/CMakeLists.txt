cmake_minimum_required(VERSION 2.8)

project(raytracing)
message(STATUS ">>> light subdirectory")



set(RAYTRACING_LIGHT_SRC light.cpp)

set(RAYTRACING_LIGHT_INCLUDES light.h)

add_library(raytracing_objects SHARED ${RAYTRACING_LIGHT_SRC})

target_link_libraries(raytracing_objects)

install(FILES ${RAYTRACING_LIGHT_INCLUDES} DESTINATION include)
