//Emilia Segura, 40138440

#include <string>
#include <cmath>

#include "Shape.h"
#include "Triangle.h"
#include "RightTriangle.h"

using std::string;

//constructor
RightTriangle::RightTriangle(int b, const string& name, const string& description): Triangle{b,b,name, description}{

}

double RightTriangle::perimeter() const{
    return (2+sqrt(2))* double(getHeightTriangle());
}
int RightTriangle::screenArea() const{
    int he = getHeightTriangle();
    return he * (he +1) / 2;
}
int RightTriangle::screenPerimeter() const{
    return 3*(getHeightTriangle()-1);
}

//could simplify I think, and move this to Triangle!!
int RightTriangle::boxHeight() const{
    return getBaseTriangle();
}
int RightTriangle::boxWidth() const{
    return getHeightTriangle();
}