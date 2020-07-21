//Emilia Segura, 40138440

#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "Shape.h"

class Rhombus: public Shape{

private:
    int d; //if d is odd d=d else d= d+1 (make sure construction is done right!)



public:

    Rhombus(int d, const std::string name ="Diamond", const std::string description = "Parallelogram with equal sides"); //constructor
    virtual ~Rhombus() = default; //destructor

    double area() const; //check return types
    double perimeter() const;
    int screenArea() const;
    int screenPerimeter() const;
    int boxHeight() const;
    int boxWidth() const;

   Grid draw(char fChar = '*', char bChar = ' ') const;


};

#endif