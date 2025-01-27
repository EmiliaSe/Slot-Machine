//Emilia Segura, 40138440

#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <typeinfo>
#include "Shape.h"

using std::string;
using std::cout;
using std::endl;
using std::ostream;


int Shape::counter{0};
//constructor
Shape::Shape(const std::string& name, const std::string& description) 
    : name{name}, description{description}, id{++counter}{ //using a static counter variable to increment ids
}


int Shape::getId() const{
    return this->id;
}
string Shape::getName() const{
    return this->name;
}
string Shape::getDescription() const{
    return this->description;
}

void Shape::setName(std::string& name){
    this->name = name;
}
void Shape::setDescription(std::string& description){
    this->description = description;
}


//uses a string stream to nicely construct two formatted columns of output
string Shape::toString() const{
   std::ostringstream s;
   s << "Shape Information\n-----------------\n";
   s << std::left <<std::setw(15)<< "id:" << getId() <<endl;
   s << std::left <<std::setw(15)<< "Shape name:" << getName() <<endl;
   s << std::left <<std::setw(15)<< "Description:" << getDescription() <<endl;
   s << std::left <<std::setw(15)<< "B. box width:" << boxWidth() <<endl;
   s << std::left <<std::setw(15)<< "B. box height:" << boxHeight() <<endl;
   s << std::left <<std::setw(15)<< "Scr area" <<  screenArea() <<endl;
   s << std::left <<std::setw(15)<< "Geo area:" << std::fixed << std::setprecision(2)<< area() <<endl; //fixed and set precison to print decimal number nicely
   s << std::left <<std::setw(15)<< "Scr perimeter:" << screenPerimeter() <<endl;
   s << std::left <<std::setw(15)<< "Geo perimeter:" << std::fixed << std::setprecision(2)<< perimeter() <<endl;
   s << std::left <<std::setw(15)<< "Static type:" << typeid(this).name() <<endl;
   s << std::left <<std::setw(15)<< "Dynamic type:" << typeid(*this).name() <<endl;
   
   return s.str(); //return the string stream as a single string
}

//to output string representation
ostream& operator<< (ostream& out, const Shape& shape){
      out << shape.toString();
      return out;
}

//to output the drawing of any shape 
ostream& operator<< (ostream& out, const Grid& g){
    for ( const auto &row : g ){ //for each row
        for ( const auto &c : row ) { //for each char in the row
            out << c; //add char to stream
        }
    out << '\n'; //new line after each row
    }
    return out;
}