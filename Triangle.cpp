//Emilia Segura
#include <string>
#include "Triangle.h"
#include "Shape.h"


//constructor
Triangle::Triangle(int b, int h, const std::string& name, const std::string& description): Shape{name, description}, b{b}, h{h} {}

int Triangle::getBaseTriangle() const{
    return b;
}
int Triangle::getHeightTriangle() const{
    return h;
}
double Triangle::area() const{
    return double(h)*b/2;

}