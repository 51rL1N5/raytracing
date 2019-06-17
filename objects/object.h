#ifndef OBJECTS_H
#define OBJECTS_H

#include <eigen3/Eigen/Dense>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <vector>
#include "color.h"
#include "ray.h"

struct Material
{
  float kd;
  float ks;
};

class Object
{
private:

public:

  Material material;

  std::vector<std::pair<Eigen::Vector3f,Color> > drawPoints;

  Object();    // Default Constructor


  ~Object();   // Default Destructor


  virtual void intersect(const Ray ray, Eigen::Vector3f & intersection, Eigen::Vector3f & normal)=0;

};

#endif // OBJECTS_H
