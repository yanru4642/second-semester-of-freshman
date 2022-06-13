#include "dice.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

Dice::Dice(){
	srand(time(NULL));
	numSides = 6;
}	
Dice::Dice(int numSides){
	srand(time(NULL));
	this->numSides = numSides;
}
int Dice::rollDice() const {
	cout << "Dice function    ";
	return (rand() % numSides) + 1;
}