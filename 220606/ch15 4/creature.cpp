#include <iostream>
#include <string>
#include "creature.h"
using namespace std;

Creature::Creature() {
	type = -1;
	strength = -1;
	hitpoints = -1;
}
Creature::Creature(int newType, int newStrength, int newHit) {
	type = newType;
	strength = newStrength;
	hitpoints = newHit;
}
int Creature::getDamage() {
	int damage;
	damage = (rand() % strength) +1;
	cout << getSpecies() << " attacks for " << damage << " points!" << endl;
	//balrogs can attack twice
	
	return damage;
}
string Creature::getSpecies() {
	switch (type) {
	case 0:
		return "Human";
	case 1:
		return "Cyberdemon";
	case 2:
		return "Balrog";
	case 3:
		return "Elf";
	default:
		return "Unknown";
	}
}