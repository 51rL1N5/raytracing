#ifndef _SCENE_H
#define _SCENE_H

#include "object.h"
#include "camera.h"
#include "light.h"
#include <iostream>
#include <eigen3/Eigen/Dense>
#include <vector>

class Scene
{
public:

    static Eigen::Vector3f bg_color;

    static Camera * cam;



    static std::vector<Object*> objects;

    static std::vector<Light> light_sources;

    Scene();

    Scene(Camera * cam_, Eigen::Vector3f bg_color_);

    static void setBgColor(Eigen::Vector3f bg_color_ = Eigen::Vector3f(0, 0, 0));
    static void setCam(Camera * cam_);

    static void insertObject(Object * object);
    static void insertLightSource(Light light);

    static Camera * getCam();

};

#endif // _SCENE_H
