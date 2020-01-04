#ifndef feather_h
#define feather_h

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include "random"

#include "items.h"

class Feather : public I::Items {
	std::string name;
public:
	Feather(Character& ch) : Items(ch) {
		name = "Mana Feather";
	}

	int getSellPrice() const { return 200; };

	std::string getName() const {
		return name;
	}

	std::string info() const {
	    std::stringstream ss;
	    ss << std::setw(30) << std::left << name << std::setw(46) << "Use this item to increase your max Mana.";
	    std::string out = ss.str();
	    return out;
	}

	void consume() {
		int stat = rand() % 11 + 15;
		std::cout << "The Mana Feather grants you +" << stat << " Mana!\n" << std::endl;
		ch.setMana(ch.getMana() + stat);
		ch.setCurrMana(stat);
	}

};
#endif // feather_h

