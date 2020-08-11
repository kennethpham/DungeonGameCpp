#include "event.h"

//Event::Event(Character& ch, Inventory& inv, std::string vS = " .") : character(ch), i(inv), isVisited(false), currentlyOccupied(false), notVisitedSymbol(" ?"), visitedSymbol(vS) {}

std::string Event::getSymbol() const {
    return isVisited ? visitedSymbol : notVisitedSymbol;
}

void Event::performEvent() {
    isVisited = true;
    std::cout << "An event has occured!" << std::endl;
}

bool Event::getIsVisited() const {
    return isVisited;
}

void Event::visit() {
    isVisited = true;
}

void Event::unVisit() {
    isVisited = false;
}