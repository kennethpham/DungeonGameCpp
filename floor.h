#ifndef floor_h
#define floor_h

#include <vector>
#include <iostream>
#include <iomanip>
#include <random>

#include "character.h"
#include "inventory.h"
#include "no_event.h" //List of events
#include "battle.h"
#include "ladder.h"
#include "merchant.h"
#include "chest.h"


class Floor {
private:
	static int floorNum;
	const int dimension;
	Character& character;
	Inventory& i;
	std::vector<std::vector<Event*>> floor;
	int ladderX, ladderY;
public:
	Floor(Character& character, Inventory& inv);

	~Floor() {
		for (int r = 0; r < dimension; r++) {
			for (int c = 0; c < dimension; c++) {
				delete floor[r][c];
			}
		}
	}

	bool revealLadder();
	void revealAll();
	void hideAll();

	bool moveCharacter(char direction);

	int getRand() const {
		return std::rand() % dimension;
	}

	friend std::ostream& operator<<(std::ostream& out, const Floor& f);
};

std::ostream& operator<<(std::ostream& out, const Floor& f);
#endif //floor_h 
