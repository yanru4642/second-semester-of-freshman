#pragma once
#include <string>
#include "creature.h"
using namespace std;

class Human :public Creature {
public:
	Human();
	Human(int newStrength, int newHit);
	virtual int getDamage();
	string getSpecies() { return "Human"; }
};