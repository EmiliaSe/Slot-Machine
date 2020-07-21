//Emilia Segura, 40138440

#include <string>
#include <cmath>
#include <vector>

#include "Shape.h"
#include "Rhombus.h"

using std::vector;

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

//This works! could it be simpler?
Grid Rhombus::draw(char fChar, char bChar) const{

   Grid temp; //create 2D vector 

   vector<char> middlerow (d,'*');
   temp.push_back(middlerow);

 int h = d/2;
   for (int i=h; i >=1; --i){  //loop to add rows.. maybe will have to change range
   
        vector<char> row;

        for (int j=i; j<=h; j++){
            row.push_back(bChar); //left background
        }

        for (int k=1; k<=(2*i-1);k++){
            row.push_back(fChar);
        }
        for (int l=i; l<=h; l++){
            row.push_back(bChar); //right background
        }

        temp.push_back(row); //insert rows both before and after middle
        temp.insert(temp.begin(), row);
   }

   return temp;
}