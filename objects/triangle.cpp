#include "triangle.h"
#include <cmath>

#define EPSILON 0.00001
#define NULL_VECTOR Eigen::Vector3f(0,0,0)

Triangle::Triangle()
{}

Triangle::Triangle(Eigen::Vector3f v0, Eigen::Vector3f v1, Eigen::Vector3f v2)
{
  vertex[0] = v0;
  vertex[1] = v1;
  vertex[2] = v2;
}

void Triangle::setTriangle(Eigen::Vector3f v0, Eigen::Vector3f v1, Eigen::Vector3f v2)
{
  vertex[0] = v0;
  vertex[1] = v1;
  vertex[2] = v2;
}

void Triangle::intersect(Ray ray, Eigen::Vector3f & intersection, Eigen::Vector3f & normal)
{

  // Vetor normal
  normal = (vertex[1] - vertex[0]).cross(vertex[2]-vertex[0]);

  // Achar intercessão com o plano

  if(fabs(normal.dot(ray.Rd)) < EPSILON)
  {
    intersection = NULL_VECTOR;
    normal = NULL_VECTOR;
    return;
  }

  // Parâmetro D do plano que contém o triangulo
  float D = normal.dot(vertex[0]);

  // encontrar o t da itnercessão
  float t;

  t = (normal.dot(ray.Ro) + D) / normal.dot(ray.Rd);

  if (t < 0)
  {
    intersection = NULL_VECTOR;
    normal = NULL_VECTOR;
    return;
  }

  intersection = ray.Ro + t * ray.Rd;

  // Ver se tá dentro do triangulo
  Eigen::Vector3f C;

  // Aresta 0

  Eigen::Vector3f edge0 = vertex[1] - vertex[0];
  Eigen::Vector3f vp0   = intersection - vertex[0];

  C = edge0.cross(vp0);

  if(normal.dot(C) < 0)
  {
    intersection = NULL_VECTOR;
    normal = NULL_VECTOR;
    return;
  }

  // Aresta 1

  Eigen::Vector3f edge1 = vertex[2] - vertex[1];
  Eigen::Vector3f vp1   = intersection - vertex[1];

  C = edge1.cross(vp1);

  if(normal.dot(C) < 0)
  {
    intersection = NULL_VECTOR;
    normal = NULL_VECTOR;
    return;
  }

  // Aresta 2

  Eigen::Vector3f edge2 = vertex[0] - vertex[2];
  Eigen::Vector3f vp2   = intersection - vertex[2];

  C = edge2.cross(vp2);

  if(normal.dot(C) < 0)
  {
    intersection = NULL_VECTOR;
    normal = NULL_VECTOR;
    return;
  }

  normal.normalize();
}
