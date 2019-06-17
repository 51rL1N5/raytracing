#include "scene.h"

Scene::Scene(int window_width, int window_height)
{
    objects = vector<Object>();
    this->bg_color = bg_color;
    this->Ia = Ia;
    this->ka = ka;
    this->window_width = window_width;
    this->window_height = window_height;
}

void Scene::setBgColor(Vector3f bg_color)
{
    this->bg_color = bg_color;
}

void Scene::setBgColor(Vector3f bg_color = Vector3f(0, 0, 0))
{
    this->bg_color = bg_color;
}

void Scene::insertObject(Object object)
{
    objects.push_back(object);
}

int Scene::getWindowWidth()
{
    return this->window_width;
}

int Scene::getWindowHeight()
{
    return this->window_height;
}
