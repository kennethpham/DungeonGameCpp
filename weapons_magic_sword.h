
#ifndef weapons_magic_sword_h
#define weapons_magic_sword_h

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>

#include "items.h"

class Magic_Sword : public I::Items {
    std::string name;
    int damage, upgradeDamage;
    int value;
    int upgradeTier;
    std::string attribute;
public:
    Magic_Sword(int uT, Character& ch, std::string attr = "") : Items(ch, false) {
		damage = upgradeDamage = 5;
        value = 15;
        upgradeTier = uT;
        attribute = attr;
        if(attribute.empty()) {
             name = "Magic Sword";
        }
        else {
             name = attribute + " Magic Sword";
        }
		ch.setATK(ch.getATK() + damage);
    }
    void addAttribute(std::string attr) {
        attribute = attr;
        name = attribute + " Magic Sword";
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
		int buff = upgradeTier % 2 ? ch.getATK() + (damage * 2) : ch.getATK() + damage;
		ch.setATK(buff);
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
#endif // weapons_magic_sword_h
