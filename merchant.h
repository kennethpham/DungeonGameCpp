#ifndef merchant_h
#define merchant_h

#include <map>
#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <string>

#include "items.h"
#include "inventory.h"
#include "event.h"

class Merchant : public Event {
	Inventory *merchInv;
	I::Items* item;
public:
	Merchant(Character& ch, Inventory& i) : Event(ch, i, "<S>") {
		merchInv = new Inventory(ch, 1);
	}

	~Merchant() {
		delete merchInv;
	}

	//This is for populating the Merchant inventory upon creation of Merchant
	//Currently no design for adding Player-Sold items to the Merchant inventory
	//However, this function can be used for that (with currency edits), if needed.
	void addMerchInv(I::Items* item, int quantity) {
		merchInv->addInventoryItem(item, quantity);
	}
	//Removes the item from the merchant's inventory
	void delMerchInv(I::Items* item, int quantity) {
		merchInv->delInventoryItem(item, quantity);
	}
	void idMerchItem(std::string& com, I::Items*& item) const {
		merchInv->idItem(com, item);
	}

	void printMerchInv() const {
		merchInv->printInventory();
	}

	void performEvent();

	void buyItem();

	void sellItem();

	void isValidNum(std::string in, int& num);

	void printArt() const;
};

#endif // merchant_h
