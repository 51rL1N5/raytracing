#include "raytracer.h"

void Raytracer::rayCasting()
{
/*
    cout << "ray casting\n";
    for (int i = 0; i < cam->window.width; i++)
    {

        for (int j = 0; j < cam->window.height; j++)
        {

            Vector3f p1 = cam->toWorldPoint(Eigen::Vector3f(i, j, 0.0), 480);
            Vector3f p2 = cam->toWorldPoint(Vector3f(i, j, 1.0), cam->window.height);

            Vector3f rayDir = (p2 - p1) / (p2 - p1).norm();

            //cout<<p1<<endl;

            trace(p1, rayDir, 1);
        }
    }
    */
}

void Raytracer::reshape(int w, int h)
{
/*
    cout << "reshape\n";
    Eigen::Vector3f pos = (*cam).pos;
    Eigen::Vector3f lookAt = (*cam).lookAt;
    Eigen::Vector3f normal = (*cam).normal;
    //printf("ok");
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, cam->window.width / (float)cam->window.height, 1.0, 100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(pos(0, 0), pos(1, 0), pos(2, 0), lookAt(0, 0), lookAt(1, 0), lookAt(2, 0), normal(0, 0), normal(1, 0), normal(2, 0));
    */
}

void Raytracer::display()
{/*
    cout<<"\n frontal\n" <<shapes[1].getFace(0).getNormalVector()<<endl<<endl;
    cout<<"\n left\n" <<shapes[1].getFace(1).getNormalVector()<<endl<<endl;
    cout<<"\n bot\n" <<shapes[1].getFace(2).getNormalVector()<<endl<<endl;
    cout<<"\n back\n" <<shapes[1].getFace(3).getNormalVector()<<endl<<endl;
    cout<<"\n right\n" <<shapes[1].getFace(4).getNormalVector()<<endl<<endl;
    cout<<"\n top\n" <<shapes[1].getFace(5).getNormalVector()<<endl<<endl;
*/
/*
glEnable(GL_DEPTH_TEST);

    cout << "display\n";
    Eigen::Vector3f pos = (*cam).pos;
    Eigen::Vector3f lookAt = (*cam).lookAt;
    Eigen::Vector3f normal = (*cam).normal;
    rayCasting();
    glLoadIdentity();
    glClearColor(0.0, 0, 0.7, 1);
    gluLookAt(pos(0, 0), pos(1, 0), pos(2, 0), lookAt(0, 0), lookAt(1, 0), lookAt(2, 0), normal(0, 0), normal(1, 0), normal(2, 0)); //placed at (0,0,5), aim at (0,0,0), normal vector (0,1,0)
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBegin(GL_POINTS);

    for (int i = 0; i < shapes.size(); i++)
    {
        for (int j = 0; j < shapes[i].drawPoints.size(); j++)
        {

            Eigen::Vector3f point = shapes[i].drawPoints[j].first;
            Color cor = shapes[i].drawPoints[j].second;
            glColor3f(cor.r, cor.g, cor.b);

            float x = point(0, 0);
            float y = point(1, 0);
            float z = point(2, 0);

            glVertex3f(x, y, z);
        }
        shapes[i].drawPoints.clear();
    }

    for (int i = 0; i < shadows.size(); i++)
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
    }
    glEnd();

    glFlush();
    */
}
