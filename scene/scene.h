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
private:

    std::vector<Object*> objects;

    std::vector<Light> light_sources;

    Eigen::Vector3f bg_color;

    static Camera * cam;

public:
    Scene();

    Scene(Camera * cam, Eigen::Vector3f bg_color);
    void setBgColor(Eigen::Vector3f bg_color = Eigen::Vector3f(0, 0, 0));
    void setCam(Camera * cam);
    
    void insertObject(Object * object);
    void insertLightSource(Light light);

    Camera * getCam();

};

#endif // _SCENE_H
