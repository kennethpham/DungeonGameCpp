#include "final_battle.h"

void fb::FinalBattle::performEvent() { //auto as c++11 feature!
	auto turn = 0; //Turn counter in each stage 
	auto pups = 0; //How many pups still alive by stage 5?
	auto buff = 0; //Defense buff for Doggo
	auto doom = 3; //Turns for Final Doggo to charge up his attack 
	while (stage != 7) { //If stage hits 7, fight is over no matter what 
		turn = 0;
		std::cout << "\nA " << monster->getMonsterName() << " appears!\n" << std::endl;
		monster->printAscii();

		while (character.getCurrHP() > 0 && monster->getHP() > 0) {
			if (performTurn(doom, pups, turn))
				break;
		}//End While

		if (character.getCurrHP() < 0) {
			throw std::string("You were killed by the " + monster->getMonsterName() + "!\nGAME OVER");
		}

		if (monster->getHP() < 0) {
			isDead = true;
			if (stage != 6) {
				std::cout << "You successfully killed the " << monster->getMonsterName() << "!" << std::endl;
			}
			else {
				std::cout << "Congratulations! You've exterminated the " << monster->getMonsterName() << std::endl;
				throw std::string("\nYou have conquered this dungeon, hero! YOU WIN!");
			}
		}

		std::cout << std::endl;
		nextStage();
		monster = getDog(stage);

		std::cout << std::setfill('-') << std::setw(100) << "" << std::setfill(' ') << std::endl;
		if (stage == 2) {
			std::cout << "The Doggo is scared and has went into hiding. Get through his two guard Pups!" << std::endl;
			std::cout << "The first Pup runs at you! Kill it in 5 turns!" << std::endl;
		}
		else if (stage == 3) {
			std::cout << "The second Pup runs at you! Kill it in 5 turns!" << std::endl;
		}
		else if (stage == 4) {
			std::cout << "The ScaredDoggo is driven out of hiding!" << std::endl;
		}
		else if (stage == 5) {
			std::cout << "You've turned the ScaredDoggo into a MadDoggo..." << std::endl;
			if (pups > 0) {
				std::cout << "The MadDoggo chases down the deserter pups and consumes them." << std::endl;
				std::cout << "MadDoggo uses " << monster->aName() << " and chows down on " << pups <<
					" serving(s) of pup." << std::endl;
				std::cout << "MadDoggo's defense is increased by " << pups * monster->aPower() << "." << std::endl;
				buff = 20 + pups * monster->aPower();
				monster->setStat(2, buff);
			}
		}
		else if (stage == 6) {
			std::cout << "The FinalDoggo is using its last resort, stop the charging of its final attack!\nNote: Sleep and Paralysis will not stop this attack!" << std::endl;
			if (pups > 0) { //If the Doggo was buffed up by Consume previously
				monster->setStat(2, buff);
			}
		}

		std::cout << std::setfill('-') << std::setw(100) << "" << std::setfill(' ') << std::endl;
		isVisited = true;
		std::cout << std::endl << std::endl;
	}
}

bool fb::FinalBattle::performTurn(int& doom, int& pups, int& turn) {
	int monsterAtk;
	std::string userInput;
	displayCommands(turn, doom, userInput);

	if (userInput == "run") {
		std::cout << "You can't run away from this " << monster->getMonsterName() << "!\n" << std::endl;
		return false;
	}

	if (userInput == "o") {
		if (i.useInventory()) { //If the user used an item
			performMonsterAttk(monsterAtk);
		}
	}
	else {
		int dmg;

		if (userInput == "s") {
			int n;
			std::string input;
			character.displayMoves();
			bool validMove;

			do {
				validMove = true;
				std::cout << "Which move would you like to use? ";
				std::getline(std::cin, input);

				if (input.length() != 1) {
					validMove = false;
					std::cout << "Invalid input! ";
					continue;
				}

				try {
					n = stoi(input);
					dmg = character.useSpecial(n, monster);
				}
				catch (const std::invalid_argument& e) {
					std::cout << "Invalid number! ";
					validMove = false;
				}
				catch (const std::out_of_range& e) {
					std::cout << "Invalid number! ";
					validMove = false;
				}
				catch (...) {
					std::cout << "Invalid input! ";
					validMove = false;
				}
			} while (!validMove);

			if (dmg != 0) { //0 means not enough mana
				monster->takeDamage(dmg);
			}
			std::cout << std::endl;
		}
		else if (userInput == "") {
			std::cout << "\nYou attack the " << monster->getMonsterName() << std::endl;
			dmg = character.attack();
			monster->takeDamage(dmg);
		}
		else {
			return false;
		}
		
		if (dmg != 0) {
			performMonsterAttk(monsterAtk);
		}
		
	}

	turn += 1;

	if ((stage == 2 || stage == 3) && monster->getHP() > 0 && turn > 5) { //If you take too long to kill a pup 
		pups += 1;
		std::cout << "The Pup runs away!" << std::endl;
		return true;
	}

	if (doom == 0 && monster->getHP() > 0) { //If the doom count hits 0 on the FinalDoggo
		std::cout << "You have failed to stop FinalDoggo from powering up...\n";
		std::cout << "FinalDoggo unleashes " << monster->aName() << ".";
		character.takeDamage(monster->aPower());
		throw std::string("\n\nYou were killed by the FinalDoggo! So close...\nGAME OVER");
	}

	std::cout << std::endl;
	return false;
}

void fb::FinalBattle::displayCommands(int& turn, int& doom, std::string& userInput) {
	std::cout << "Enemy HP: " << monster->getHP();

	if (monster->getStatus() >= 0) {
		std::cout << "   Enemy Status: " << monster->getStrStatus();
	}

	std::cout << "   Your HP: " << character.getCurrHP() << "/" << character.getHP();
	std::cout << "   Your Mana: " << character.getCurrMana() << "/" << character.getMana() << std::endl;
	std::cout << "TURN: " << turn << std::endl << std::endl;

	if (stage == 6)
	{
		doom -= 1;
		std::cout << std::setfill('-') << std::setw(100) << "" << std::setfill(' ') << std::endl;
		if (doom == 0) {
			std::cout << "Kill the FinalDoggo with the next move, or you will face Armadoggen!!!\n";
		}
		else {
			std::cout << "Gas builds up within the FinalDoggo! " << doom << " turns from destruction...\n";
		}

		std::cout << std::setfill('-') << std::setw(100) << "" << std::setfill(' ') << std::endl << std::endl;
	}

	std::cout << "--COMMANDS--\n";
	std::cout << "Attack: 'enter key'\n";
	std::cout << "Use special ability: 's'\n";
	std::cout << "Run Away: 'run'\n";
	std::cout << "Open Invntory: 'o'\n";
	std::cout << "Input which command you want: ";
	std::getline(std::cin, userInput);
	std::transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);
	std::cout << "\n";
}

void fb::FinalBattle::performMonsterAttk(int& monsterAtk) {
	if (monster->getHP() > 0) {
		if (stage != 6) { //If it's FinalDoggo
			monsterAtk = monster->attack();
			if (monsterAtk < 0) { //I set it up so neg damage means special attack
				std::cout << "The " << monster->getMonsterName() << " used " << monster->getAbilityName() << "!" << std::endl;
				if (monster->getMonsterName() == "Doggo") { //Doggo's special attack 
					std::cout << "It gained " << monster->getAbilityPower() << " HP!\n" << std::endl;
				}
				else if (monster->getMonsterName() == "Pup") { //Pup's special attack 
					std::cout << "This Pupper is getting buffer!";
				}
				monsterAtk *= -1;
			}
			else if (monsterAtk > 0) {
				std::cout << "The " << monster->getMonsterName() << " attacks!\n" << std::endl;
			}
		}
		else
		{
			std::cout << "FinalDoggo's stomach is rumbling...\n";
			monsterAtk = 0; // No damage to Character while charging up
		}

		if (monsterAtk != 0) {
			if (!character.takeDamage(monsterAtk)) {
				throw std::string("You were killed by the " + monster->getMonsterName() + "!\nGAME OVER");
			}
		}
	}
}