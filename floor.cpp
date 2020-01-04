#include "floor.h"

int Floor::floorNum = 0;

Floor::Floor(Character& character, Inventory& inv) : character(character), i(inv), dimension(10), floor(dimension, std::vector<Event*>(dimension)) {
	floorNum++;
	int randNum;
	int merchX, merchY;

	//Set Ladder
	do {
		ladderX = getRand();
		ladderY = getRand();
	} while (ladderX == 0 && ladderY == 4); //don't spawn ladder right where character lands
	floor[ladderX][ladderY] = new Ladder(character, i);

	do {
		merchX = getRand();
		merchY = getRand();
	} while ((merchX == 0 && merchY == 4) || (merchX == ladderX && merchY == ladderY)); //don't spawn merchant right where character lands
	floor[merchX][merchY] = new Merchant(character, i);

	//Generate # between 0 - 50; 
	//0 - 5 : monster, 6 - 7 = chest, else = no event
	for (int r = 0; r < dimension; r++) {
		for (int c = 0; c < dimension; c++) {
			if (floor[r][c] == 0) { //uninitialized coordinate
				randNum = rand() % 51;
				if (randNum >= 0 && randNum <= 5) {
					floor[r][c] = new Battle(character, i, floorNum);
				}
				else if (randNum >= 6 && randNum <= 7) {
					floor[r][c] = new Chest(character, i);
				}
				else {
					floor[r][c] = new NoEvent(character, i);
				}
			}
		}
	}

	for (int r = 0; r < dimension; r++) {
		for (int c = 0; c < dimension; c++) {
			if (floor[r][c] == 0) { //uninitialized coordinate
				randNum = rand() % 51;
				if (randNum >= 0 && randNum <= 5) {
					floor[r][c] = new Battle(character, i, floorNum);
				}
				else if (randNum >= 6 && randNum <= 7) {
					floor[r][c] = new Chest(character, i);
				}
				else {
					floor[r][c] = new NoEvent(character, i);
				}
			}
		}
	}

	//0,4 is spawn point, so make it a revealed NoEvent Tile
	delete floor[0][4];
	floor[0][4] = new NoEvent(character, i);
	floor[0][4]->visit(); //reveal
}

bool Floor::moveCharacter(char direction) {
	int x = character.getX(), y = character.getY();
	bool moved;
	switch (direction) {
	case 'w': //Up
		if (y - 1 < 0) {
			moved = false;
		}
		else {
			character.setCoor(x, y - 1);
			moved = true;
		}
		break;
	case 'd': //Right
		if (x + 1 >= dimension) {
			moved = false;
		}
		else {
			character.setCoor(x + 1, y);
			moved = true;
		}
		break;
	case 's': //Down
		if (y + 1 >= dimension) {
			moved = false;
		}
		else {
			character.setCoor(x, y + 1);
			moved = true;
		}
		break;
	case 'a': //Left
		if (x - 1 < 0) {
			moved = false;
		}
		else {
			character.setCoor(x - 1, y);
			moved = true;
		}
		break;
	default:
		return false; //Int on range [0,4] not entered
	}

	floor[character.getY()][character.getX()]->performEvent();

	return moved;
}

std::ostream& operator<<(std::ostream& out, const Floor& f) {
	out << std::left;
	int charX = f.character.getX(), charY = f.character.getY();

	out << "Currently on " << f.character.getCurrentFloor() + 1 << "F" << std::endl;
	for (int r = 0; r < f.dimension; r++) {
		for (int c = 0; c < f.dimension; c++) {
			out << std::setw(4);
			if (r == charY && c == charX)
				out << "YOU";
			else
				out << f.floor[r][c]->getSymbol();
			out << " ";
		}
		out << std::endl << std::endl;
	}
	out << f.character << std::endl;

	return out;
}

void Floor::revealAll() {
	for (int r = 0; r < dimension; r++) {
		for (int c = 0; c < dimension; c++) {
			floor[r][c]->visit();
		}
	}
}

void Floor::hideAll() {
	for (int r = 0; r < dimension; r++) {
		for (int c = 0; c < dimension; c++) {
			floor[r][c]->unVisit();
		}
	}
}

bool Floor::revealLadder() {
	if (!floor[ladderX][ladderY]->getIsVisited()) {
		floor[ladderX][ladderY]->visit();
		return true;
	}

	return false;
}