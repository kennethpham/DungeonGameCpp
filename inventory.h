#ifndef inventory_h
#define inventory_h

#include <iostream>
#include <map>
#include <random>
#include <iomanip>

#include "character.h"
#include "items.h"
#include "potions_health.h"
#include "potions_special.h"
#include "potions_combat.h"
#include "weapons_magic_sword.h"
#include "weapons_alcohol_bottle.h"
#include "weapons_katar_dagger.h"
#include "weapons_upgrade.h"
#include "armour_basic_armour.h"
#include "lamp.h"
#include "herb.h"
#include "feather.h"

class Inventory {
	Character& ch;
	I::Items* item = nullptr;
	int type;
	std::map <I::Items*, int> inventoryItem;
	static int floorCount;
	I::Items* weaponPtr, *armorPtr;
public:
	Inventory(Character& c, int i);

	virtual ~Inventory() {
		for (std::map<I::Items*, int>::iterator iter = inventoryItem.begin(); iter != inventoryItem.end(); ++iter) {
			delete iter->first;
		}
	}

	int searchInventory(I::Items* item) {
		return inventoryItem[item];
	}

	I::Items* getRandItem(std::string type);
	void accessInventoryItem(std::string& com) const;
	void addInventoryItem(I::Items* item, int quantity);
	void delInventoryItem(I::Items* item, int quantity);
	void idItem(std::string& com, I::Items*& item);
	void printInventory();
	bool useInventory();
	bool isInInventory(std::string s);
	bool addNewItem(std::string itemName, I::Items* i);
};
#endif // inventory_h
