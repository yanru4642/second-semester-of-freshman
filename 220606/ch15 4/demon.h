#pragma once
#include <string>
#include "creature.h"
using namespace std;

class Demon :public Creature {
public:
	Demon();
	Demon(int newType, int newStrength, int newHit);
	virtual int getDamage();
};