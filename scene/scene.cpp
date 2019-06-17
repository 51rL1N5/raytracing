#include "scene.h"

Scene::Scene()
{
    this->bg_color = bg_color;
    this->Ia = Ia;
    this->ka = ka;
}


void Scene::setBgColor(Vector3f bg_color)
{
    this->bg_color = bg_color;
}

void Scene::insertObject(Object * object)
{
    objects.push_back(object);
}
