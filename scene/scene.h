#ifndef _SCENE_H
#define _SCENE_H

#include "object.h"
#include <iostream>
#include <eigen3/Eigen/Dense>
#include <vector>


class Scene
{
private:
    std::vector<Object*> objects;
    Eigen::Vector3f bg_color;
    float ka;
    Eigen::Vector3f Ia;

public:
    Scene();
    void setBgColor(Eigen::Vector3f bg_color = Eigen::Vector3f(0, 0, 0));
    void insertObject(Object * object);
};

#endif // _SCENE_H
