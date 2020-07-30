//Emilia Segura, 40138440


#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <string>
#include "Shape.h"

class Rectangle: public Shape{

private:
    int h; //rectangle height
    int w; //rectangle width

public:
    Rectangle(int w, int h, const std::string name ="Rectangle", const std::string description = "Four right angles"); //constructor, takes default name and descriptions
    virtual ~Rectangle() = default; //destructor

//all implemented here in derived class. All const since they should not modify the object
    double area() const; 
    double perimeter() const;
    int screenArea() const;
    int screenPerimeter() const;
    int boxHeight() const;
    int boxWidth() const;

    Grid draw(char fChar = '*', char bChar = ' ') const;
};

#endif