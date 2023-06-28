#include "Balrog.h"
#include <iostream>

namespace cs_creature {

	Balrog::Balrog() : Demon() {}






	Balrog::Balrog(int strength, int hitpoints) : Demon(strength, hitpoints) {}






	string Balrog::getSpecies() const {
		return "balrog";
	}







	int Balrog::getDamage() const {
		//cout << "The balrog ";
		int dmg = Demon::getDamage();
		int dmg2 = (rand() % getStrength()) + 1;
		cout << "Balrog speed attack inflicts " << dmg2 << " additional damage points!" << endl;
		dmg += dmg2;
		return dmg;
	}
}