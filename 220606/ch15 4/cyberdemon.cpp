#include <iostream>
#include <string>
#include "cyberdemon.h"
using namespace std;

Cyberdemon::Cyberdemon() :Demon() { setType(1); }

Cyberdemon::Cyberdemon(int newStrength, int newHit) :Demon(1, newStrength, newHit) {}

int Cyberdemon::getDamage() {
	int damage = Demon::getDamage();
	return damage;
}