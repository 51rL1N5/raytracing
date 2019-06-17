#include "light.h"

Light::Light()
{

}

void Light::setAmbientLightColor(Vector3f light_color = Vector3f(1, 1, 1))
{
    this->Ia = light_color;
}

void Light::setLightColor(Vector3f light_color = Vector3f(1, 1, 1))
{
    this->Il = light_color;
}

void Light::setLightPosition(Vector3f light_position)
{
    this->light_position = light_position;
}

void Light::setLightCoeff(float ka, float kd, float ks)
{
    this->ka = ka;
    this->kd = kd;
    this->ks = ks;
}

Vector3f Light::calculateLight()
{
    
}
