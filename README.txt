Emilia Segura, 40138440

Assignment 4


Program runs as assignement instructions specify.

Shape:
-Added a static private member int to generate the unique ids of each shape. (It is incremented at the creation of every shape)
-Every functionality that is shared by all objects is implemented in the abstract Shape class. All functions that depend on the type of shape are defined as pure virtual in the Shape class.

Triangle:
-Implemented area, box Height and box Width in Triangle as they are common to both Right and Acute Triangles.
-Triangle is an abstract class as it inherits from Shape and does not implement all the pure virtual functions defined in Shape.

Rectangle, Rhombus, RightTriangle, AcuteTriangle:
-As they inherit or define all virtual functions defined in Shape, they are concrete classes. They are each implemented based on their geometric attributes 

SlotMachine:
-private functions were added to SlotMachine class described in point 9.6 of assignment in order to simplify run()
-The goal was to make code clearer and easier to separate each step of algorithm
-One function signature was modified. void display() was changed to int display(int bet) in order to both calculate the result of the bet and display the appropriate message to the player