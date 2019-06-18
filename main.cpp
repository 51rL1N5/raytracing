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
   Camera cam(Vector3f(0, 0, -10), Vector3f(0, 0, 0), Vector3f(0, 1, 0), window);
   Scene scene;


   scene.setCam(&cam);
   scene.setBgColor(Vector3f(0, 0, 0));

   Sphere * esfera = new Sphere();
   Sphere * esfera2 = new Sphere();

   esfera->setSphere(Eigen::Vector3f(0,6,40), 4, 0.5, 0.3);
    esfera2->setSphere(Eigen::Vector3f(0,-6,40), 4, 0.5, 0.3);

   scene.insertObject(esfera);
   scene.insertObject(esfera2);

/*
   Triangle * triangle = new Triangle();

   triangle->setTriangle(Vector3f(4,-1,40), Vector3f(-4,-1,40), Vector3f(0,4,40));

   scene.insertObject(triangle);
*/
/*
   Cube * cube = new Cube();

   cube->setCube(Vector3f(0,0,20), 4);

   scene.insertObject(cube)
*/


   Plane * plane = new Plane();


   plane->setPlane(Vector3f(0,0,-1), 30);


   scene.insertObject(plane);


   Light * light = new Light();

   light->setLightPosition(Vector3f(0,10,20));
   light->setLightColor(Vector3f(1,1,1));
   light->setAmbientLightColor(Vector3f(0,1.0,1.0));
   light->setLightCoeffs(0.2, 0.5, 0.3, 50);

   scene.insertLightSource(light);

   Raytracer raytracer;
   raytracer.setScene(scene);

   raytracer.rayCasting();

  glutDisplayFunc(raytracer.display);
  glutReshapeFunc(raytracer.reshape);
  glutMainLoop();


   return 0;
}
