//Emilia Segura, 40138440
#include <array>
#include "Shape.h"

#ifndef SLOTMACHINE_H
#define SLOTMACHINE_H

//copied from p.22 of assignment
class SlotMachine
{
private: //private was added be me, 
    std::array<std::unique_ptr<Shape>, 3> reel{}; 
    void make_shapes(); // Step 6-19
    void make_shape(int k); // Steps 7-18
    int display(int bet); // Step 23 modified from signature given in assignment instructions void display()

    //added by me
    int t = 10; //keep track of how many tokens, default is 10
    void welcome(); //display initial welcome message
    int prompt(); //read bet
    int generateRandom(int lower, int upper); //generate a random int in range bounded by lower and upper
    void printReel(); 
    void printRow(const int& i, const int& h, const int& w, const Grid& box); 

    // int betResult(int bet);

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