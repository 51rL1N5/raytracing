#ifndef RAY_H
#define RAY_H

#include <eigen3/Eigen/Dense>

struct Ray
{
  Eigen::Vector3f Ro;

  Eigen::Vector3f Rd; // Director Vector, always normalized

  Ray(Eigen::Vector3f Ro_, Eigen::Vector3f Rd_)
  {
    Ro = Ro_;
    Rd = Rd_ - Ro_;
    Rd.normalize();
  }
};

#endif // RAY_H
