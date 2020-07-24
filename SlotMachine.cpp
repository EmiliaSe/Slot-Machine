//Emilia Segura, 40138440

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>

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

    // cout << "Shape # " << k <<endl;
    // cout << "random n is " << n <<endl;
    // cout << "random w is  " << w <<endl;

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

        case 3: //rectangle
            int h = generateRandom(1,25); //randomly generate height between 1 and 25
            reel[k].reset(new Rectangle(w,h));
            break;
    }

} // Steps 7-18

int SlotMachine::generateRandom(int lower, int upper) {
    return lower + ( rand() % ( upper - lower + 1 ));  //restricts the random number to the desired range, is the pseudorandom enough?
}

void SlotMachine::printReel(){
    int w0 = reel[0]->boxWidth();
    int w1 = reel[1]->boxWidth();
    int w2 = reel[2]->boxWidth();

    int h0 = reel[0]->boxHeight();
    int h1 = reel[1]->boxHeight();
    int h2 = reel[2]->boxHeight();

    Grid box_0 = reel[0]->draw(); 
    Grid box_1 = reel[1]->draw();
    Grid box_2 = reel[2]->draw();

    int height = std::max({h0, h1,h2});

    //top row (bottom row should be the same)
    cout << '+' << std::string((w0+2), '-') << '+' << std::string((w1+2), '-') << '+' << std::string((w2+2), '-') << '+' << endl; 

    for (int i =0; i< height; ++i){ //outer loop (going row by row)
        cout << "| ";
        //loop for grid 0
        printRow(i,h0,w0,box_0);
        cout << " | ";
        //loop for grid 1
        printRow(i,h1,w1,box_1);
        cout << " | ";
        //loop for grid 2
        printRow(i,h2,w2,box_2);
        cout << " |" << '\n';
    }
    //bottom row
    cout << '+' << std::string((w0+2), '-') << '+' << std::string((w1+2), '-') << '+' << std::string((w2+2), '-') << '+' << endl; 
}

void SlotMachine::printRow(const int& i, const int& h, const int& w, const Grid& box){ //helper for printReel. goes through a row of the grid
    for (int j=0; j<w; ++j){
            if (i<h){
            cout << box[i][j];
            }
            else { //when the shape is smaller than total height of reel, blank spaces are printed
                cout << ' ';
            }
        }
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
        //temporary solution just to test
        Grid box_0 = reel[0]->draw(); 
        Grid box_1 = reel[1]->draw();
        Grid box_2 = reel[2]->draw();

        cout << box_0 << endl;
        cout << box_1 << endl;
        cout << box_2 << endl;

        printReel();
        //step 21 compute token win or loss
        //step 22 update current tokens
        //display message (call function display())
        //if player chooses to quit by entering 0 as bet figure out how that exits loop and says bye

        //temp for testing asking user for nbr tokens
        cout << "Enter how many tokens you have left " ;
        cin >> t;
    }
//display goodbye no more tokens

}