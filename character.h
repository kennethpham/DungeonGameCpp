#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <vector>
#include <iostream>

#include "special_moves.h"
#include "monster.h"

class Character {
protected:
	std::string name;
	enum {HP, currHP, Mana, currMana, ATK, DEF, NumberOfStats};
	std::vector<int> stats;
	std::vector<SpecialMove*> moves;
	int xCoor, yCoor;
	int currentFloor;
	int turns;
	int money;
public:
	Character();

	~Character();

	virtual void displayMoves();

	virtual int useSpecial(int num, Monster* m);

	void setCoor(int newX, int newY);

	int getX() const;

	int getY() const;

	std::string getName() const;

	void addMoney(int m);

	int getMoney() const;

	//Stat mutators
	void setHP(int h);
	
	bool unlockRandomAbility();

	void setCurrHP(int h);

	void setCurrMana(int m);

	void setMana(int m);

	void setATK(int a);

	void setDEF(int d);

	void setTurns(int t);

	//Stat Accessors
	int getHP() const;

	int getCurrHP() const;

	int getMana() const;

	int getCurrMana() const;

	int getATK() const;

	int getDEF() const;

	int getTurns() const;

	virtual int attack() const;

	//This function will return TRUE if character is still alive and FALSE if not
	virtual bool takeDamage(int dmg);

	void setCurrentFloor(int f);

	int getCurrentFloor() const;

	void moveToNextFloor();

	friend std::ostream& operator << (std::ostream& out, const Character& c);

	
};

#endif