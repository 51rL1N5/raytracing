#include "plane.h"

Plane::Plane()
{}

void Plane::setPlane(Eigen::Vector3f normal, float distance_)
{
  distance = distance_;

  normal_ = normal;

  normal_.normalize();
}

void Plane::intersect(Ray ray, Eigen::Vector3f & intersection, Eigen::Vector3f & normal)
{

  normal = normal_;

  normal.normalize();

  if(fabs(ray.Rd.dot(normal) - distance) < 0.0001)
  {
    normal = Eigen::Vector3f(0,0,0);
    intersection = Eigen::Vector3f(0,0,0);
  }


  float t = -(normal.dot(ray.Ro) + distance)/normal.dot(ray.Rd);

  intersection = t*ray.Rd + ray.Ro;
}
