cmake_minimum_required(VERSION 2.8)

project(raytracing)
message(STATUS ">>> scene subdirectory")


set(RAYTRACING_SCENE_SRC scene.cpp)

set(RAYTRACING_SCENE_INCLUDES scene.h)

add_library(raytracing_scene SHARED ${RAYTRACING_SCENE_SRC} ${RAYTRACING_OBJECTS} ${RAYTRACING_CAMERA} ${OPENGL_GL_LIBRARY} ${GLUT_LIBRARY})

target_link_libraries(raytracing_scene raytracing_objects raytracing_camera ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})

install(FILES ${RAYTRACING_SCENE_INCLUDES} DESTINATION include)
