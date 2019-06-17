#include "light.h"
#include <cmath>

//using namespace Eigen;

Light::Light()
{

}

void Light::setAmbientLightColor(const Vector3f light_color = UNIT_VECTOR)
{
    this->Ia = light_color;
}

void Light::setLightColor(const Vector3f light_color = UNIT_VECTOR)
{
    this->Il = light_color;
}

void Light::setLightPosition(const Vector3f light_position)
{
    this->light_position = light_position;
}

void Light::setLightCoeff(const float ka, const float kd, const float ks, const float nshiny)
{
    this->ka = ka;
    this->kd = kd;
    this->ks = ks;
    this->nshiny = nshiny;
}

Vector3f Light::getReflectedRay(const Vector3f &ray, const Vector3f &normal)
{
    //Rr = 2N(Ri*N)-Ri;
    return 2 * normal * (ray.dot(normal)) - ray;
}

Vector3f Light::shade(const Ray ray, Object *object)
{
    Vector3f normal, n, intersection, L, R, O, obj_intersection;
    object->intersect(ray.Rd, normal, intersection);
    
    //Obtem direção da luz
    L = light_position-intersection;
    L.normalize();
    
    //Obtem raio do observador
    O = ray.Ro - intersection;
    
    //Verifica se há um objeto entre ponto de interseção e luz
    object->intersect(L, n, obj_intersection);
    if(intersection == Vector3f(0, 0, 0))
    {
        float obj_norm = (obj_intersection-intersection).norm();
        float light_norm = (light_position-intersection).norm();
        if(obj_norm < light_norm) return ka*Ia;
    }
    
    //Obtem raio refletido
    R = getReflectedRay(L, normal);    
    
    //Calcula e retorna luz
    return ka*Ia + fatt*Il*(kd*normal.dot(L) + ks*std::pow(R.dot(O), nshiny));   
    
    
}
