//Emilia Segura, 40138440

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <string>
#include "Shape.h"

class Triangle: public Shape{

private:
    int h; //height and base are commun data members to both acute and right triangles
    int b;

public:

    Triangle(int b, int h, const std::string& name, const std::string& description);
    virtual ~Triangle() = default;

    double area() const;

    int boxHeight() const; //these are equivalent to the height and base of both types of triangles
    int boxWidth() const;

    //other functions are left to the derived classes AcuteTriangle and RightTriangle as they are different for each triangle


};

#endif