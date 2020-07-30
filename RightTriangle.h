//Emilia Segura, 40138440

#ifndef RIGHTTRIANGLE_H
#define RIGHTTRIANGLE_H

#include "Shape.h" 
#include "Triangle.h"

class RightTriangle: public Triangle{

private:


public:

    RightTriangle(int b, const std::string& name = "Ladder", const std::string& description = "One right and two acute angles");
    virtual ~RightTriangle() = default;
    double perimeter() const;
    int screenArea() const;
    int screenPerimeter() const;

    Grid draw(char fChar = '*', char bChar = ' ') const;

};

#endif