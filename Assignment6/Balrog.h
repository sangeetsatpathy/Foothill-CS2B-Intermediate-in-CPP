#pragma once
#include "Demon.h"
#include <string>
namespace cs_creature {
	class Balrog : public Demon {
	public:
		Balrog();
		Balrog(int strength, int hitpoints);
		string getSpecies() const;
		int getDamage() const;
	};

}