#pragma once
#include <string>
#include "demon.h"
using namespace std;

class Balrog :public Demon {
public:
	Balrog();
	Balrog(int newStrength, int newHit);
	virtual int getDamage();
	string getSpecies() { return "Balrog"; }
};