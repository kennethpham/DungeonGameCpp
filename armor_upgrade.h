#ifndef armor_upgrade_h
#define armor_upgrade_h

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>

#include "items.h"

class Armor_Upgrade : public I::Items {
	std::string name;
public:
	Armor_Upgrade(Character& ch) : Items(ch, false) {
		name = "Armor Upgrade";
	}

	std::string getName() const {
		return name;
	}

	std::string info() const {
        std::stringstream ss;
	    ss << std::setw(30) << std::left << name << std::setw(46) << "Use this item to upgrade your armor's resistance.";
	    std::string out = ss.str();
	    return out;
	}

};
#endif // armor_upgrade_h
