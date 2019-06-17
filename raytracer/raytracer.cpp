#include "raytracer.h"

void Raytracer::rayCasting(Scene scene)
{

    cout << "ray casting\n";
    for (int i = 0; i < scene.getWindowWidth(); i++)
    {

        for (int j = 0; j < scene.getWindowHeight(); j++)
        {

            Vector3f p1 = scene.getCam()->toWorldPoint(Eigen::Vector3f(i, j, 0.0), 480);
            Vector3f p2 = scene.getCam().toWorldPoint(Vector3f(i, j, 1.0), scene.getWindowHeight());

            //Vector3f rayDir = (p2 - p1) / (p2 - p1).norm();
            
            Ray ray(p1, p2);        

            trace(ray, 1);
        }
    }
    
}

void Raytracer::getClosestIntersection(const Ray &ray,
                                       Eigen::Vector3f &normal,
                                       Eigen::Vector3f &intersectPoint,
                                       int object)
{
    for(int i = 0; i < scene.objects.size(); i++)
    {
        if(scene.objects.at(i)->intersect(ray, normal, ))
    }
}

void Raytracer::trace(Ray ray, int n_reflections)
{
    //percorre objetos
    Eigen::Vector3f normal, intersection;
    for(int i = 0; i < scene.objects.size(); i++)
    {
        
        if(scene.objects.at(i)->intersect(ray, normal, ))
    }
}

void Raytracer::display()
{

glEnable(GL_DEPTH_TEST);

    cout << "display\n";
    Eigen::Vector3f pos = scene.getCam()->pos;
    Eigen::Vector3f lookAt = scene.getCam()->lookAt;
    Eigen::Vector3f normal = scene.getCam()->normal;
    rayCasting();
    glLoadIdentity();
    glClearColor(0.0, 0, 0.7, 1);
    gluLookAt(pos(0, 0), pos(1, 0), pos(2, 0), lookAt(0, 0), lookAt(1, 0), lookAt(2, 0), normal(0, 0), normal(1, 0), normal(2, 0)); //placed at (0,0,5), aim at (0,0,0), normal vector (0,1,0)
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBegin(GL_POINTS);

    for (int i = 0; i < scene.objects.size(); i++)
    {
        for (int j = 0; j < scene.objects.at(i)->drawPoints.size(); j++)
        {

            Eigen::Vector3f point = scene.objects.at(i)->drawPoints.at(j).first;
            Color cor = scene.objects.at(i)->drawPoints.at(j).second;
            glColor3f(cor.r, cor.g, cor.b);

            /*float x = point(0, 0);
            float y = point(1, 0);
            float z = point(2, 0);*/

            glVertex3f(point(0), point(1), point(2));
        }
        scene.objects.at(i)->drawPoints.clear();
    }

    /*for (int i = 0; i < shadows.size(); i++)
    {
        for (int j = 0; j < shadows[i].drawPoints.size(); j++)
        {

            Eigen::Vector3f point = shadows[i].drawPoints[j].first;
            Color cor = shadows[i].drawPoints[j].second;
            glColor3f(0, 0, 0);

            float x = point(0, 0);
            float y = point(1, 0);
            float z = point(2, 0);
            cout << x << " " << y << " " << z << endl
                 << endl
                 << "-----------------------------\n\n";
            glVertex3f(x, y, z);
        }
        shadows[i].drawPoints.clear();
    }*/
    glEnd();

    glFlush();
}
