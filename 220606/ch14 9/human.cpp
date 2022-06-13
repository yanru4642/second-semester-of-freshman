#include <iostream>
#include <string>
#include "human.h"
using namespace std;

Human::Human() :Creature() { setType(0); }

Human::Human(int newStrength, int newHit) :Creature(0, newStrength, newHit) {}

int Human::getDamage(){
	int damage = Creature::getDamage();
	return damage;
}