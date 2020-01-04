#include <iostream>
#include <string>
#include <iomanip>

#include "dungeon.h"

//Character Classes
#include "adventurer.h"
#include "assassin.h"
#include "alcoholic.h"


using namespace std;

int main() {
	int choice;
	Character* cPtr = nullptr;
	bool valid;


	cout << "Welcome to DUNGEON EXPLORER, hero!" << endl;
	cout << "Your job will be to traverse through 10 dangerous floors and make it to the top of the dungeon" << endl;
	cout << "But beware, the top of the dungeon is home to a very dangerous monster..." << endl;
	cout << "\n\tpress any key to continue";
	cin.get();
	cout << "-------------------------------------------" << endl;
	cout << "Your job will be to search around every floor to find the ladder to the next floor" << endl;
	cout << "While searching, you may find chests containing goodies!" << endl;
	cout << "You may also find monsters that aren't so happy you bumped into them" << endl;
	cout << "Monsters may be difficult to take on at first, but when you beat them, they will drop gold!" << endl;
	cout << "You can spend gold at Grendel's Shop, once you find it, to heal or power yourself up." << endl;
	cout << "\n\tpress any key to continue";
	cin.get();
	cout << "-------------------------------------------" << endl;
	cout << "Now I can sit here and bore you to death, or you can get started on your daring quest!" << endl;
	cout << "Just make sure you are strong enough to take on the final boss.\nIt certainly would be a shame to go all that way just to die..." << endl;
	cout << "\n\tpress any key to continue";
	cin.get();
	cout << "-------------------------------------------" << endl;
	cout << "Now then! Pick your class below and let the journey begin!" << endl;
	cout << "-------------------------------------------" << endl;

	do {
		valid = true;
		cout << "1) Adventurer - basic stats, upgrade weapons more quickly" << endl;
		cout << "2) Assassin - chance to deal double damage when attacking and chance to dodge attacks" << endl;
		cout << "3) Alcoholic - take % reduced damage and gain a special ability" << endl;
		cin >> choice;

		if (choice == 1) {
			cPtr = new Adventurer();
		}
		else if (choice == 2) {
			cPtr = new Assassin();
		}
		else if (choice == 3) {
			cPtr = new Alcoholic();
		}
		else {
			valid = false;
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "\nI'm not sure what class that is. Try entering the number next to the class\n";
		}

		cout << endl;
	} while (!valid);


	Dungeon d(cPtr);
	d.play();

	delete cPtr;
}
