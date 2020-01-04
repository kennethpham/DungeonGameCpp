#include "ladder.h"

void Ladder::performEvent() {
	if (character.getCurrentFloor() <= 8) {
		std::string input;
		std::cout << "\nYou found a ladder! Would you like to move to the next floor? (y/n): ";
		getline(std::cin, input);

		if (input == "y" || input == "Y") {
			character.moveToNextFloor();
		}
		isVisited = true;
	}
	else {
		std::string input;
		std::cout << "\nYou feel a powerful darkness up ahead...\nAre you absolutely certain you wish to face this power right now? (y/n): ";
		getline(std::cin, input);
		if (input == "y" || input == "Y") {
			character.moveToNextFloor();
		}
		isVisited = true;
	}
}