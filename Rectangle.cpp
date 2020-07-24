//Emilia Segura, 40138440

#include <string>
#include <vector>

#include "Shape.h"
#include "Rectangle.h" 

using std::string;
using std::cout;
using std::endl;
using std::vector;


//constructor. Forwards name and description to the Shape constructor
Rectangle::Rectangle(int w, int h,const string name, const string description): Shape(name, description), h{h}, w{w} {
  //  cout << "A rectangle has been created" <<endl; //for testing
}

double Rectangle::area() const{
    return double(h)*w;

} 
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


Grid Rectangle::draw(char fChar, char bChar) const{

   vector<vector<char>> temp(h,vector<char>(w, fChar)); //create 2D vector with right dimensions and fill completeley with foreground character
   return temp;
}
