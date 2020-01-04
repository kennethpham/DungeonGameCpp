#include "assassin.h"

Assassin::Assassin()  // Uses base Character to set stats 
{
	stats[currHP] = stats[HP] -= 2;
	stats[ATK] += 2;
	stats[DEF] -= 5;
	name = "Assassin";
}

int Assassin::attack() const
{
	int roll = rand() % 100 + 1; // When Assassin attacks, a number is rolled from 1 to 100 
	if (roll <= critChance)
	{
		std::cout << "A critical hit!" << std::endl;
		return stats[ATK] * critDamage; // If the number is the critChance, the Assassin crits and does damage
	}                                    //based on his critDamage
	else
	{
		return stats[ATK]; // If he doesn't "crit", he just does the normal amount of damage 
	}
}

bool Assassin::takeDamage(int dmg)
{
	if (dmg == 0)
		return true;
	int roll = rand() % 100 + 1; // When the Assassin is to be attacked, a number is rolled from 1 to 100
	if (roll <= evadeChance)
	{
		std::cout << "You evaded the attack!" << std::endl;
	}
	else
	{
		int reducedDmg = dmg - stats[DEF]; // Otherwise, the damage taken by the assassin is calculated normally
		reducedDmg = reducedDmg <= 0 ? 1 : reducedDmg;
		stats[currHP] -= (reducedDmg);
	}
	return stats[currHP] <= 0 ? false : true;
}