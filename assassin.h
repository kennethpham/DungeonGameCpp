#include <string>
#include <vector> 
#include "character.h"

class Assassin : public Character // A character that can critically strike for bonus damage, and evade attacks
{
private:
	int critChance = 10; // % chance of critting
	int critDamage = 2; // Factor that an attack increases in damage by when critting
	int evadeChance = 15; // % chance of dodging an attack 
public:
	Assassin();

	int attack() const;

	bool takeDamage(int dmg);
};