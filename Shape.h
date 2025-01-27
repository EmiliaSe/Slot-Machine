//Emilia Segura, 40138440

#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <vector>
#include <iostream>


using Grid = std::vector<std::vector<char>>; //defined here as it is used by all shapes

class Shape{

private:
    const int id; 
    std::string name;
    std::string description;

    static int counter; //used to generate the unique id.


public:

    Shape(const std::string& name, const std::string& description); //Constructor
    virtual ~Shape() = default; //destructor 
    Shape(const Shape &s) = delete; //not wanted behaviour
    Shape& operator= (const Shape &s) = delete; //not wanted behaviour

    //getters, non virtual as they only need to be implemented in base class
    int getId() const;
    std::string getName() const;
    std::string getDescription() const;

    //setters, non virtual as they only need to be implemented in base class
    void setName(std::string& name);
    void setDescription(std::string& description);

    std::string toString() const; //shared by all shapes, so implemented in base class

    //pure virutal functions, only implemented in derived classes
    virtual double area() const = 0; 
    virtual double perimeter() const= 0;
    virtual int screenArea() const= 0;
    virtual int screenPerimeter() const = 0;
    virtual int boxHeight() const = 0;
    virtual int boxWidth() const = 0;
    virtual Grid draw(char fChar = '*', char bChar = ' ') const = 0; 

};
// << overloads are the same for all shapes.
  std::ostream& operator<< (std::ostream& out, const Shape& shape); //overload to print shape information

  std::ostream& operator<< (std::ostream& out, const Grid& g); //overload to print drawing of shape

#endif
