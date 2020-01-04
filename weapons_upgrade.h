#ifndef weapons_upgrade_h
#define weapons_upgrade_h

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>

#include "items.h"

class Weapon_Upgrade : public I::Items {
    std::string name;
public:
    Weapon_Upgrade(Character& ch) : Items(ch, false) {
        name = "Weapon Upgrade";
    }

    std::string getName() const {
        return name;
    }

	std::string info() const {
        std::stringstream ss;
	    ss << std::setw(30) << std::left << name << std::setw(46) << "Use this item to upgrade your weapon's power.";
	    std::string out = ss.str();
	    return out;
		//return name + "\t\tUse this item to upgrade your weapon's power!";
	}

};
#endif // weapons_upgrade_h
