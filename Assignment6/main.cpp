#include "Creature.h"
#include "Balrog.h"
#include "Demon.h"
#include "Elf.h"
#include "Cyberdemon.h"
#include "Human.h"

#include <iostream>

using namespace cs_creature;


void battleArena(Creature& creature1, Creature& creature2) {
	while (creature1.getHitpoints() > 0 && creature2.getHitpoints() > 0) {
		int dmg1 = creature1.getDamage();
		int dmg2 = creature2.getDamage();
		creature1.subtractHitpoints(dmg2);
		creature2.subtractHitpoints(dmg1);
	}
	if (creature1.getHitpoints() > 0 && creature2.getHitpoints() <= 0) {
		cout << creature1.getSpecies() << " wins!" << endl;
	}
	else if (creature1.getHitpoints() <= 0 && creature2.getHitpoints() > 0) {
		cout << creature2.getSpecies() << " wins!" << endl;
	}
	else {
		cout << "Tie" << endl;
	}
}







int main()
{
	srand(static_cast<unsigned>(time(nullptr)));

	Elf e(50, 50);
	Balrog b(50, 50);

	battleArena(e, b);
}
