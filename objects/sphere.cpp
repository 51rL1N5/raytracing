#include "sphere.h"
#include <cmath>
#include <iostream>
#define NULL_VECTOR Eigen::Vector3f(0,0,0)

Sphere::Sphere()
{ }

void Sphere::setSphere(Eigen::Vector3f center_, float radius_, float kd, float ks)
{

  center          = center_;
  radius          = radius_;
  material.kd     = kd;
  material.ks     = ks;
}

void Sphere::intersect(const Ray ray, Eigen::Vector3f & intersection, Eigen::Vector3f & normal)
{
  float A, B, C;

  A = ray.Rd(0) * ray.Rd(0) + ray.Rd(1)*ray.Rd(1) + ray.Rd(2) * ray.Rd(2);

  B  = 2 * ( ray.Rd(0)*(ray.Ro(0) - center(0)) + ray.Rd(1)*(ray.Ro(1) - center(1)) + ray.Rd(2)*(ray.Ro(2) - center(2)));

  C  = pow(ray.Ro(0) - center(0),2)+ pow(ray.Ro(1) - center(1),2) + pow(ray.Ro(2) - center(2),2) - radius*radius;

  float delta = B*B - 4*C*A;

  std::cout << delta <<std:: endl;

  if (delta < 0)
  {
    intersection = NULL_VECTOR;
    normal = NULL_VECTOR;
  }
  else
  {
    float t1 = (-B + sqrt(delta))/(2*A);
    float t2 = (-B - sqrt(delta))/(2*A);

    intersection = std::min(t1,t2)*ray.Rd + ray.Ro;

    normal = intersection - center;
  }

}
