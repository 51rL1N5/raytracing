#ifndef _RAYTRACER_H
#define _RAYTRACER_H
#include <iostream>
#include "scene.h"
#include "light.h"
#include "object.h"

#include <eigen3/Eigen/Dense>

class Raytracer
{
private:
    Scene scene;

public:
    Raytracer(Scene scene);
    void display();
    void reshape();
    void getClosestIntersection(const Ray &ray,
                                Eigen::Vector3f &normal,
                                Eigen::Vector3f &intersectPoint,
                                int object_index = -1);
};
#endif
