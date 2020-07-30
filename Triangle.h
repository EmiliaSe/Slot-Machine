//Emilia Segura, 40138440

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <string>
#include "Shape.h"

class Triangle: public Shape{

private:
    int h; //height and base are common data members to both acute and right triangles
    int b;

public:

    Triangle(int b, int h, const std::string& name, const std::string& description);
    virtual ~Triangle() = default;

//these three functions are common to both types of triangles so they are implemented here
    double area() const;
    int boxHeight() const; //these are equivalent to the height and base of both types of triangles
    int boxWidth() const;

    //other functions are left to the derived classes AcuteTriangle and RightTriangle as they are different for each triangle
    //therefore triangle is an adstract class as it does not implement all the pure virtual functions defined in Shape
};

#endif