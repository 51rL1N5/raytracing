#include "light.h"
#include <cmath>

//using namespace Eigen;

Light::Light()
{

}

void Light::setAmbientLightColor(const Eigen::Vector3f light_color)
{
    this->Ia = light_color;
}

void Light::setLightColor(const Eigen::Vector3f light_color)
{
    this->Il = light_color;
}

void Light::setLightPosition(const Eigen::Vector3f light_position)
{
    this->light_position = light_position;
}

void Light::setLightCoeffs(const float ka, const float kd, const float ks, const float nshiny)
{
    this->ka = ka;
    this->kd = kd;
    this->ks = ks;
    this->nshiny = nshiny;
}

Eigen::Vector3f Light::shade(Ray ray, Object * object)
{
    Eigen::Vector3f normal, n, intersection, R, O, obj_intersection;

    object->intersect(ray, normal, intersection);

    //Obtem direção da luz
    Ray L(intersection, light_position);

    //Obtem raio do observador
    O = ray.Ro - intersection;

    //Verifica se há um objeto entre ponto de interseção e luz
    object->intersect(L, n, obj_intersection);

    if(intersection == Eigen::Vector3f(0, 0, 0))
    {
        float obj_norm = (obj_intersection-intersection).norm();
        float light_norm = (light_position-intersection).norm();
        if(obj_norm < light_norm) return ka*Ia;
    }

    fatt = 1/light_position.dot(intersection);

    //Obtem raio refletido
    R = 2 * normal * (ray.Rd.dot(normal)) - ray.Rd;

    //Calcula e retorna luz
    return ka*Ia + fatt*Il*(kd*normal.dot(L.Rd) + ks*std::pow(R.dot(O), nshiny));


}
