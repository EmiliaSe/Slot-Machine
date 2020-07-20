//Emilia Segura, 40138440


#ifndef RECTANGLE.H
#define RECTANGLE.H

#include <string>
#include "Shape.h"

class Rectangle: public Shape{

private:
    int h;
    int w;



public:
    Rectangle(int& h, int& w, std::string name ="Rectangle", std::string description = "Four right angles"); //constructor
    virtual ~Rectangle(); //destructor


    

//ARE THESE SUPPOSE TO BE VIRTUAL??? WHAT GOES IN BASE VS DERIVED CLASSES
    std::string toString();
    double area(); //check return types
    double perimeter();
    int screenArea();
    int screenPerimeter();
    void draw();
    int boxHeight();
    int boxWidth();


};

#endif