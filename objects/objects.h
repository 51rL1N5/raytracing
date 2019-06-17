#ifndef OBJECTS_H
#define OBJECTS_H

#include <eigen3/Eigen/Dense>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <vector>
#include "color.h"

class Object
{
private:

  struct Material
  {
    float kd;
    float ks;
  };

  std::vector<std::pair<Eigen::Vector3f,Color> > drawPoints;

public:

  Object(); // Default Constructor



};

#endif // OBJECTS_H
