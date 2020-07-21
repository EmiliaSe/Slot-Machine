//Emilia Segura, 40138440

#include <string>
#include <cmath>

#include "Shape.h"
#include "Rhombus.h"

//constructor
Rhombus::Rhombus(int d, const std::string name, const std::string description): Shape{name, description}{
    if (d%2 ==1){
        this->d = d;
    }
    else{
        this->d = d+1;
    }
}

double Rhombus::area() const{
    return ((double)d*d)/2.0;
} //check return types
double Rhombus::perimeter() const{
    return 2.0*sqrt(2.0)*double(d);
}
int Rhombus::screenArea() const{
    int n{d/2};
    return 2*n*(n+1)+1;
}
int Rhombus::screenPerimeter() const{
    return 2*(d-1);
}
int Rhombus::boxHeight() const{
    return d;
}
int Rhombus::boxWidth() const{
    return d;
}