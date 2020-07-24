//Emilia Segura, 40138440
#include <array>
#include "Shape.h"

#ifndef SLOTMACHINE_H
#define SLOTMACHINE_H

//copied from p.22 of assignment
class SlotMachine
{
private: //private was added be me, 
    std::array<std::unique_ptr<Shape>, 3> reel{}; //uncommment once Shape is implemented
    void make_shapes(); // Step 6-19
    void make_shape(int k); // Steps 7-18
    void display(); // Step 23

    //added by me
    int t = 10; //keep track of how many tokens, default is 10
    void welcome(); //display initial welcome message
    int prompt(); //read bet
    int generateRandom(int lower, int upper); //generate a random int in range bounded by lower and upper

public:
    SlotMachine() = default;
    SlotMachine(const SlotMachine&) = delete; // copy ctor 
    SlotMachine(SlotMachine&&) = delete; // move ctor
    SlotMachine& operator=(const SlotMachine&) = delete; // copy assignment 
    SlotMachine& operator=(SlotMachine&&) = delete; // move assignment 
    virtual ~SlotMachine() = default;
    void run();
};

#endif