//Emilia Segura, 40138440

#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "Shape.h"

class Rhombus: public Shape{

private:
    int d; 

public:

    Rhombus(int d, const std::string name ="Diamond", const std::string description = "Parallelogram with equal sides"); //constructor
    virtual ~Rhombus() = default; //destructor

//all implemented here in derived class
    double area() const; 
    double perimeter() const;
    int screenArea() const;
    int screenPerimeter() const;
    int boxHeight() const;
    int boxWidth() const;

   Grid draw(char fChar = '*', char bChar = ' ') const;


};

#endif