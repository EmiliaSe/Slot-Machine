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
    cout << "please enter a bet smaller or equal to " << t << endl;
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

int SlotMachine::display(int bet){
    //names of each shape
    std::string n0= reel[0]->getName();
    std::string n1= reel[1]->getName();
    std::string n2= reel[2]->getName();

    //screen areas of each shape
    int a0 = reel[0]->screenArea();
    int a1 = reel[1]->screenArea();
    int a2 = reel[2]->screenArea();

    //add a print statement with the names and dimensions of each shape!
    

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



void SlotMachine::run(){
    srand(time(NULL)); //calls this once to seed the random number generator
    welcome();
    t = 10;  //not currently necessary, but here as reminder to modify if user chooses a different number

    while (t>0){ //step 4
        int bet{prompt()}; //step 5
            if (bet==0){
                cout << "Thanks for playing, come back soon! \n";
                cout << "Be sure you cash your remaining " << t << " tokens at the bar! \n"; 
                cout << "Game over." << endl;
                break; //quit the game if player bets 0
            }
        make_shapes(); //steps 6-19
        printReel(); //step 20
        //step 21 compute token win or loss
        int result = display(bet); //this line covers steps 21 and 23 (the order makes no difference in game play. the player just sees the bet result before the current tokesn are updated)
        t +=result; //step 22 update current tokens
        cout << "You currently have " << t << " tokens" << endl;
        //display message (call function display()) oops, implemented differently, maybe need to change this!
    }
    cout << "You just ran out of tokens. Better luck next time! \n";
    cout << "Game Over." << endl;

}