#include "chest.h"

int Chest::weaponUpgradeCount = 0;
int Chest::armorUpgradeCount = 0;

Chest::Chest(Character& ch, Inventory& i) : Event(ch, i, "<C>"), hasItem(true) {
	int r = rand() % 100 + 1;

	if (r <= 20) {
		weaponUpgradeCount++;
		if (weaponUpgradeCount > 10)
			item = new Herb(character);
		else
			item = new Weapon_Upgrade(character);
	}
	else if (r > 20 && r <= 40) {
		armorUpgradeCount++;
		if (armorUpgradeCount > 10)
			item = new Feather(character);
		else
			item = new Armor_Upgrade(character);
	}
	else if (r > 40 && r <= 60) {
		item = new Lamp(character);
	}
	else if (r > 60 && r <= 80) {
		item = new Herb(character);
	}
	else {
		item = new AbilityScroll(character);
	}
}

void Chest::performEvent() {
	isVisited = true;
	std::string s;
	printAscii();
	//std::cout << "You found a chest! Would you like to open it? (Y / N): ";
	std::cout << "You found a chest!";

	/**
	std::getline(std::cin, s);
	s[0] = tolower(s[0]);

	if (s[0] == 'n') {
	std::cout << std::endl;
	return;
	}*/

	if (!hasItem) {
		std::cout << "\nYou peer into the chest but don't see anything...\n" << std::endl;
	}
	else if (hasItem) {
		std::cout << "\nYou found a " << item->getName() << "!";
		std::cout << "\nYou add it to your inventory for safe keeping.\n" << std::endl;
		std::string itemName = item->getName();

		if (i.isInInventory(itemName)) {
			i.idItem(itemName, item);
			i.addInventoryItem(item, 1);
		}
		else {
			i.addNewItem(item->getName(), item);
			item = nullptr;
		}
		hasItem = false;
	}
	std::cout << "Press any key to continue your adventure...\n";
	std::cin.get();
	return;
}

void Chest::printAscii() const {
	std::cout << std::endl << R"(
*******************************************************************************
          |                   |                  |                     |
 _________|________________.=""_;=.______________|_____________________|_______
|                   |  ,-"_,=""     `"=.|                  |
|___________________|__"=._o`"-._        `"=.______________|___________________
          |                `"=._o`"=._      _`"=._                     |
 _________|_____________________:=._o "=._."_.-="'"=.__________________|_______
|                   |    __.--" , ; `"=._o." ,-"""-._ ".   |
|___________________|_._"  ,. .` ` `` ,  `"-._"-._   ". '__|___________________
          |           |o`"=._` , "` `; .". ,  "-._"-._; ;              |
 _________|___________| ;`-.o`"=._; ." ` '`."\` . "-._ /_______________|_______
|                   | |o;    `"-.o`"=._``  '` " ,__.--o;   |
|___________________|_| ;     (#) `-.o `"=.`_.--"_o.-; ;___|___________________
____/______/______/___|o;._    "      `".o|o_.--"    ;o;____/______/______/____
/______/______/______/_"=._o--._        ; | ;        ; ;/______/______/______/_
____/______/______/______/__"=._o--._   ;o|o;     _._;o;____/______/______/____
/______/______/______/______/____"=._o._; | ;_.--"o.--"_/______/______/______/_
____/______/______/______/______/_____"=.o|o_.--""___/______/______/______/____
/______/______/______/______/______/______/______/______/______/______/______/_
*******************************************************************************
		)" << std::endl << std::endl;
}