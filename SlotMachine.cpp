//Emilia Segura, 40138440

#include <iostream>
#include <ctime>
#include <cstdlib>

#include "SlotMachine.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Rhombus.h"
#include "RightTriangle.h"
#include "AcuteTriangle.h"

using std::cout;
using std::endl;
using std::cin;


//potentially modify to take user input to get #of tokens, or at least display right number of tokens.
void SlotMachine::welcome(){
    cout << "Welcome to 3-Reel Lucky Slot Machine Game!\n";
    cout << "Each reel will randomly display one of four shapes, each in 25 sizes.\n";
    cout << "To win 3 x bet, get 2 similar shapes AND 2 shapes with equal Scr Areas\n";
    cout << "To win 2 x bet, get 3 similar shapes\n";
    cout << "To win 1 x bet, get (Middle) Scr Area > (Left + Right) Scr Areas\n";
    cout << "To win or lose nothing, get same Left and Right shapes\n";
    cout << "Otherwise, you lose your bet.\n";
    cout << "You start with 10 free slot tokens" <<endl;

}

//prompt for user to enter their bet, checks that input is an integer <= available tokens
int SlotMachine::prompt(){ 
std::string bad_data;
int bet;
cout << "How much would you like to bet (enter 0 to quit)" << endl;
cin >> bet;
while(! cin || bet > this->t){ //while not an int or int too big
    cin.clear(); //reset cin to a good state
    std::getline(cin, bad_data);
    cout << "please enter a integer smaller or equal to " << t << endl;
    cin >> bet;
}
std::getline(cin, bad_data);
return bet;
}

void SlotMachine::make_shapes(){
    for (int k=0; k<3; k++){
        make_shape(k);
    }

} // Step 6-19


void SlotMachine::make_shape(int k){
    //generate random n between 0 and 3
    //genereate random w between 1 and 25
    int n = generateRandom(0,3);
    int w = generateRandom(1,25);

    switch (n){
        case 0: //rhombus
            reel[k].reset(new Rhombus(w));
            break;

        case 1: //acute triangle
            reel[k].reset(new AcuteTriangle(w));
            break;

        case 2: //right triangle
            reel[k].reset(new RightTriangle(w));
            break;

        case 3: //or default? rectangle
            int h = generateRandom(1,25); //randomly genereate height between 1 and 25
            reel[k].reset(new Rectangle(w,h));
            break;
    }

} // Steps 7-18

int generateRandom(int lower, int upper) {
    return lower + ( rand() % ( upper - lower + 1 ));  //restricts the random number to the desired range
}




void SlotMachine::run(){
    srand(time(NULL)); //calls this once to seed the random number generator
    welcome();
    t = 10;  //not currently necessary, but here as reminder to modify if user chooses a different number

    //step 3 Prepare an array reel of three elements to represent the three reels of the slot machine. Each array element is a smart pointer to a Shape object
    //reel already declared as member variable, not sure I need to do anything here

    while (t>0){ //step 4
        int bet{prompt()}; //step 5
        make_shapes(); //steps 6-19

        //step 20, print three reel shapes side by side
        //step 21 compute token win or loss
        //step 22 update current tokens
        //display message (call function display())
        //if player chooses to quit by entering 0 as bet figure out how that exits loop and says bye
    }
//display goodbye no more tokens

}