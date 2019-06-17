cmake_minimum_required(VERSION 2.8)

project(raytracing)
message(STATUS ">>> Objects subdirectory")



set(RAYTRACING_OBJECTS_SRC object.cpp sphere.cpp)

set(RAYTRACING_OBJECTS_INCLUDES object.h ray.h sphere.h color.h)

add_library(raytracing_objects SHARED ${RAYTRACING_OBJECTS_SRC})

target_link_libraries(raytracing_objects)

install(FILES ${RAYTRACING_OBJECTS_INCLUDES} DESTINATION include)
