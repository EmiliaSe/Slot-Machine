//Emilia Segura

#include <string>
#include <cmath>

#include "Shape.h"
#include "Triangle.h"
#include "AcuteTriangle.h"

using std::string;


//constructor
AcuteTriangle::AcuteTriangle(int b, const string& name, const string& description)
        : Triangle(b%2==1 ? b : b+1 , b%2==1 ? ((b+1)/2) :((b+2)/2) , name, description){ //parity condition is inside constructor of parent
}


//look into simplofying all this with more in Triangle parent class
double AcuteTriangle::perimeter() const{
    int b = getBaseTriangle();
    int h = getHeightTriangle();
    return double(b) + sqrt(b*b+4*h*h);

}
int AcuteTriangle::screenArea() const{
    return getHeightTriangle()*getHeightTriangle();
}
int AcuteTriangle::screenPerimeter() const{
    return 4*(getHeightTriangle()-1);
}
int AcuteTriangle::boxHeight() const{
    return getHeightTriangle();
}
int AcuteTriangle::boxWidth() const{
    return getBaseTriangle();
}