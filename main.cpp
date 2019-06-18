#include <iostream>
#include <eigen3/Eigen/Dense>

#include "camera.h"
#include "scene.h"
#include "raytracer.h"
#include "sphere.h"
#include "light.h"
#include "triangle.h"
#include "cube.h"
#include "plane.h"

using namespace Eigen;

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize (640, 480);
  glutInitWindowPosition (100, 100);
  glutCreateWindow (argv[0]);


   Window window(640,480,100,100,-20,300);
   Camera cam(Vector3f(0, 0, -5), Vector3f(0, 0, 0), Vector3f(0, 1, 0), window);
   Scene scene;


   scene.setCam(&cam);
   scene.setBgColor(Vector3f(0, 0, 0));

   Sphere * esfera = new Sphere();

   esfera->setSphere(Eigen::Vector3f(-5,0,5), 3, 0.7, 0.2);

   Sphere * esfera2 = new Sphere();

   esfera2->setSphere(Eigen::Vector3f(3,0,3), 3, 0.1, 0.50);


   Sphere * esfera3 = new Sphere();

   esfera3->setSphere(Eigen::Vector3f(0,0,7), 3, 0.21, 0.70);




   scene.insertObject(esfera);
   scene.insertObject(esfera2);
   scene.insertObject(esfera3);
/*
   Triangle * triangle = new Triangle();

   triangle->setTriangle(Vector3f(4,-1,40), Vector3f(-4,-1,40), Vector3f(0,4,40));

   scene.insertObject(triangle);
*/
/*
   Cube * cube = new Cube();

   cube->setCube(Vector3f(0,0,10), 3, 0.3, 0.5);

   scene.insertObject(cube);
*/


   Plane * plane = new Plane();


   plane->setPlane(Vector3f(0,1,0), 3, 0.2, 0.8);


   scene.insertObject(plane);


   Light * light = new Light();

   light->setLightPosition(Vector3f(0,10,8));
   light->setLightColor(Vector3f(1,1,1));
   light->setAmbientLightColor(Vector3f(0.1,0.5,1.0));
   light->setLightCoeffs(0.5, 0.5, 0.3, 5);

   scene.insertLightSource(light);

/*
   Light * light2 = new Light();

   light2->setLightPosition(Vector3f(-10,10,0));
   light2->setLightColor(Vector3f(1,0,0));
   light2->setAmbientLightColor(Vector3f(0,1.0,1.0));
   light2->setLightCoeffs(0.2, 0.5, 0.3, 50);

   scene.insertLightSource(light2);
*/
   Raytracer raytracer;
   raytracer.setScene(scene);

   raytracer.rayCasting();

  glutDisplayFunc(raytracer.display);
  glutReshapeFunc(raytracer.reshape);
  glutMainLoop();


   return 0;
}
