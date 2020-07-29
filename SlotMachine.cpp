//Emilia Segura, 40138440

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <typeinfo>

#include "SlotMachine.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Rhombus.h"
#include "RightTriangle.h"
#include "AcuteTriangle.h"

using std::cout;
using std::endl;
using std::cin;



void SlotMachine::welcome(int t){ //function to display welcome message an initial number of tokens at the start of game
    cout << "Welcome to 3-Reel Lucky Slot Machine Game!\n";
    cout << "Each reel will randomly display one of four shapes, each in 25 sizes.\n";
    cout << "To win 3 x bet, get 2 similar shapes AND 2 shapes with equal Scr Areas\n";
    cout << "To win 2 x bet, get 3 similar shapes\n";
    cout << "To win 1 x bet, get (Middle) Scr Area > (Left + Right) Scr Areas\n";
    cout << "To win or lose nothing, get same Left and Right shapes\n";
    cout << "Otherwise, you lose your bet.\n";
    cout << "You start with " << t << " free slot tokens" <<endl;

}

//prompt for user to enter their bet, checks that input is an integer <= available tokens
int SlotMachine::prompt(int t){ 
std::string bad_data;
int bet;
cout << "How much would you like to bet (enter 0 to quit)" << endl;
cin >> bet;
while(! cin || bet > t){ //while not an int or int too big
    cin.clear(); //reset cin to a good state
    std::getline(cin, bad_data);
    cout << "please enter a bet smaller or equal to " << t << endl;
    cin >> bet;
}
std::getline(cin, bad_data);
return bet; //returns a valid bet
}

void SlotMachine::make_shapes(){
   for (int k=0; k<3; k++){
       make_shape(k); //call make shape 3 times
   }
} // Step 6-19


void SlotMachine::make_shape(int k){
    
    int n = generateRandom(0,3); //generate random n between 0 and 3
    int w = generateRandom(1,25); //genereate random w between 1 and 25

    switch (n){
        case 0: //rhombus
            reel[k].reset(new Rhombus(w)); //smart pointer to Rhombus
            break;

        case 1: //acute triangle
            reel[k].reset(new AcuteTriangle(w)); //smart pointer to Acute Triangle
            break;

        case 2: //right triangle
            reel[k].reset(new RightTriangle(w)); //smart pointer to Right Triangle
            break;

        case 3: //rectangle
            int h = generateRandom(1,25); //randomly generate height between 1 and 25
            reel[k].reset(new Rectangle(w,h)); //smart pointer to Rectangle
            break;
    }
} // Steps 7-18

int SlotMachine::generateRandom(int lower, int upper) { //generate a random int to be used to create shapes
    return lower + ( rand() % ( upper - lower + 1 ));  //restricts the random number to the desired range
}

void SlotMachine::printReel(){  //function to display the three shapes side by side with border as in assignment instructions
    int w0 = reel[0]->boxWidth();
    int w1 = reel[1]->boxWidth();
    int w2 = reel[2]->boxWidth();

    int h0 = reel[0]->boxHeight();
    int h1 = reel[1]->boxHeight();
    int h2 = reel[2]->boxHeight();

    Grid box_0 = reel[0]->draw(); 
    Grid box_1 = reel[1]->draw();
    Grid box_2 = reel[2]->draw();

    int height = std::max({h0, h1,h2}); //height of tallest object becomes height of reel (smaller objects will just have blank space below)

    //top row 
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
    //prints names and dimensions of the three shapes
    cout << "(" <<reel[0]->getName() <<", " << h0 <<", "<< w0 <<") ";
    cout << "(" <<reel[1]->getName() <<", " << h1 <<", "<< w1 <<") ";
    cout << "(" <<reel[2]->getName() <<", " << h2 <<", "<< w2 <<")"<<endl;
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

int SlotMachine::display(int bet){ //calculates win or loss on a bet and displays appropriate message to user (steps 21 and 23) Returns number of tokents won (negative if loss)
    //names of each shape
    std::string n0= reel[0]->getName();
    std::string n1= reel[1]->getName();
    std::string n2= reel[2]->getName();

    //screen areas of each shape
    int a0 = reel[0]->screenArea();
    int a1 = reel[1]->screenArea();
    int a2 = reel[2]->screenArea();    

    if (((n0==n1)|| (n0==n2) ||(n1==n2)) && ((a0==a1)|| (a0==a2) ||(a1==a2)) ) { //case 3X bet
        cout << "Jackpot! 2 Similar Shapes AND 2 Equal Screen Areas\n";
        cout << "Congratulations you win 3X your bet :" << 3*bet <<endl;
        return 3*bet;
        }
    else if (n0==n1 && n0==n2){ //case 2X bet
        cout <<"Three similar shapes\n";
        cout << "Congratulations you win 2X your bet :" << 2*bet <<endl;
        return 2*bet;
    } 
    else if (a1 > (a0+a2)) { //case 1X bet
        cout << "Middle > Left + Right, in Screen Areas\n";
        cout << "Congratulations you win 1X your bet :" << bet <<endl;
        return bet;
        } 
    else if (n0 == n2) { //case 0x bet
        cout << "Lucky this time!\n";
        cout << "You don’t win, you don’t lose, your are safe!" <<endl;
        return 0;
        }
    else { //-1 bet
        cout <<"Oh No!\nYou lose your bet" << endl;
        return -bet;
    }
}



void SlotMachine::run(int t){
    srand(time(NULL)); //calls this once to seed the random number generator
    welcome(t);

    while (t>0){ //step 4
        int bet{prompt(t)}; //step 5
            if (bet==0){
                break; //quit the game if player bets 0
            }
        make_shapes(); //steps 6-19
        printReel(); //step 20
        int result = display(bet); //this line covers steps 21 and 23 (the order makes no difference in game play. the player just sees the bet result before the current tokesn are updated)
        t +=result; //step 22 update current tokens
        cout << "You currently have " << t << " tokens" << endl;
    }

    if (t ==0 ) { //when player loses
    cout << "You just ran out of tokens. Better luck next time! \n";
    }
    else { //when player quits still having tokens left
        cout << "Thanks for playing, come back soon! \n";
        cout << "Be sure you cash your remaining " << t << " tokens at the bar! \n"; 
    }
    cout << "Game Over" << endl;
}