#ifndef _RAYTRACING_H
#define _RAYTRACING_H
#include <iostream>
#include <../scene/scene.h>
#include <../light/light.h>
#include <../objects/objects.h>
#include<eigen3/Eingen/Dense>

using namespace Eigen;

class Raytracing
{
private:
    Scene scene;
    Light light;    

public:
    Raytracing();
};
#endif
