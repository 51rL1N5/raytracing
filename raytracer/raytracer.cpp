#include "raytracer.h"

Scene Raytracer::scene;

Raytracer::Raytracer()
{}
Raytracer::Raytracer(Scene scene)
{this->scene = scene;}

void Raytracer::rayCasting()
{

    std::cout << "ray casting\n";
    for (int i = 0; i < scene.getCam()->window.width; i++)
    {
    //int i = 320;
    //int j = 500;

        for (int j = 0; j < scene.getCam()->window.height; j++)
        {

            //Eigen::Vector3f p1 = scene.getCam()->toWorldPoint(Eigen::Vector3f(i, j, 0.0),scene.getCam()->window.height);
            Eigen::Vector3f p2 = scene.getCam()->toWorldPoint(Eigen::Vector3f(i, j,  1.0),scene.getCam()->window.height);
            Eigen::Vector3f p1(0, 0, -5);
            //std::cout << p1 << std::endl;
            //std::cout << p2 << std::endl;

            //Vector3f rayDir = (p2 - p1) / (p2 - p1).norm();

            Ray ray(p2, p1);


            //std::cout << "ray:" << std::endl;
            //std::cout << ray.Rd << std::endl;

            trace(ray, 1, false);
        }
    }

}

void Raytracer::setScene(Scene & scene)
{
  Raytracer::scene = scene;
}


void Raytracer::getClosestIntersection(const Ray &ray,
                                       Eigen::Vector3f &normal,
                                       Eigen::Vector3f &intersectPoint,
                                       int& object_index)
{

    Eigen::Vector3f min_intersectionPoint(10000, 10000, 10000), min_normal;


    for(int i = 0; i < scene.objects.size(); i++)
    {
        scene.objects.at(i)->intersect(ray, intersectPoint, normal);


        if( intersectPoint.norm() != 0 && intersectPoint.norm() <  min_intersectionPoint.norm())
        {
            min_intersectionPoint = intersectPoint;
            min_normal = normal;
            object_index = i;

        }
    }

    intersectPoint = min_intersectionPoint;
    normal = min_normal;

}

void Raytracer::reshape(int w, int h)
{

    std::cout << "reshape\n";
    Eigen::Vector3f pos = scene.getCam()->pos;
    Eigen::Vector3f lookAt = scene.getCam()->lookAt;
    Eigen::Vector3f normal = scene.getCam()->normal;
    //printf("ok");
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90.0, (float)scene.getCam()->window.width / (float)scene.getCam()->window.height, 0.01, 10000.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(pos(0, 0), pos(1, 0), pos(2, 0), lookAt(0, 0), lookAt(1, 0), lookAt(2, 0), normal(0, 0), normal(1, 0), normal(2, 0));
}


Eigen::Vector3f Raytracer::trace(Ray ray, int n_reflections, bool reflection)
{
    //percorre objetos
    Eigen::Vector3f normal, intersection;
    Eigen::Vector3f cor(0, 0, 0), cor_reflection(0, 0, 0);



    int object_index = -1;

    getClosestIntersection(ray, normal, intersection, object_index);

    //Calcula contribuição das luzes
    for (int i = 0; i < scene.light_sources.size(); i++)
    {
        if (object_index == -1)
            return Eigen::Vector3f(0, 0, 0);
        cor = scene.light_sources.at(i)->shade(ray, scene.objects.at(object_index));
    }

    if(n_reflections != 0)
    {
        int obj_index = -1;
        Eigen::Vector3f obj_intersection, normal_obj;
        Eigen::Vector3f observer = ray.Ro-intersection;
        observer.normalize();
        Eigen::Vector3f reflected = 2*normal*(normal.dot(observer)) - observer;

        Ray reflected_ray(intersection, Eigen::Vector3f(0, 0, 0));
        reflected_ray.Rd = reflected;

        getClosestIntersection(reflected_ray, normal_obj, obj_intersection, obj_index);

        if(obj_index != -1)
        {
            cor_reflection = trace(reflected_ray, n_reflections-1, true);

            if(isnanf(cor_reflection.norm()))
              cor_reflection = Eigen::Vector3f(0,0,0);

        }
    }
    else if(reflection)
    {
        return cor;
    }

    Eigen::Vector3f final_color = (cor*cor.norm() + cor_reflection*cor_reflection.norm())/(cor.norm() + cor_reflection.norm());

    //std::cout << final_color(0) << ", " << final_color(1) << ", " << final_color(2) << std::endl;
    if(!reflection)
    {
        //std::cout << "obj: " << object_index << std::endl;
        scene.objects.at(object_index)->drawPoints.push_back(std::pair<Eigen::Vector3f, Color>(intersection, Color(final_color)));
    }
    return final_color;
}

void Raytracer::display()
{

glEnable(GL_DEPTH_TEST);

    std::cout << "display\n";
    Eigen::Vector3f pos = scene.getCam()->pos;
    Eigen::Vector3f lookAt = scene.getCam()->lookAt;
    Eigen::Vector3f normal = scene.getCam()->normal;
//    rayCasting();
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
