#pragma once
#include "Creature.h"
#include <string>
using namespace std;

namespace cs_creature {
	class Demon : public Creature {
	private:
		static constexpr double DEMONIC_ATTACK_PROBABILITY = 0.25;
		static const int DEMONIC_BONUS_DAMAGE = 50;
	public:
		Demon();
		Demon(int strength, int hitpoints);
		string getSpecies() const;
		int getDamage() const;
	};
}