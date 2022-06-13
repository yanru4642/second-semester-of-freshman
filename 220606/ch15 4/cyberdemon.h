#pragma once
#include <string>
#include "demon.h"
using namespace std;

class Cyberdemon :public Demon {
public:
	Cyberdemon();
	Cyberdemon(int newStrength, int newHit);
	virtual int getDamage();
	string getSpecies() { return "Cyberdemon"; }
};