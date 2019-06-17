#ifndef _SCENE_H
#include <iostream>
#include <eigen3/Eigen/Dense>
#include <vector>

using namespace std;
using namespace Eigen;

Class Scene
{
private:
    vector<Object> objects;
    Vector3f bg_color;
    float ka;
    Vector3f Ia;
    
public:
    Scene();
    void setBgColor(Vector3f bg_color = Vector3f(0, 0, 0));
    void insertObject(Object object);
};
#endif
