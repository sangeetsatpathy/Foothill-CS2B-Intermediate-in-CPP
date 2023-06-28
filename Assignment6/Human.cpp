#include "Human.h"
#include <iostream>
using namespace std;

namespace cs_creature {

	Human::Human() : Creature() {}






	Human::Human(int strength, int hitpoints) : Creature(strength, hitpoints) {}







	string Human::getSpecies() const {
		return "human";
	}







	
}