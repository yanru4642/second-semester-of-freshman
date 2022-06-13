#include <iostream>
#include <string>
#include "balrog.h"
using namespace std;

Balrog::Balrog() :Demon() { Creature::setType(2); }

Balrog::Balrog(int newStrength, int newHit) :Demon(2, newStrength, newHit) {}

int Balrog::getDamage() {
	int damage = Demon::getDamage();
	int damage2 = (rand() % getStrength()) + 1;
	cout << "Balrog speed attack inflicts " << damage2
		<< " additional damage points!" << endl;
	damage += damage2;
	return damage;
}