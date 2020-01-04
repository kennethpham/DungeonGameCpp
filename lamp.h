#ifndef lamp_h
#define lamp_h

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>

#include "items.h"

class Lamp : public I::Items {
	std::string name;
public:
	Lamp(Character& ch) : Items(ch) {
		name = "Lamp of Illumination";
	}

	int getSellPrice() const { return 100; };

	std::string getName() const {
		return name;
	}

	std::string info() const {
	    std::stringstream ss;
	    ss << std::setw(30) << std::left << name << std::setw(46) << "Use this item to reveal the ladder's location.";
	    std::string out = ss.str();
	    return out;
		//return name + "\t\tUse this item to reveal the ladder's location";
	}

};
#endif // lamp_h
