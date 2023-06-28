#include "Demon.h"
#include <iostream>
using namespace std;
namespace cs_creature {
	Demon::Demon() : Creature() {}






	Demon::Demon(int strength, int hitpoints) : Creature(strength, hitpoints) {};






	string Demon::getSpecies() const {
		return "demon";
	}







	int Demon::getDamage() const {
		int dmg = Creature::getDamage();
		//cout << "attacks for " << dmg << " points!" << endl;
		if (rand() % 100 * 0.01 < DEMONIC_ATTACK_PROBABILITY) {
			dmg += DEMONIC_BONUS_DAMAGE;
			cout << "Demonic attack inflicts " << DEMONIC_BONUS_DAMAGE << " additional damage points!" << endl;
		}
		return dmg;
	}
}