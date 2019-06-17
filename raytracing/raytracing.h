#ifndef _RAYTRACER_H
#define _RAYTRACER_H
#include <iostream>
#include <../scene/scene.h>
#include <../light/light.h>
#include <../objects/objects.h>
#include <../objects/ray.h>
#include <eigen3/Eingen/Dense>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

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
