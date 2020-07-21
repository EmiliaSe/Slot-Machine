//Emilia Segura, 40138440


#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <string>
#include "Shape.h"

class Rectangle: public Shape{

private:
    int h;
    int w;



public:
    Rectangle(int h, int w, const std::string name ="Rectangle", const std::string description = "Four right angles"); //constructor
    virtual ~Rectangle() = default; //destructor

    double area() const; //check return types
    double perimeter() const;
    int screenArea() const;
    int screenPerimeter() const;
    int boxHeight() const;
    int boxWidth() const;

    Grid draw(char fChar = '*', char bChar = ' ') const;
};

#endif