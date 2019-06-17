#include "scene.h"

Camera * Scene::cam;

Eigen::Vector3f Scene::bg_color;

std::vector<Object*> Scene::objects;

std::vector<Light> Scene::light_sources;


Scene::Scene()
{
  this->bg_color = Eigen::Vector3f(0,0,0);
}

Scene::Scene(Camera * cam_, Eigen::Vector3f bg_color_)
{
    bg_color = bg_color_;
    cam      = cam_;
}


void Scene::setBgColor(Eigen::Vector3f bg_color_)
{
    bg_color = bg_color_;
}

void Scene::setCam(Camera * cam_)
{
  cam = cam_;
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
