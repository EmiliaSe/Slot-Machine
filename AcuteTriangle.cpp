//Emilia Segura

#include <string>
#include <cmath>
#include <vector>

#include "Shape.h"
#include "Triangle.h"
#include "AcuteTriangle.h"

using std::string;
using std::vector;


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


Grid AcuteTriangle::draw(char fChar, char bChar) const{
    int base = boxWidth();
    int height = boxHeight();
    
    
    Grid temp;

    for (int i=1; i <= height ; ++i){ //outer loop going row by row
        
        vector<char> row;
        for (int j=i; j < height; ++j){ //fill the left backgroud
            row.push_back(bChar); 
        }
        for (int k=1; k <=(2*i-1); ++k){ //fill foreground
            row.push_back(fChar);
        }
        for (int l=i; l < height; ++l){ //fill the right backgroud
            row.push_back(bChar); 
        }
        temp.push_back(row);
    }
   return temp;
}