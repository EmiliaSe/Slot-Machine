//Emilia Segura, 40138440

#ifndef SHAPE.H
#define SHAPE.H

#include <string>


class Shape{

private:
    int id; //figure out what to do with this
    std::string name;
    std::string description;

    static int counter; //used to generate the unique id.


public:
    Shape(std::string& name, std::string& description); //Constructor
    virtual ~Shape(); //destructor

    int getId() const;
    std::string getName() const;
    std::string getDescription() const;

    void setName(std::string& name);
    void setDescription(std::string& description);

    std::string toString();

//ARE THESE SUPPOSE TO BE VIRTUAL??? WHAT GOES IN BASE VS DERIVED CLASSES
    double area(); //check return types
    double perimeter();
    int screenArea();
    int screenPerimeter();
    void draw();
    int boxHeight();
    int boxWidth();

};

#endif
