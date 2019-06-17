#include "scene.h"


Scene::Scene()
{
  this->bg_color = Eigen::Vector3f(0,0,0);
}

Scene::Scene(Camera * cam, Eigen::Vector3f bg_color)
{
    this->bg_color = bg_color;
    this->cam      = cam;
}


void Scene::setBgColor(Eigen::Vector3f bg_color)
{
    this->bg_color = bg_color;
}

void Scene::setCam(Camera * cam)
{
  this->cam = cam;
}

void Scene::insertObject(Object * object)
{
    objects.push_back(object);
}

void Scene::insertLightSource(Light light)
{
  light_sources.push_back(light);
}

Camera * Scene::getCam()
{
  return cam;
}
