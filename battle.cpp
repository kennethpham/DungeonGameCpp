#include "battle.h"

Monster* Battle::getRandMonster() {
	Monster* m;

	/* Floor specific monster generation*/
	switch (floorNumber/ 4 + 1) {
	case 1:
		switch (rand() % 3 + 1) {
		case 1:
			m = new AngrySpider;
			break;
		case 2:
			m = new Goblin;
			break;
		case 3:
			m = new GreenSlime;
			break;
		default:
			m = new AngrySpider;
		}
		m->setGold(rand() % 100 + 50);
		break;
	case 2:
		switch (rand() % 4 + 1) {
		case 1:
			m = new SkeletonSoldier;
			break;
		case 2:
			m = new Chimera;
			break;
		case 3:
			m = new Golem;
			break;
		case 4:
			m = new Berserker;
			break;
		default:
			m = new SkeletonSoldier;
		}
		m->setGold(rand() % 200 + 75);
		break;
	case 3:
		switch (rand() % 3 + 1) {
		case 1:
			m = new Necromancer;
			break;
		case 2:
			m = new BulkyOrc;
			break;
		case 3:
			m = new SkeletonKing;
			break;
		default:
			m = new Necromancer;
		}
		m->setGold(rand() % 999 + 450);
		break;
	default:
		m = new AngrySpider;
	}

	monsters.push_back(m); //first save to vector
	return m;
}

Battle::Battle(Character& ch, Inventory& i, int f) : Event(ch, i, "<B>"), isDead(false), floorNumber(f) {
	monster = getRandMonster();
}

Battle::~Battle() {
	if (monsters.size() != 0) {
		for (unsigned i = 0; i < monsters.size(); i++)
			delete monsters[i];
		monsters.clear();
	}
}

void Battle::performEvent() {
	if (!isDead) {
		int maxHP = monster->getHP();
		std::cout << "You ran into a " << monster->getMonsterName() << "!\n" << std::endl;

		while (character.getCurrHP() > 0 && monster->getHP() > 0) {
			std::cout << "Enemy HP: " << monster->getHP();
			if (monster->getStatus() >= 0) {
				std::cout << "   Enemy Status: " << monster->getStrStatus();
			}
			std::cout << "   Your HP: " << character.getCurrHP() << "/" << character.getHP();
			std::cout << "   Your Mana: " << character.getCurrMana() << "/" << character.getMana() << std::endl;
			

			std::string userInput;
			int count = 0;
			do {
				if (count > 0) {
					std::cout << "Please enter valid input\n\n";
				}
				std::cout << "--COMMANDS--\n";
				std::cout << "Attack: 'enter key'\n";
				std::cout << "Use special ability: 's'\n";
				std::cout << "Run Away: 'run'\n";
				std::cout << "Open Invntory: 'o'\n";
				std::cout << "Input which command you want: ";
				std::getline(std::cin, userInput);
				std::cout << "\n";
				std::transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);
				count++;
			} while (userInput != "run" && userInput != "o" && userInput != "s" && userInput != "");
			if (userInput == "run") {
				isVisited = true;
				return;
			}
			else if (userInput == "o") {
				if (i.useInventory()) { //If the user used an item
					if (monster->getHP() > 0) {
						monsterAttack(maxHP);
					}
				}

			}
			else if (userInput == "s") {
				int n, dmg;
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
				} while (!validMove);
		
				
				if (dmg != 0) { //0 means not enough mana
					monster->takeDamage(dmg);

					if (monster->getHP() > 0) {
						monsterAttack(maxHP);
					}
				}
			}
			else {
				std::cout << "\nYou attack the " << monster->getMonsterName() << std::endl;
				monster->takeDamage(character.attack());

				if (monster->getHP() > 0) {
					monsterAttack(maxHP);
				}
			}

			std::cout << std::endl;
		}

		isVisited = true;
		if (monster->getHP() <= 0) {
			isDead = true;
			std::cout << "You successfully killed the " << monster->getMonsterName() << "!" << std::endl;
			std::cout << "You gained " << monster->getGold() << " gold" << std::endl;
			character.addMoney(monster->getGold());
		}
		std::cout << std::endl;
	}
}

void Battle::monsterAttack(int maxHP) {
	int monsterAtk = monster->attack();

	if (monsterAtk < 0) { //I set it up so neg damage means special attack
		std::cout << "The " << monster->getMonsterName() << " used " << monster->getAbilityName() << "!" << std::endl;
		monsterAtk *= -1;
	}
	else if (monsterAtk > 0) { //regular attack
		std::cout << "The " << monster->getMonsterName() << " attacks!" << std::endl;
	}
	//If monsterAtk == 0, then monster is asleep or paralyzed & didn't attack

	if (!character.takeDamage(monsterAtk)) {
		throw std::string("You were killed by the " + monster->getMonsterName() + "!\nGAME OVER");
	}

	if (monster->getStatus() == 0) { //if monster is poisoned
		int dmg = static_cast<int>(maxHP * .1);
		monster->takePoisonDamage(dmg);
		std::cout << monster->getMonsterName() << " took " << dmg << " damage due to poison!" << std::endl;
	}
}

std::string Battle::getSymbol() const {
	return isDead ? " ." : (isVisited ? "<B>" : notVisitedSymbol); //show '.' if not dead, and <B> if otherwise
}

std::vector<Monster*> Battle::monsters;
