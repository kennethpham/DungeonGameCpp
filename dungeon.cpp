#include "dungeon.h"

void Dungeon::play() {
	int i, j;
	while (true) {
		i = ch->getCurrentFloor();
		std::cout << *(dungeon[i]);
		std::cout << std::setfill('-') << std::setw(10) << "" << "Controls" << std::setfill('-') << std::setw(10) << "" << std::setfill(' ') << std::endl;
		std::cout << "UP - W, DOWN - S, RIGHT - D, LEFT - A, OPEN INVENTORY - O\n" << std::endl;
		std::cout << "Your Command: ";
		std::cin >> in;
		
		//First five conditionals are for backdoor presentation purposes
		if (in[0] == 'f' && isdigit(in[1])) {
			int f;
			std::stringstream s(in.substr(1));
			s >> f;
			ch->setCurrentFloor(f - 1); //to account for vector 0 - based counting (make more user-friendly)
			std::cout << std::endl;
			continue;
		}
		else if (in == "tank") {
			ch->setHP(9999999);
			ch->setMana(9999999);
			ch->setCurrHP(9999999);
			ch->setCurrMana(9999999);
			std::cout << std::endl;
			continue;
		}
		else if (in == "reveal") {
			dungeon[ch->getCurrentFloor()]->revealAll();
			std::cout << std::endl;
			continue;
		}
		else if (in == "hide") {
			dungeon[ch->getCurrentFloor()]->hideAll();
			std::cout << std::endl;
			continue;
		}
		else if (in == "atk") {
			ch->setATK(ch->getATK() + 10);
			std::cout << std::endl;
			continue;
		}
		else if (in.length() != 1) {
			std::cout << std::endl;
			continue;
		}
	
		std::cin.ignore(1000, '\n');
		std::cout << std::endl;
		input = tolower(in[0]);

		try {
			if (input == 'w' || input == 's' || input == 'a' || input == 'd') {
				dungeon[i]->moveCharacter(input);
				j = ch->getCurrentFloor();

				if (j == 10) {
					f.performEvent();
				}
				else if (i != j) { //Character moved up a floor
					ch->setCoor(4, 0); //so reset to entrance coors for new floor
				}
			}
			else if (input == 'o') {
				try {
					inv.useInventory();
				}
				catch (const Lamp& l) {
					dungeon[ch->getCurrentFloor()]->revealLadder();
				}
			}
		}
		catch (std::string err) {
			std::cout << err << std::endl;

			if (err.find("WIN") != std::string::npos)
				printVictory();
			return;
		}
	}
}

void Dungeon::printVictory() const {
	std::cout << std::endl << R"(
     _______________
    |@@@@|     |####|
    |@@@@|     |####|
    |@@@@|     |####|
    \@@@@|     |####/
     \@@@|     |###/
      `@@|_____|##'
           (O)
        .-'''''-.
      .'  * * *  `.
     :  *       *  :
    : ~   Y O U   ~ :
    : ~  W I N !  ~ :
     :  *       *  :
      `.  * * *  .'
        `-.....-'
)" << std::endl;
}

