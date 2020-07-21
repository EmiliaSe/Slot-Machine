//Emilia Segura, 40138440

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <string>
#include "Shape.h"

class Triangle: public Shape{

private:
    int h;
    int b;



public:

    Triangle(int b, int h, const std::string& name, const std::string& description);
    virtual ~Triangle() = default; //will this need to be changed?

    int getBaseTriangle() const;
    int getHeightTriangle() const;
    double area() const;

    int boxHeight() const;
    int boxWidth() const;

    


};

#endif