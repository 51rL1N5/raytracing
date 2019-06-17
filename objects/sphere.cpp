#include "sphere.h"
#include <cmath>

#define NULL_VECTOR Eigen::Vector3f(0,0,0)

Sphere::Sphere()
{}

void Sphere::setSphere(Eigen::Vector3f center, float radius, float kd, float ks)
{
  this->center          = center;
  this->radius          = radius;
  this->material.kd     = kd;
  this->material.ks     = ks;
}

void Sphere::intersect(const Ray ray, Eigen::Vector3f & intersection, Eigen::Vector3f & normal)
{
  float B, C;

  B  = 2 * ( ray.Rd(0)*(ray.Ro(0) - center(0)) + ray.Rd(1)*(ray.Ro(1) - center(1)) + ray.Rd(2)*(ray.Ro(2) - center(2)));

  C  = (ray.Ro(0) - center(0)) * (ray.Ro(0) - center(0)) + (ray.Ro(1) - center(1)) * (ray.Ro(1) - center(1)) + (ray.Ro(2) - center(2)) * (ray.Ro(2) - center(2)) - radius*radius;

  float delta = B*B - 4*C;

  if (delta < 0)
  {
    intersection = NULL_VECTOR;
    normal = NULL_VECTOR;
  }
  else
  {
    float t1 = (-B + sqrt(delta))/2;
    float t2 = (-B - sqrt(delta))/2;

    intersection = std::min(t1,t2)*ray.Rd + ray.Ro;

    normal = intersection - center;
  }

}
