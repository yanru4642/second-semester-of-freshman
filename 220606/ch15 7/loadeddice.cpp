#include "loadeddice.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

LoadedDice::LoadedDice():Dice() {}
LoadedDice::LoadedDice(int numSides):Dice(numSides) {}

int LoadedDice::rollDice() const {
	if (rand()%2==0){
		return numSides;
	}
	else {
		return (rand() % numSides) + 1;
	}
}