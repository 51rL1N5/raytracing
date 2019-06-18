#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "object.h"

class Triangle : public Object
{
public:

  Eigen::Vector3f vertex[3];

  Triangle();
  
  Triangle(Eigen::Vector3f v0, Eigen::Vector3f v1, Eigen::Vector3f v2);

  void setTriangle(Eigen::Vector3f v0, Eigen::Vector3f v1, Eigen::Vector3f v2);

  void intersect(Ray ray, Eigen::Vector3f & intersection, Eigen::Vector3f & normal);

};

#endif // TRIANGLE_H
