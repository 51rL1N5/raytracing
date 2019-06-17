#ifndef _LIGHT_H
#define _LIGHT_H

#include <iostream>
#include <eigen3/Eigen/Dense>
#include "object.h"
#include "ray.h"
#define UNIT_VECTOR Eigen::Vector3f(1, 1, 1)

class Light
{
private:
    float ka, ks, kd, fatt, nshiny;
    Eigen::Vector3f light_position;
    Eigen::Vector3f Il;
    Eigen::Vector3f Ia;

public:
    Light();
    void setAmbientLightColor(const Eigen::Vector3f light_color = UNIT_VECTOR);
    void setLightColor(const Eigen::Vector3f light_color = UNIT_VECTOR);
    void setLightPosition(const Eigen::Vector3f light_position);
    void setLightCoeffs(const float ka, const float kd, const float ks, const float nshiny);
    Eigen::Vector3f getReflectedRay(Eigen::Vector3f ray, Eigen::Vector3f normal);
    Eigen::Vector3f shade(Ray rayDir, Object *object);
};

#endif // _LIGHT_H
