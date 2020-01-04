#ifndef BATTLE_H
#define BATTLE_H

#include <algorithm>
#include <random>
#include <vector>

#include "event.h"
//List of monsters
#include "angry_spider.h"
#include "berserker.h"
#include "bulky_orc.h"
#include "goblin.h"
#include "chimera.h"
#include "green_slime.h"
#include "necromancer.h"
#include "skeleton_king.h"
#include "golem.h"
#include "skeleton_soldier.h"

class Battle : public Event {
private:
	Monster * getRandMonster();

	int floorNumber;
	bool isDead;
	Monster* monster; //the current monster for the current battle

	static std::vector<Monster*> monsters; //ALL battle classes will push dynamic ptr to same vector so we won't have to worry about cleaning up somewhere else
public:
	Battle(Character& ch, Inventory& i, int f);

	~Battle();

	void performEvent();

	void monsterAttack(int maxHP);

	std::string getSymbol() const;

};

#endif
