#include "Cyberdemon.h"
#include <iostream>

namespace cs_creature {
	Cyberdemon::Cyberdemon() : Demon() {}







	Cyberdemon::Cyberdemon(int strength, int hitpoints) : Demon(strength, hitpoints) {}






	string Cyberdemon::getSpecies() const {
		return "cyberdemon";
	}








}