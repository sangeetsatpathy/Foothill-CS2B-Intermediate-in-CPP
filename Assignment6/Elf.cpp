#include "Elf.h"
#include <iostream>

namespace cs_creature {

	Elf::Elf() : Creature() {}






	Elf::Elf(int strength, int hitpoints) : Creature(strength, hitpoints) {}








	string Elf::getSpecies() const {
		return "elf";
	}







	int Elf::getDamage() const {
		int dmg = Creature::getDamage();
		//cout << "The elf attacks for " << dmg << " points!" << endl;
		if (rand() % 100 * 0.01 < MAGICAL_ATTACK_PROBABILITY) {
			cout << "Magical attack inflicts " << dmg << " additional damage points!" << endl; //possible error with calculation
			dmg *= MAGICAL_ATTACK_MULTIPLIER;
		}
		return dmg;
	}
}