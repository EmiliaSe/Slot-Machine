//Emilia Segura, 40138440

#include <string>

#include "Shape.h"
#include "Rectangle.h" //also need to include shape?

using std::string;
using std::cout;
using std::endl;


//constructor
Rectangle::Rectangle(int h, int w,const string name, const string description): Shape(name, description), h{h}, w{w} {
    cout << "A rectangle has been created" <<endl; //for testing
}



double Rectangle::area() const{
    return double(h)*w;

} //check return types
double Rectangle::perimeter() const{
    return 2.0*(h+w);
}
int Rectangle::screenArea() const{
        return area();

}
int Rectangle::screenPerimeter() const{
    return perimeter()-4;

}
int Rectangle::boxHeight() const{
    return h;
}
int Rectangle::boxWidth() const{
    return w;
}

