#ifndef _RAYTRACER_H
#define _RAYTRACER_H
#include <iostream>
#include "scene.h"
#include "light.h"
#include "object.h"

#include <eigen3/Eigen/Dense>

using namespace Eigen;

class Raytracer
{
private:
    Scene scene;
    Light light;

public:
    void rayCasting();

    void display();

    void reshape(int w, int h);
};
#endif
