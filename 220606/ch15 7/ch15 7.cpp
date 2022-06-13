#include <iostream>
#include <string>
#include "loadeddice.h"
using namespace std;

int rollTwoDice(const Dice& die1, const Dice& die2);

int main() {
    int sides; //number of dice side
    cout << "Enter the first dice's side number> ";
    cin >> sides;
    if (sides<1)    {
        cout << "side number should >=1" << endl;
        exit(1);
    }
    LoadedDice dice1(sides);
    cout << "Enter the second dice's side number> ";
    cin >> sides;
    if (sides < 1) {
        cout << "side number should >=1" << endl;
        exit(1);
    }
    LoadedDice dice2(sides);

    //try 10 times
    cout << "Rolling two dice 10 times..." << endl;
    for (int i = 0; i < 10; i++)    {
        cout << "Sum of two dice: " << rollTwoDice(dice1, dice2) << endl;
    }

    system("pause");
    return 0;
}

int rollTwoDice(const Dice& die1, const Dice& die2) {
    return die1.rollDice() +die2.rollDice();
}