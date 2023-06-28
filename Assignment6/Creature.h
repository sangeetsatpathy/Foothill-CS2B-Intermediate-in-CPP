#pragma once
#include <string>

namespace cs_creature {
    class Creature {
    private:
        int strength;                 // how much damage this Creature inflicts
        int hitpoints;                // how much damage this Creature can sustain
        static const int DEFAULT_STRENGTH = 10;
        static const int DEFAULT_HITPOINTS = 10;
    public:
        Creature();                   // initialize to human, 10 strength, 10 hitpoints
        Creature(int newStrength, int newHitpoints);
        virtual int getDamage() const;        // returns the amount of damage this Creature
        // inflicts in one round of combat
        virtual std::string getSpecies() const = 0;


        // also include appropriate accessors and mutators    
        int getStrength() const;
        int getHitpoints() const;
        void subtractHitpoints(int damage);
    };
}