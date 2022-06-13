#include <iostream>
#include <string>
#include "demon.h"
using namespace std;

Demon::Demon():Creature() {}
Demon::Demon(int newType, int newStrength, int newHit):Creature(newType,newStrength,newHit) {}

int Demon::getDamage() {
	int damage = Creature::getDamage();
	//demon inflicts 50 additional damage with 5% chance
	if (rand() % 100 < 5) {
		cout << "Demonic attack inflicts 50 additional damage points!" << endl;
		damage += 50;
	}
	return damage;
}