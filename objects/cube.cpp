#include "cube.h"

Cube::Cube()
{}

Cube::Cube(Eigen::Vector3f left_corner, float size)
{
  this->size = size;


  Eigen::Vector3f p[8];

  p[0] = left_corner;

  p[1] = p[0] + Eigen::Vector3f(0, size,0);

  p[2] = p[1] + Eigen::Vector3f(-size, 0, 0);

  p[3] = p[0] + Eigen::Vector3f(-size,0,0);

  p[4] = p[0] + Eigen::Vector3f(0,0,size);

  p[5] = p[4] + Eigen::Vector3f(0,size,0);

  p[6] = p[5] + Eigen::Vector3f(-size, 0,0);

  p[7] = p[4] + Eigen::Vector3f(-size, 0, 0);

  // Bottom side
  triangles.push_back(new Triangle(p[0], p[1], p[2]));
  triangles.push_back(new Triangle(p[0], p[3], p[2]));

  // Left side
  triangles.push_back(new Triangle(p[0], p[4], p[3]));
  triangles.push_back(new Triangle(p[7], p[4], p[3]));

  // Front side
  triangles.push_back(new Triangle(p[0], p[1], p[4]));
  triangles.push_back(new Triangle(p[5], p[1], p[4]));

  // Right Side
  triangles.push_back(new Triangle(p[5], p[1], p[2]));
  triangles.push_back(new Triangle(p[5], p[6], p[2]));

  // Top Side
  triangles.push_back(new Triangle(p[4], p[7], p[6]));
  triangles.push_back(new Triangle(p[4], p[5], p[6]));

  // Back side
  triangles.push_back(new Triangle(p[2], p[6], p[7]));
  triangles.push_back(new Triangle(p[2], p[3], p[7]));

}

void Cube::setCube(Eigen::Vector3f left_corner, float size)
{
  this->size = size;


  std::vector<Eigen::Vector3f > p(8,Eigen::Vector3f(0,0,0));

  p[0] = left_corner;

  p[1] = p[0] + Eigen::Vector3f(0, size,0);

  p[2] = p[1] + Eigen::Vector3f(-size, 0, 0);

  p[3] = p[0] + Eigen::Vector3f(-size,0,0);

  p[4] = p[0] + Eigen::Vector3f(0,0,size);

  p[5] = p[4] + Eigen::Vector3f(0,size,0);

  p[6] = p[5] + Eigen::Vector3f(-size, 0,0);

  p[7] = p[4] + Eigen::Vector3f(-size, 0, 0);

  // Bottom side
  triangles.push_back(new Triangle(p[0], p[1], p[2]));
  triangles.push_back(new Triangle(p[0], p[3], p[2]));

  // Left side
  triangles.push_back(new Triangle(p[0], p[4], p[3]));
  triangles.push_back(new Triangle(p[7], p[4], p[3]));

  // Front side
  triangles.push_back(new Triangle(p[0], p[1], p[4]));
  triangles.push_back(new Triangle(p[5], p[1], p[4]));

  // Right Side
  triangles.push_back(new Triangle(p[5], p[1], p[2]));
  triangles.push_back(new Triangle(p[5], p[6], p[2]));

  // Top Side
  triangles.push_back(new Triangle(p[4], p[7], p[6]));
  triangles.push_back(new Triangle(p[4], p[5], p[6]));

  // Back side
  triangles.push_back(new Triangle(p[2], p[6], p[7]));
  triangles.push_back(new Triangle(p[2], p[3], p[7]));
}

void Cube::intersect(Ray ray, Eigen::Vector3f & intersection, Eigen::Vector3f & normal)
{
  std::vector<Eigen::Vector3f> intersections;//[triangles.size()];
  std::vector<Eigen::Vector3f> normals;//[triangles.size()];

  Eigen::Vector3f tmp_intercept;
  Eigen::Vector3f tmp_normals;

  for (int i = 0; i < triangles.size(); i++)
  {
    triangles.at(i)->intersect(ray, tmp_intercept, tmp_normals);

    intersections.push_back(tmp_intercept);
    normals.push_back(tmp_normals);
  }

  float distance = 20000;
  int closest = -1;

  for (int i = 0; i < triangles.size(); i++)
  {
    if(distance > (ray.Ro -intersections[i]).norm())
    {
      distance =  (ray.Ro -intersections[i]).norm();
      closest = i;
    }
  }

  if(closest == -1)
  {
    normal = Eigen::Vector3f(0,0,0);
    intersection = Eigen::Vector3f(0,0,0);
  }
  else
  {
    normal = normals[closest];
    intersection = intersections[closest];
  }

}
