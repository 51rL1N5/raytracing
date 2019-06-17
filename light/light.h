#ifndef _LIGHT_H
#define _LIGHT_H
#include <iostream>
#include <eigen3/Eigen/Dense>
#include <../objects/objects.h>
#include <../objects/ray.h>
#define UNIT_VECTOR Eigen::Vector3f(1, 1, 1)

//using namespace std;
using namespace Eigen;

Class Light
{
private:
    float ka, ks, kd, fatt, nshiny;
    Vector3f light_position;
    Vector3f Il;
    Vector3f Ia;
    
public:
    Light();
    void setAmbientLightColor(const Vector3f light_color = UNIT_VECTOR);
    void setLightColor(const Vector3f light_color = UNIT_VECTOR);
    void setLightPosition(const Vector3f light_position);
    void setLightCoeffs(const float ka, const float kd, const float ks, const float nshiny);
    Vector3f getReflectedRay(const Vector3f &ray, const Vector3f &normal);
    Vector3f shade(const Vector3f rayDir, const Object *object);    
}
#endif
