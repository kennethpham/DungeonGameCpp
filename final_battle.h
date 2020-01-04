#ifndef finalbattle_h
#define finalbattle_h

#include "battle.h"
#include "doggo.h"

namespace fb {
	class FinalBattle : public Battle {
	private:
		Monster * getDog(int stage) {
			Monster* m;
			switch (stage) {
			case 1:
				m = new Doggo;
				break;
			case 2:
				m = new Pup;
				break;
			case 3:
				m = new Pup;
				break;
			case 4:
				m = new ScaredDoggo;
				break;
			case 5:
				m = new MadDoggo;
				break;
			case 6:
				m = new FinalDoggo;
				break;
			}
			monsters.push_back(m); //first save to vector
			return m;
		}
		bool isDead;
		Monster* monster; //the current monster for the current battle
		std::vector<Monster*> monsters; //save pups/dogs to some vector
	public:
		int stage = 1;
		FinalBattle(Character& ch, Inventory& i) : Battle(ch, i, 11) {
			monster = getDog(stage);
		}

		~FinalBattle() {
			if (monsters.size() != 0) {
				for (size_t i = 0; i < monsters.size(); i++)
					delete monsters[i];
				monsters.clear();
			}
		}

		void nextStage() {
			stage += 1;
		}

		void performEvent();

		bool performTurn(int& doom, int& pups, int& turn);

		void displayCommands(int& turn, int& doom, std::string& userInput);

		void performMonsterAttk(int& monsterAtk);
	};
}
#endif //finalbattle_h