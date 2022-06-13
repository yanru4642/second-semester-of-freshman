#pragma once
#include <string>
using namespace std;

class Creature {
public:
	Creature();
	Creature(int newType, int newStrength, int newHit);
	virtual int getDamage();

	void setType(int inType) { type = inType; }
	void setStrength(int inStrength) { strength = inStrength; }
	void setHitpoints(int inHitpoints) { hitpoints = inHitpoints; }
	int getType() { return type; }
	int getStrength() { return strength; }
	int getHitpoints() { return hitpoints; }
	string getSpecies(); //return type of species
private:
	int type; //0 human, 1 cyberdemon, 2balrog, 3 elf
	int strength; //how much damage we can inflict
	int hitpoints; //how much damage we can sustain
};