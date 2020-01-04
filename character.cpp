#include "character.h"

Character::Character() : stats(NumberOfStats), xCoor(0), yCoor(0), currentFloor(0), money(0) {
	stats[HP] = stats[currHP] = 25;
	stats[Mana] = stats[currMana] = 15;
	stats[ATK] = 10;
	stats[DEF] = 12;

	moves.push_back(new Moves::ParalyzingShock);
	moves.push_back(new Moves::ToxicStar);
	moves.push_back(new Moves::ForbiddenChant);
}

Character::~Character() {
	for (unsigned i = 0; i < moves.size(); i++)
		delete moves[i];
}

void Character::displayMoves() {
	for (unsigned i = 0, j = 1; i < moves.size(); i++) {
		std::cout << j++ << ". " << *moves[i] << std::endl;
	}
}

int Character::useSpecial(int num, Monster* m) {
	int i = num - 1; //i is index in vector that has move


	if (!moves.at(i)->getCanUse()) {
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
	return moves[i]->getDamage() + stats[ATK];
}

void Character::setCoor(int newX, int newY) {
	xCoor = newX;
	yCoor = newY;
}

int Character::getX() const {
	return xCoor;
}

int Character::getY() const {
	return yCoor;
}

std::string Character::getName() const {
	return name;
}

void Character::addMoney(int m) {
	money += m;
}

int Character::getMoney() const {
	return money;
}

void Character::setHP(int h) {
	stats[HP] = h;
}

bool Character::unlockRandomAbility() {
		int count = 0;
		for (std::vector<SpecialMove*>::iterator i = moves.begin(); i != moves.end(); i++) {
			if ((*i)->getCanUse())
				count++;
		}

		if (count == 3) {
			std::cout << "\nThe scroll lights up, but nothing seems to happen. Perhaps you've learned all the abilities?\n" << std::endl;
			return false;//no more moves to unlock
		}

		int r;
		do {
			r = rand() % 3;
		} while (moves[r]->getCanUse());

		moves[r]->setCanUse(true);
		std::cout << "\nThe scroll lights up and you gain its knowledge!\nYou now know: " << moves[r]->getMoveName() << "!\n" << std::endl;
		return true;
	}

void Character::setCurrHP(int h) {
	int amt = stats[currHP] + h;
	if (amt > stats[HP])
		amt = stats[HP];
	stats[currHP] = amt;
}

void Character::setCurrMana(int m) {
	int amt = stats[currMana] + m;
	if (amt > stats[Mana])
		amt = stats[Mana];
	stats[currMana] = amt;
}

void Character::setMana(int m) {
	stats[Mana] = m;
}

void Character::setATK(int a) {
	stats[ATK] = a;
}

void Character::setDEF(int d) {
	stats[DEF] = d;
}

void Character::setTurns(int t) {
	turns = t;
}

//Stat Accessors
int Character::getHP() const {
	return stats[HP];
}

int Character::getCurrHP() const {
	return stats[currHP];
}

int Character::getMana() const {
	return stats[Mana];
}

int Character::getCurrMana() const {
	return stats[currMana];
}

int Character::getATK() const {
	return stats[ATK];
}

int Character::getDEF() const {
	return stats[DEF];
}

int Character::getTurns() const {
	return turns;
}

int Character::attack() const {
	return stats[ATK];
}

//This function will return TRUE if character is still alive and FALSE if not
bool Character::takeDamage(int dmg) {
	int reducedDmg = dmg - stats[DEF];
	reducedDmg = reducedDmg <= 0 ? 1 : reducedDmg;
	stats[currHP] -= (reducedDmg);

	return stats[currHP] <= 0 ? false : true;
}

void Character::setCurrentFloor(int f) {
	if (f < 0 || f > 9)
		return;
	currentFloor = f;
}

int Character::getCurrentFloor() const {
	return currentFloor;
}

void Character::moveToNextFloor() {
	currentFloor++;
}

std::ostream& operator << (std::ostream& out, const Character& c) {
	out << "HP: " << c.stats[c.currHP] << "/" << c.stats[c.HP];
	out << " | Mana: " << c.stats[c.currMana] << "/" << c.stats[c.Mana];
	out << " | ATK: " << c.stats[c.ATK];
	out << " | DEF: " << c.stats[c.DEF];
	out << " | Gold: " << c.money;
	return out;
}