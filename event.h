#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <string>
#include "inventory.h"
#include "character.h"

class Event {
protected:
	bool isVisited, currentlyOccupied;
	std::string notVisitedSymbol, visitedSymbol;
	Character& character;
	Inventory& i;
public:
	Event() = delete; //forced to use overloaded c-tor
	Event(Character& ch, Inventory& inv, std::string vS = " .") : character(ch), i(inv), isVisited(false), currentlyOccupied(false), notVisitedSymbol(" ?"), visitedSymbol(vS) {}

	virtual std::string getSymbol() const;

	virtual void performEvent();

	bool getIsVisited() const;

	void visit();

	void unVisit();
};
#endif
