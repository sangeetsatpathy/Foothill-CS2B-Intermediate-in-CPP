#pragma once
#include "Creature.h"
#include <string>
using namespace std;

namespace cs_creature {
	class Elf : public Creature {
	private:
		static constexpr double MAGICAL_ATTACK_PROBABILITY = 0.5;
		static constexpr double MAGICAL_ATTACK_MULTIPLIER = 2.0;
	public:
		Elf();
		Elf(int strength, int hitpoints);
		string getSpecies() const;
		int getDamage() const;

	};
}