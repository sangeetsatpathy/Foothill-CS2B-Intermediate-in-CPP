#include "Creature.h"
#include <string>
#include <iostream>
using namespace std;

namespace cs_creature {
	int Creature::getDamage() const {
		int damage = (rand() % strength) + 1;
		cout << "The " << getSpecies() << " attacks for " << damage << " points!" << endl;
		return damage;
	}




	Creature::Creature() : strength(DEFAULT_STRENGTH), hitpoints(DEFAULT_HITPOINTS) {}






	Creature::Creature(int newStrength, int newHitpoints) : strength(newStrength), hitpoints(newHitpoints) {}





	int Creature::getHitpoints() const { return hitpoints; }





	int Creature::getStrength() const { return strength; }





	void Creature::subtractHitpoints(int damage) {
		hitpoints -= damage;
	}
}