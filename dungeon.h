#ifndef dungeon_h
#define dungeon_h

#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <ctime>
#include <random>
#include <sstream>

#include "floor.h"
#include "character.h"
#include "inventory.h"
#include "final_battle.h"

class Dungeon {
private:
	const int numFloors = 10;
	std::vector<Floor*> dungeon;
	Character* ch;
	Inventory inv;
	fb::FinalBattle f;
	std::string in; 
	char input;
public:
	Dungeon(Character* c) : ch(c), inv(*ch, 0), f(*ch, inv) {
		std::srand(static_cast<unsigned>(std::time(0)));
		for (int i = 0; i < numFloors; i++)
			dungeon.push_back(new Floor(*ch, inv));
		int entranceX = 4;
		int entranceY = 0;
		ch->setCoor(entranceX, entranceY);
	}

	~Dungeon() {
		for (int i = 0; i < numFloors; i++)
			delete dungeon[i];
	}

	void play();
	void printVictory() const;

};
#endif  //dungeon_h
