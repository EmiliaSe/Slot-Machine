//Emilia Segura, 40138440
#include <array>

#ifndef SLOTMACHINE_H
#define SLOTMACHINE_H

//copied from p.22 of assignment
class SlotMachine
{
private: //private was added be me, 
  //  std::array<std::unique_ptr<Shape>, 3> reel{}; uncommment once Shape is implemented
    void make_shapes(); // Step 6-19
    void make_shape(int k); // Steps 7-18
    void display(); // Step 23
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