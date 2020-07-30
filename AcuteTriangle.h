//Emilia Segura, 40138440

#ifndef ACUTETRIANGLE_H
#define ACUTETRIANGLE_H

#include "Shape.h" 
#include "Triangle.h"

class AcuteTriangle: public Triangle{

private:

public:

    AcuteTriangle(int b, const std::string& name = "Wedge", const std::string& description = "Three acute angles");
    virtual ~AcuteTriangle() = default;

    double perimeter() const;
    int screenArea() const;
    int screenPerimeter() const;
  
    Grid draw(char fChar = '*', char bChar = ' ') const;


};

#endif