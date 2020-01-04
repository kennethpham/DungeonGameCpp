#ifndef MONSTER_H
#define MONSTER_H

#include <string>
#include <vector>
#include <random>
#include <iostream>

class Monster {
protected:
	std::string name;
	enum {HP, ATK, DEF, NumberOfStats}; //  need to name this enum as Character declares one with no name as well
	enum status { PSN, SLP, PAR, statusNum };
	std::vector<int> stats;
	int status;
	int sleepCount;
	int gold;

	struct ability {
		std::string abilityName;
		int power;

		//Constructor : aN = abilityName, aT = abilityType, aP = abilityPower
		ability(std::string aN, int aP) : abilityName(aN), power(aP) {}
	};

	ability move;

public:
	Monster(std::string monsterName, int hp, int a, int d, std::string aN, int aP);

	~Monster(){}

	virtual void printAscii() const {}
	virtual std::string aName() { return "Kibble"; } // These two lines are ONLY for Doggos 
	virtual int aPower() { return 20; }

	void setStat(int stat, int amount);

	void setGold(int amt);

	int getGold() const;

	int getStatus() const;

	std::string getStrStatus() const;

	void setStatus(int status);

	int getAbilityPower() const;

	int getATK() const;

	int getDEF() const;

	int getHP() const;

	void healMonster(int amt);

	std::string getMonsterName() const;

	std::string getAbilityName() const;

	virtual int attack();

	//This function will return TRUE if monster is still alive and FALSE if dead
	bool takeDamage(int dmg);

	bool takePoisonDamage(int dmg);
};
#endif