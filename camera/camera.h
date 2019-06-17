#ifndef CAMERA_H
#define CAMERA_H

#include <eigen3/Eigen/Dense>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <vector>
#include <utility>


class Window
{
public:
    Window()
    {}

    Window(int width,int height,  float x, float y,float znear,float zfar);

    static  float x,y,znear,zfar;
    int height;
    int width;

};

class Camera
{
public:
    Eigen::Vector3f pos;
    Eigen::Vector3f lookAt;
    Eigen::Vector3f normal;
    float znear,zfar;
    static Window window;


    Camera(Eigen::Vector3f pos, Eigen::Vector3f lookAt, Eigen::Vector3f normal,Window window_);
    Eigen::Vector3f toWorldPoint(Eigen::Vector3f windowPoint/*, int height*/);


};

#endif // CAMERA_H
