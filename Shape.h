//Emilia Segura, 40138440

#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <vector>
#include <iostream>

//using Grid = vector<vector<char>>;  see 7.2, 7.3 in instructions....


class Shape{

private:
    const int id; //figure out what to do with this
    std::string name;
    std::string description;

    static int counter; //used to generate the unique id.


public:
    Shape(const std::string& name, const std::string& description); //Constructor
    virtual ~Shape() = default; //destructor for now default, maybe change if needed!

    //getters
    int getId() const;
    std::string getName() const;
    std::string getDescription() const;

    //setters
    void setName(std::string& name);
    void setDescription(std::string& description);

    std::string toString() const; //only need to implement here in base class I think

    //pure virutal functions, only implemented in derived classes
    virtual double area() const = 0; //check return types
    virtual double perimeter() const= 0;
    virtual int screenArea() const= 0;
    virtual int screenPerimeter() const = 0;
    virtual int boxHeight() const = 0;
    virtual int boxWidth() const = 0;

   // will need to figure this out!
  //  virtual Grid draw(char fChar = ’*’, char bChar = ’ ’) const = 0;  see 7.2, 7.3 in instructions....

};


  std::ostream& operator<< (std::ostream& out, const Shape& shape);

#endif
