#ifndef COLOR_H
#define COLOR_H

#include <eigen3/Eigen/Dense>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <vector>

struct Color
{
    float r;
    float g;
    float b;

    Color()
    {}
    
    Color(const Eigen::Vector3f &cores)
	{
	    this->r = cores(0);
	    this->g = cores(1);
	    this->b = cores(2);
	}
	
	Color(float r, float g, float b)
	{
	    this->r = r;
	    this->g = g;
	    this->b = b;
	}
	
	friend Color operator*(const Color& color, float n)
    {
        Color c(color.r*n, color.g*n, color.b*n);
        return c;
    }
    
    friend Color operator/(const Color& color, float n)
    {
        Color c(color.r/n, color.g/n, color.b/n);
        return c;
    }
    
    Color operator+(const Color& c1)
    {
        return Color(this->r-c1.r, this->g-c1.g, this->b-c1.b);
    }
    
    Color& operator=(const Eigen::Vector3f &cores)
	{
	    this->r = cores(0);
	    this->g = cores(1);
	    this->b = cores(2);
	    return *this;
    }

    Eigen::Vector3f getVector()
    {
        return Eigen::Vector3f(this->r, this->g, this->b);
    }

};

#endif // COLOR_H
