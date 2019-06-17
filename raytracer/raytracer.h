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


public:

    static Scene scene;

    Raytracer();
    Raytracer(Scene scene);
    void setScene(Scene & scene);
    static void rayCasting();
    static void display();
    static void trace(Ray ray, int n_reflections);
    static void reshape(int w, int h);
    static void getClosestIntersection(const Ray &ray,
                                Eigen::Vector3f &normal,
                                Eigen::Vector3f &intersectPoint,
                                int & object_index);
};
#endif
