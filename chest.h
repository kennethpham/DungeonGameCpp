#ifndef chest_h
#define chest_h

#include <iostream>
#include <random>

#include "event.h"
#include "weapons_upgrade.h"
#include "armor_upgrade.h"
#include "lamp.h"
#include "feather.h"
#include "herb.h"
#include "ability_scroll.h"

class Chest : public Event {
private:
	I::Items * item;
	bool hasItem;
	static int weaponUpgradeCount;
	static int armorUpgradeCount;
public:
	Chest(Character& ch, Inventory& i);

	~Chest() {
		delete item;
	}

	void performEvent();
	void printAscii() const;
};
#endif // chest_h
