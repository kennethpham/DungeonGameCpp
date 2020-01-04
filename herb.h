#ifndef herb_h
#define herb_h

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include "random"

#include "items.h"

class Herb : public I::Items {
	std::string name;
public:
	Herb(Character& ch) : Items(ch) {
		name = "Bulky Herb";
	}

	int getSellPrice() const { return 250; };

	std::string getName() const {
		return name;
	}

	std::string info() const {
	    std::stringstream ss;
	    ss << std::setw(30) << std::left << name << std::setw(46) << "Use this item to increase your max HP.";
	    std::string out = ss.str();
	    return out;
	}

	void consume() {
		int stat = rand() % 16 + 10;
		std::cout << "The Bulky Herb grants you +" << stat << " HP!\n" << std::endl;
		ch.setHP(ch.getHP() + stat);
		ch.setCurrHP(stat);
	}

};
#endif // herb_h

