#ifndef _LIGHT_H
#define _LIGHT_H
#include <iostream>
#include <eigen3/Eigen/Dense>
#include

using namespace std;
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
    void setAmbientLightColor(Vector3f light_color = Vector3f(1, 1, 1));
    void setLightColor(Vector3f light_color = Vector3f(1, 1, 1));
    void setLightPosition(Vector3f light_position);
    void setLightCoeff(float ka, float kd, float ks);
    Vector3f calculateLight();
    void intersect(Vector3f rayDir, Object object);
    
}
#endif
