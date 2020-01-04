#include "inventory.h"

Inventory::Inventory(Character& c, int i) : ch(c), type(i) {
	if (i == 0) { //character inventory
		Basic_Armour *bscArm = new Basic_Armour(0, ch, "Standard");
		armorPtr = bscArm;
		item = bscArm;
		this->addInventoryItem(item, 1);
		//Determine weapon to add based on Character class
		std::string charClass = ch.getName();
		if (charClass == "Adventurer") {
			item = new Magic_Sword(0, ch, "Simple");
		}
		else if (charClass == "Alcoholic") {
			item = new Alcohol_Bottle(0, ch, "Shoddy");
		}
		else if (charClass == "Assassin") {
			item = new Katar_Dagger(0, ch, "Basic");
		}
		weaponPtr = item;
		this->addInventoryItem(item, 1);
	}
	else { //Merchant inventory
		std::string s;
		if (++floorCount < 4) {
			s = "Small";
		}
		else if (floorCount < 7) {
			s = "Medium";
		}
		else if (floorCount < 9) {
			s = "Large";
		}
		else {
			s = "Full";
		}
		for (int i = 0; i < 7; i++) {
			item = getRandItem(s);
			if (!isInInventory(item->getName())) //no adding duplicates!
				this->addInventoryItem(item, rand() % 3 + 1);
		}
	}
}

void Inventory::delInventoryItem(I::Items* item, int quantity) {
	inventoryItem[item] -= quantity;
	if (inventoryItem[item] <= 0) {
		inventoryItem.erase(item);
	}
}

I::Items* Inventory::getRandItem(std::string type) {
	int r = rand() % 6;
	switch (r) {
	case 0:
	case 1:
	case 2:
		return new Health_Potions(type, ch);
	case 3:
		return new Special_Potions(type, ch);
	case 4:
		return new Combat_Potions(type, "Attack", ch);
	case 5:
		return new Combat_Potions(type, "Defense", ch);
	}
	return nullptr;
}

void Inventory::accessInventoryItem(std::string& com) const {
	std::cout << "Enter item name to use or type 'Back': ";
	getline(std::cin, com);
	for (unsigned i = 0; i < com.length(); ++i) {
		com[i] = tolower(com[i]);
	}
}

void Inventory::addInventoryItem(I::Items* item, int quantity) {
	inventoryItem[item] += quantity;
}

void Inventory::idItem(std::string& com, I::Items*& item) {
	for (std::map<I::Items*, int>::iterator iter = inventoryItem.begin(); iter != inventoryItem.end(); ++iter) {
		I::Items* k = iter->first;
		std::string tCom = com;
		for (unsigned i = 0; i < com.length(); ++i) {
			tCom[i] = tolower(com[i]);
		}
		std::string name = k->getName();
		for (unsigned i = 0; i < name.length(); ++i) {
			name[i] = tolower(name[i]);
		}
		if (tCom == name) {
			item = k;
			return;
		}
	}
	com = "";
}

bool Inventory::addNewItem(std::string itemName, I::Items* i) {
	item = nullptr;
	for (unsigned i = 0; i < itemName.length(); ++i) {
		itemName[i] = tolower(itemName[i]);
	}
	if (itemName.find("attack") != std::string::npos ||
		itemName.find("defense") != std::string::npos) {
		item = new Combat_Potions(*dynamic_cast<Combat_Potions*>(i));
	}
	else if (itemName.find("health") != std::string::npos) {
		item = new Health_Potions(*dynamic_cast<Health_Potions*>(i));
	}
	else if (itemName.find("mana") != std::string::npos &&
		itemName.find("feather") == std::string::npos) {
		item = new Special_Potions(*dynamic_cast<Special_Potions*>(i));
	}
	else if (itemName == "weapon upgrade" ||
		itemName == "armor upgrade" ||
		itemName == "lamp of illumination" ||
		itemName == "bulky herb" ||
		itemName == "mana feather" ||
		itemName == "ability scroll") {
		item = i;
	}
	if (item) {
		addInventoryItem(item, 1);
		return true;
	}
	else {
		return false;
	}
}

bool Inventory::isInInventory(std::string s) {
	I::Items* p;
	idItem(s, p);
	if (s == "")
		return false;
	return true;
}

bool Inventory::useInventory() {
	std::string com;
	//Prints out the inventory for the player
	this->printInventory();
	//Returns the Item the player wants to use
	this->accessInventoryItem(com);
	if (com == "Back" || com == "back") {
		com = "";
		return false;
	}
	else {
		if (com.find("magic sword") != std::string::npos ||
			com.find("alcohol bottle") != std::string::npos ||
			com.find("katar dagger") != std::string::npos ||
			com.find("magic armour") != std::string::npos) {
			std::cout << "You cannot use weapons/armours in this way!" << std::endl;
			com = "";
			return false;
		}
	}
	//Finds the item in the map
	this->idItem(com, item);
	//Deletes one specified item quantity
	if (!com.empty()) {
		if (item->getName() == "Weapon Upgrade") {
			delInventoryItem(item, 1);
			std::cout << "\nYou feel the power in your sword grow stronger...\n" << std::endl;
			weaponPtr->upgradeWeapon();
			return true;
		}
		else if (item->getName() == "Armor Upgrade") {
			delInventoryItem(item, 1);
			std::cout << "\nYou feel your armor grow tougher...\n" << std::endl;
			armorPtr->upgradeArmor();
			return true;
		}
		else if (item->getName() == "Lamp of Illumination") {
			delInventoryItem(item, 1);
			std::cout << "\nThe Lamp of Illumination lights up...\n" << std::endl;
			throw Lamp(ch);
		}
		else if (item->getName() == "Ability Scroll") {
			delInventoryItem(item, 1);
			ch.unlockRandomAbility();
			return true;
		}
		//Uses the item's effect
		item->consume();
		int itemCount = inventoryItem[item] - 1;
		this->delInventoryItem(item, 1);
		std::cout << std::endl;
		std::cout << "You used one " << com << ". (" << itemCount << ") left in inventory." << std::endl;
		std::cout << std::endl;
		return true;
	}
	else {
		std::cout << "Item not found." << std::endl << std::endl;
		return false;
	}
}

void Inventory::printInventory() {
	if (type == 0) { //Char inventory
		std::cout << std::setw(12) << "Quantity:" << std::setw(30) << "Item:" << std::setw(50) << "Notes:" << std::endl;
		for (std::map<I::Items*, int>::iterator iter = inventoryItem.begin(); iter != inventoryItem.end(); ++iter) {
			int v = iter->second;
			std::cout << "(" << v << std::setw(10) << ")";
			I::Items* k = iter->first;
			std::cout << k->info() << std::endl;
		}
	}
	else { //Merchant Inventory
		std::cout << std::setw(25) << "Name" << std::setw(15) << "# In-Stock" << std::setw(10) << "Potency" << std::setw(10) << "Price" << std::endl;
		std::cout << std::setfill('-') << std::setw(60) << "" << std::setfill(' ') << std::endl;
		for (std::map<I::Items*, int>::iterator iter = inventoryItem.begin(); iter != inventoryItem.end(); ++iter) {
			int v = iter->second;
			I::Items* k = iter->first;
			std::cout << std::setw(25) << k->getName() << std::setw(15) << v << std::setw(10) << k->getPotency() << std::setw(10) << k->getPrice() << std::endl;
		}
	}
}

int Inventory::floorCount = 0;