#include <iostream>
#include <eigen3/Eigen/Dense>

#include "camera.h"
#include "scene.h"
#include "raytracer.h"

using namespace Eigen;

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize (640, 480);
  glutInitWindowPosition (100, 100);
  glutCreateWindow (argv[0]);


   Window window(640,480,100,100,1,300);
   Camera cam(Vector3f(0, 0, -5), Vector3f(0, 0, 0), Vector3f(0, 1, 0), window);
   Scene scene;

   scene.setCam(&cam);
   scene.setBgColor(Vector3f(0, 0, 0));

   Raytracer raytracer(scene);

   raytracer.rayCasting();

  glutDisplayFunc(raytracer.display);
  glutReshapeFunc(raytracer.reshape);
  glutMainLoop();


   return 0;
}
