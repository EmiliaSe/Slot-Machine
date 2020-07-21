//Emilia Segura, 40138440

#include <string>
#include<iostream>
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
std::cout << "A Shape has been created" << std::endl;
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


//add formatting to print int vs double area/perimeter nicely
string Shape::toString() const{
   std::ostringstream s;
   s << "Shape Information\n-----------------\n";
   s << std::left <<std::setw(15)<< "id:" << getId() <<endl;
   s << std::left <<std::setw(15)<< "Shape name:" << getName() <<endl;
   s << std::left <<std::setw(15)<< "Description:" << getDescription() <<endl;
   s << std::left <<std::setw(15)<< "B. box width:" << boxHeight() <<endl;
   s << std::left <<std::setw(15)<< "B. box height:" << boxWidth() <<endl;
   s << std::left <<std::setw(15)<< "Scr area" << screenArea() <<endl;
   s << std::left <<std::setw(15)<< "Geo area:" << area() <<endl;
   s << std::left <<std::setw(15)<< "Scr perimeter:" << screenPerimeter() <<endl;
   s << std::left <<std::setw(15)<< "Geo perimeter:" << perimeter() <<endl;
   s << std::left <<std::setw(15)<< "Static type:" << typeid(this).name() <<endl;
   s << std::left <<std::setw(15)<< "Dynamic type:" << typeid(*this).name() <<endl;
   
   
   return s.str();
}



  ostream& operator<< (ostream& out, const Shape& shape){
      out << shape.toString();
      return out;
  }