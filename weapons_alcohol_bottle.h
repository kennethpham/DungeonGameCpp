
#ifndef weapons_alcohol_bottle_h
#define weapons_alcohol_bottle_h

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>

#include "items.h"

class Alcohol_Bottle : public I::Items {
    std::string name;
	int damage, upgradeDamage;
    int value;
    int upgradeTier;
    std::string attribute;
public:
    Alcohol_Bottle(int uT, Character& ch, std::string attr = "") : Items(ch, false) {
        damage = upgradeDamage = 5;
        value = 3;
        upgradeTier = uT;
        attribute = attr;
        if(attribute.empty()) {
             name = "Alcohol Bottle";
        }
        else {
             name = attribute + " Alcohol Bottle";
        }
		ch.setATK(ch.getATK() + damage);
    }
    void addAttribute(std::string attr) {
        attribute = attr;
        name = attribute + " Alcohol Bottle";
    }
    std::string getName() const {
        return name;
    }
    std::string info() const {
        std::stringstream ss;
        std::string def = "Damage: " + std::to_string(upgradeDamage);
        std::string val = "Value: " + std::to_string(value);
        ss << std::setw(30) << std::left << name << std::setw(12) << def << std::setw(12) << val;
        std::string out = ss.str();
        return out;
    }

	int getPrice() const {
		return 0;
	}

	int getSellPrice() const {
		return 0;
	}

	void upgradeWeapon() {
		upgradeDamage += damage;
		upgradeTier++;
		ch.setATK(ch.getATK() + damage);
		switch (upgradeTier) {
		case 1:
			attribute = "Wooden";
			break;
		case 2:
			attribute = "Decent";
			break;
		case 3:
			attribute = "Sturdy";
			break;
		case 4:
			attribute = "Stone";
			break;
		case 5:
			attribute = "Bronze";
			break;
		case 6:
			attribute = "Silver";
			break;
		case 7:
			attribute = "Hard";
			break;
		case 8:
			attribute = "Golden";
			break;
		case 9:
			attribute = "Platinum";
			break;
		default:
			attribute = "Diamond";
			break;
		}
		addAttribute(attribute);
	}
};
#endif // weapons_alcohol_bottle_h
