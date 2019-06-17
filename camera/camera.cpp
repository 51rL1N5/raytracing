#include "camera.h"

#include <stdio.h>
#include <iostream>
#include <cmath>

using std::cout;
using std::endl;
float Window::x = 100;
float Window::y = 100;
float Window::znear = 1;
float Window::zfar = 100;

Window Camera::window = Window(640,480,100,100,1,300);

Window::Window(int width, int height, float x, float y, float znear, float zfar)
{
    cout<<"janela\n";
    this->height = height;
    this->width = width;
    this->Window::x = x;
    this->Window::y = y;
    this->Window::znear = znear; //this will be useful for zfar and znear
    this->Window::zfar = zfar;
}

Camera::Camera(Eigen::Vector3f pos, Eigen::Vector3f lookAt, Eigen::Vector3f normal, Window window_)
{
    std::cout<<"camera\n";
    this->Camera::pos = pos;
    this->Camera::lookAt = lookAt;
    this->Camera::normal = normal;

    this->window = window_;

    znear = window.znear;
    zfar = window.zfar;
}


Eigen::Vector3f Camera::toWorldPoint(Eigen::Vector3f windowPoint/*, int height*/)
{

    glLoadIdentity();


    GLint viewport[4];

    GLdouble mvmatrix[16], projmatrix[16];
    GLint realy;         /*  OpenGL y coordinate position  */
    GLdouble wx, wy, wz; /*  returned world x, y, z coords  */
    gluLookAt(0, 0, -5, 0,0, 0, 0, 1, 0); //placed at (0,0,5), aim at (0,0,0), normal vector (0,1,0)
    glGetIntegerv(GL_VIEWPORT, viewport);
    glGetDoublev(GL_MODELVIEW_MATRIX, mvmatrix);
    glGetDoublev(GL_PROJECTION_MATRIX, projmatrix);
    /*  note viewport[3] is height of window in pixels  */
    //realy = viewport[3] - (GLint) y - 1;
  //  realy = height - (GLint)windowPoint(1, 0) - 1;


    gluUnProject((GLdouble)windowPoint(0, 0), (GLdouble)realy, windowPoint(2, 0),
                 mvmatrix, projmatrix, viewport, &wx, &wy, &wz);

    return Eigen::Vector3f(wx, wy, wz);
}
