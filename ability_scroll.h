#ifndef ability_scroll_h
#define ability_scroll_h

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>

#include "items.h"

class AbilityScroll : public I::Items {
	std::string name;
public:
	AbilityScroll(Character& ch) : Items(ch) {
		name = "Ability Scroll";
	}

	int getSellPrice() const { return 300; };

	std::string getName() const {
		return name;
	}

	std::string info() const {
	    std::stringstream ss;
	    ss << std::setw(30) << std::left << name << std::setw(46) << "Use this item to gain a random ability.";
	    std::string out = ss.str();
	    return out;
	}

};
#endif // ability_scroll_h
