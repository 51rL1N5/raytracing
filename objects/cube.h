#ifndef CUBE_H
#define CUBE_H

#include "object.h"
#include "triangle.h"

class Cube : public Object
{
public:

  std::vector<Triangle *> triangles;

  float size;

  Cube();

  Cube(Eigen::Vector3f left_corner, float size, float ks, float kd);

  void setCube(Eigen::Vector3f left_corner, float size, float ks, float kd);

  void intersect(Ray ray, Eigen::Vector3f & intersection, Eigen::Vector3f & normal);

};

#endif // TRIANGLE_H
