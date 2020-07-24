//Emilia Segura
#include <string>
#include "Triangle.h"
#include "Shape.h"


//constructor, sets Triangle data members and forwards name and description to shape
Triangle::Triangle(int b, int h, const std::string& name, const std::string& description): Shape{name, description}, b{b}, h{h} {}

//area can be implement here as it is common to both triangles
double Triangle::area() const{
    return double(h)*b/2;
}
//this is common to both triangles
int Triangle::boxHeight() const{
    return h;
}
int Triangle::boxWidth() const{
    return b;
}
