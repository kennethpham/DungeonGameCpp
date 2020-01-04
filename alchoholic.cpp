#include "alcoholic.h"

Alcoholic::Alcoholic() // Uses base Character to set stats 
{
	stats[currHP] = stats[HP] += 2; // Temporary weighted stats for the Alcoholic
	stats[ATK] += 1;
	stats[DEF] += 1;
	name = "Alcoholic";
}

int Alcoholic::painOfAThousandHangovers() // The special attack of the Alcoholic
{
	const int manaCost = 15;
	if (stats[currMana] < manaCost) {
		std::cout << "Not enough mana!" << std::endl;
		return 0;
	}

	stats[currMana] -= manaCost;

	tooDrunk += 2; // Add two turns of the monster being hungover 
	return stats[ATK] / 2; // The attack will do damage based on half of his ATK stat
}

bool Alcoholic::takeDamage(int dmg)
{
	if (tooDrunk > 0) // If the monster is hungover, they are stunned and won't do damage to the Alcoholic
	{
		std::cout << "The strong alcholic brew negated the damage!" << std::endl;
		tooDrunk--; // Reduce turn counter of mHungover by one, no damage is taken
		return true;
	}
	else
	{
		int reducedDmg = (dmg * painLess) / 100 - stats[DEF]; // When taking damage, the dmg amount is converted by painLess %
		reducedDmg = reducedDmg <= 0 ? 1 : reducedDmg;
		stats[currHP] -= (reducedDmg);
	}
	return stats[currHP] <= 0 ? false : true;
}

void Alcoholic::displayMoves(){
	std::cout << "1. Pain of a Thousand Hangovers: deal damage and ignore damage for 2 turns  Damage: half of attack | Mana Cost: 15" << std::endl;
	for (unsigned i = 0; i < moves.size(); i++)
		std::cout << i + 2 << ". " << *moves[i] << std::endl;
}

int Alcoholic::useSpecial(int num, Monster* m) {
	int i = num - 1; //i is index in vector that has move
	if (i == 0) { //want to use pain of a thousand hangovers
		return painOfAThousandHangovers();
	}
	else {
		i--;
		if (!moves.at(i)->getCanUse()) { //We use at because it throws an exception
			std::cout << "\nThis ability is locked! Find a scroll to unlock it.\n" << std::endl;
			return 0;
		}
		//Deal with Mana cost
		if (moves[i]->getManaCost() > stats[currMana]) {
			std::cout << "Not enough mana!" << std::endl;
			return 0;
		}

		stats[currMana] -= moves[i]->getManaCost();

		//Then with status
		if (m->getStatus() < 0) { //greater than 0 means it has a status effect already
			m->setStatus(moves[i]->getStatusEffect());
		}

		//Then with damage
		return moves[i]->getDamage();
	}
}