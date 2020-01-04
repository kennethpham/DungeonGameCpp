#include "monster.h"


Monster::Monster(std::string monsterName, int hp, int a, int d, std::string aN, int aP) : name(monsterName), move(aN, aP), status(-1) {
	stats.push_back(hp);
	stats.push_back(a);
	stats.push_back(d);

}

void Monster::setStat(int stat, int amount) {
	stats[stat] = amount;
}

void Monster::setGold(int amt) {
	gold = amt;
}

int Monster::getGold() const {
	return gold;
}

int Monster::getStatus() const {
	return status;
}

std::string Monster::getStrStatus() const {
	if (status == PSN) {
		return "PSN";
	}
	else if (status == PAR) {
		return "PAR";
	}
	else if (status == SLP) {
		return "SLP";
	}
	else {
		return "";
	}
}

void Monster::setStatus(int status) {
	this->status = status;

	if (status == SLP)
		sleepCount = 3;
}

int Monster::getAbilityPower() const {
	return move.power;
}

int Monster::getATK() const {
	return stats[ATK];
}

int Monster::getDEF() const {
	return stats[DEF];
}

int Monster::getHP() const {
	return stats[HP];
}

void Monster::healMonster(int amt) {
	stats[HP] += amt;
}

std::string Monster::getMonsterName() const {
	return name;
}

std::string Monster::getAbilityName() const {
	return move.abilityName;
}

int Monster::attack() {

	if (status == SLP) {
		sleepCount--;

		if (sleepCount > 0) {
			std::cout << this->name << " is fast asleep" << std::endl;
			return 0;
		}
		else {
			std::cout << this->name << " woke up!" << std::endl;
			status = -1; //no status
		}
	}
	else if (status == PAR) {
		if (rand() % 100 < 35) { //35% chance to not attack
			std::cout << this->name << " cannot move due to paralysis!" << std::endl;
			return 0;
		}
	}

	if (rand() % 9 % 3 == 0) { //special attack - should be 33% for special and 66% for normal, but this method has mod bias
		return -static_cast<int>(stats[ATK] + (move.power * 1.5)); // a negative is used to indicate the the attack is a special one (for display purposes in 'Battle' class)
	}
	else { //regular attack
		return stats[ATK];
	}
}

bool Monster::takeDamage(int dmg) {
	int reducedDmg = dmg - stats[DEF];
	reducedDmg = reducedDmg < 0 ? 1 : reducedDmg;
	stats[HP] -= (reducedDmg);

	return stats[HP] <= 0 ? false : true;
}

bool Monster::takePoisonDamage(int dmg) { //defense doesn't affect poison damage
	stats[HP] -= (dmg);
	return stats[HP] <= 0 ? false : true;
}