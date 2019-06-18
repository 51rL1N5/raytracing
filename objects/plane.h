#ifndef PLANE_H
#define PLANE_H

#include "object.h"

class Plane : public Object
{
public:
  Eigen::Vector3f normal_;

  float distance;

  Plane();

  void setPlane(Eigen::Vector3f normal, float distance_, float ks, float kd);

  void intersect(Ray ray, Eigen::Vector3f & intersection, Eigen::Vector3f & normal);
};

#endif // PLANE_H
