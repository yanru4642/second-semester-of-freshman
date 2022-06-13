#pragma once
#include <string>
#include "creature.h"
using namespace std;

class Elf:public Creature {
public:
	Elf();
	Elf(int newStrength, int newHit);
	virtual int getDamage();
	string getSpecies() { return "Elf"; }
};