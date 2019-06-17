#ifndef SPHERE_H
#define SPHERE_H

#include <eigen3/Eigen/Dense>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <vector>
#include "object.h"

class Sphere : public Object
{
private:

  Eigen::Vector3f center;

  float radius;

public:

  Sphere(); // Default Constructor

  void setSphere(Eigen::Vector3f center_, float radius_, float kd=0.3, float ks=0.3);

  void intersect(const Ray ray, Eigen::Vector3f & intersection, Eigen::Vector3f & normal);

  ~Sphere(); // Default Destructor
};

#endif // SPHERE_H
