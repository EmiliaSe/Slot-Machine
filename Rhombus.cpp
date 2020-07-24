//Emilia Segura, 40138440

#include <string>
#include <cmath>
#include <vector>

#include "Shape.h"
#include "Rhombus.h"

using std::vector;

//constructor, forwards name and description to Shape constructor
Rhombus::Rhombus(int d, const std::string name, const std::string description): Shape{name, description}{
    if (d%2 ==1){
        this->d = d; 
    }
    else{
        this->d = d+1; //if even make it odd
    }
}

double Rhombus::area() const{
    return ((double)d*d)/2.0;
} 
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

Grid Rhombus::draw(char fChar, char bChar) const{

   Grid temp; //create 2D vector 
   int height = d/2 +1;
   for (int i=1; i <= height ; ++i){ //outer loop going row by row for top half      
        vector<char> row; //temp vector to store a row of characters
        for (int j=i; j < height; ++j){ //fill the left backgroud
            row.push_back(bChar); 
        }
        for (int k=1; k <=(2*i-1); ++k){ //fill foreground in middle
            row.push_back(fChar);
        }
        for (int l=i; l < height; ++l){ //fill the right backgroud
            row.push_back(bChar); 
        }
        temp.push_back(row); //add row to vector
    }
   int h = d/2;
   for (int i=h; i >=1; --i){  //outer loop for bottom half
        vector<char> row;
        for (int j=i; j<=h; j++){
            row.push_back(bChar); //left background
        }
        for (int k=1; k<=(2*i-1);k++){
            row.push_back(fChar); //foreground in middle
        }
        for (int l=i; l<=h; l++){
            row.push_back(bChar); //right background
        }
        temp.push_back(row); 
   }
   return temp;
}