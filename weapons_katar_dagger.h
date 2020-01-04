
#ifndef weapons_katar_dagger_h
#define weapons_katar_dagger_h

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>

#include "items.h"

class Katar_Dagger : public I::Items {
    std::string name;
	int damage, upgradeDamage;
    int value;
    int upgradeTier;
    std::string attribute;
public:
    Katar_Dagger(int uT, Character& ch, std::string attr = "") : Items(ch, false) {
		damage = upgradeDamage = 6;
        value = 12;
        upgradeTier = uT;
        attribute = attr;
        if(attribute.empty()) {
             name = "Katar Dagger";
        }
        else {
             name = attribute + " Katar Dagger";
        }
		ch.setATK(ch.getATK() + damage);
    }
    void addAttribute(std::string attr) {
        attribute = attr;
        name = attribute + " Katar Dagger";
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
#endif // weapons_katar_dagger_h
