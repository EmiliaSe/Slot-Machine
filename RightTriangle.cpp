//Emilia Segura, 40138440

#include <string>
#include <cmath>
#include <vector>

#include "Shape.h"
#include "Triangle.h"
#include "RightTriangle.h"

using std::string;
using std::vector;

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


Grid RightTriangle::draw(char fChar, char bChar) const{
    int side = boxWidth();
    
    Grid temp;

    for (int i=1; i <= side ; ++i){ //outer loop going row by row
        vector<char> row;
        for (int j=1; j<=i; ++j){ //fill the foreground
            row.push_back(fChar); 
        }
        for (int k=side-i; k>0; --k){ //fill backgroud
            row.push_back(bChar);
        }
        temp.push_back(row);
    }

   return temp;
}