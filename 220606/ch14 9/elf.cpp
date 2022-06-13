#include <iostream>
#include <string>
#include "elf.h"
using namespace std;

Elf::Elf() :Creature() { setType(3); }

Elf::Elf(int newStrength, int newHit):Creature(3,newStrength,newHit){}

int Elf::getDamage() {
	int damage = Creature::getDamage();
	if (rand() % 10 < 1) {
		cout << "Magical attack doubles the damage points!" << endl;
		damage *= 2;
	}
	return damage;
}