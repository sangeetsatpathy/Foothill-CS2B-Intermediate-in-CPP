#pragma once
#include <string>
#include "Creature.h"

namespace cs_creature {
	class Human : public Creature {
	public:
		Human();
		Human(int strength, int hitpoints);
		std::string getSpecies() const;
	};
}