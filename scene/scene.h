#ifndef _SCENE_H
#include <iostream>
#include <eigen3/Eigen/Dense>
#include <vector>

using namespace std;
using namespace Eigen;

class Scene
{
private:
    vector<Object> objects;
    Vector3f bg_color;
    float ka;
    Vector3f Ia;
    int window_width;
    int window_height;
    
public:
    Scene(int window_width = 640, int window_height = 480);
    void setBgColor(Vector3f bg_color = Vector3f(0, 0, 0));
    void insertObject(Object object);
    int getWindowWidth();
    int getWindowHeight();
};
#endif
