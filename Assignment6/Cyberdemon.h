#pragma once
#include "Demon.h"

namespace cs_creature {
	class Cyberdemon : public Demon {
	public:
		Cyberdemon();
		Cyberdemon(int strength, int hitpoints);
		string getSpecies() const;
	};
}