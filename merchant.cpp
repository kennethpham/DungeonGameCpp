#include "merchant.h"

void Merchant::performEvent() {
	printArt();
	isVisited = true;
	char input;
	std::cout << "Hey there hero, and welcome to my shop! Feel free to look around.\n" << std::endl;

	do {
		printMerchInv();
		std::cout << "\nYou currently have " << character.getMoney() << " gold" << std::endl;
		std::cout << "\nCommands: [B] Buy item | [S] Sell item | [L] Leave ";

		std::cout << "\nWhat would you like to do? ";
		std::cin.get(input);
		std::cin.ignore(1000, '\n');
		input = tolower(input);

		if (input == 'b') {
			buyItem();
		}
		else if (input == 's') {
			sellItem();
		}

	} while (input != 'l');

	std::cout << "\nNice doin' business with ya! Come back any time!\n" << std::endl;
}

void Merchant::buyItem() {
	std::string item;
	std::cout << "Alrighty then. What's the name of the item you wanna buy? ";
	std::getline(std::cin, item);
	if (merchInv->isInInventory(item)) {// If item is in MERCHANT inventory
										//First get item
		I::Items* iPtr;
		merchInv->idItem(item, iPtr);
		if (iPtr->getPrice() > character.getMoney()) {
			std::cout << "\nYou don't have enough money for that item. I'm not running a charity here!\n" << std::endl;
			return;
		}
		else {
			character.addMoney(-iPtr->getPrice()); //First remove money from character inventory (negative of item price)
			merchInv->delInventoryItem(iPtr, 1); //remove 1 of item from merch inventory
			int itemCount;
			if (i.isInInventory(item)) { //If item already exists in CHARACTER inventory, we simply increment count
				i.idItem(item, iPtr);
				i.addInventoryItem(iPtr, 1);
				itemCount = i.searchInventory(iPtr);
			}
			else { //otherwise we need to create a new item
				i.addNewItem(item, iPtr);
				itemCount = 1;
			}
			std::cout << "\nYou obtained the " << item << "! You now have " << itemCount << " in your inventory.\n" << std::endl;
		}
	}
	else {
		std::cout << "\nHmm. I don't seem to have that item...\n" << std::endl;
		return;
	}
}

void Merchant::sellItem() {
	std::string item;
	int numToSell;
	std::string numToSellInput;
	std::cout << "Take a look through your inventory and tell me the name of the item you want to sell.\n\n";
	i.printInventory();
	std::cout << "\nItem Name: ";
	std::getline(std::cin, item);

	if (i.isInInventory(item)) {
		I::Items* iPtr;
		i.idItem(item, iPtr);

		if (!iPtr->getCanSell()) { //If cannot sell
			std::cout << "\nI have no intention on fighting monsters, so I won't buy that!\n" << std::endl;
			return;
		}
		std::string answer;
		std::cout << "Hmmm... I think I can give you " << iPtr->getSellPrice() << " gold for every " << iPtr->getName() << std::endl;
		std::cout << "What do you say? Do we have a deal? (Y / N): ";
		std::getline(std::cin, answer);
		answer[0] = tolower(answer[0]);

		if (answer[0] == 'y') {
			std::cout << "Great! Now, how many are you willing to sell? ";
			std::cin >> numToSellInput;
			std::cin.ignore(100, '\n');
			isValidNum(numToSellInput, numToSell);

			while (numToSell < 0 || numToSell > i.searchInventory(iPtr)) {
				std::cout << "Nice try, buddy. Enter a valid number: ";
				std::cin >> numToSellInput;
				std::cin.ignore(100, '\n');
				isValidNum(numToSellInput, numToSell);
			}
			if (numToSell > 0) {
				int gain = iPtr->getSellPrice() * numToSell;
				character.addMoney(gain);
				i.delInventoryItem(iPtr, numToSell);

				std::cout << "Nice doin' business with ya!" << std::endl;
				std::cout << "\nYou gained " << gain << " gold\n" << std::endl;
			}
			else if (numToSell == 0) {
				std::cout << "\nWhy'd ya have to ask in the first place then!?!\n" << std::endl;
			}
			else {
				std::cout << "Huh? Speak up! I can't hear you!" << std::endl;
			}
		}
		else if (answer[0] == 'n') {
			std::cout << "\nWhy'd ya have to ask in the first place then!?!\n" << std::endl;
		}
		else {
			std::cout << "\nSpeak English!!!\n" << std::endl;
		}
	}
	else {
		std::cout << "\nWhat's that now? I don't think you have that item...\n" << std::endl;
	}
}

void Merchant::isValidNum(std::string in, int& num) {
	try {
		num = stoi(in);
	}
	catch (const std::invalid_argument& e) {
		std::cerr << "Huh? Speak up! I can't hear you!" << std::endl;
		std::cin >> in;
		std::cin.ignore(100, '\n');
		isValidNum(in, num);
	}
}

void Merchant::printArt() const {
	std::cout << "\n" << R"(
   ______                               __        __
 .' ___  |                             |  ]      [  |
/ .'   \_| _ .--.  .---.  _ .--.   .--.| | .---.  | |  .--.
| |   ____[ `/'`\]/ /__\\[ `.-. |/ /'`\' |/ /__\\ | | ( (`\]
\ `.___]  || |    | \__., | | | || \__/  || \__., | |  `'.'.
 `._____.'[___]    '.__.'[___||__]'.__.;__]'.__.'[___][\__) )

  ______   __
.' ____ \ [  |
| (___ \_| | |--.   .--.   _ .--.
 _.____`.  | .-. |/ .'`\ \[ '/'`\ \
| \____) | | | | || \__. | | \__/ |
 \______.'[___]|__]'.__.'  | ;.__/
                           [__|
		)" << std::endl;
}