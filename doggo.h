#ifndef DOGGO_H
#define DOGGO_H

#include "monster.h"

class Doggo : public Monster {
public:
	Doggo() : Monster("Doggo", 150, 75, 50, "Kibble", 25) {} // Kibble is a healing ability that heals the Doggo for 20 health
	virtual std::string aName() { return "Kibble"; }
	virtual int aPower() { return 50; }
	virtual int attack() { // for Doggo
		if (status == SLP) {
			sleepCount--;

			if (sleepCount > 0) {
				std::cout << this->name << " is fast asleep" << std::endl;
				return 0;
			}
			else {
				std::cout << this->name << " woke up!" << std::endl;
				status = -1; //no status
			}
		}
		else if (status == PAR) {
			if (rand() % 100 < 35) { //35% chance to not attack
				std::cout << this->name << " cannot move due to paralysis!" << std::endl;
				return 0;
			}
		}

		if (rand() % 7 < 2) { // special attack - should be 33% for special and 66% for normal, but this method has mod bias
			healMonster(35);
			return -aPower(); 
		}
		else { //regular attack
			return stats[ATK];
		}
	}

	virtual void printAscii() const {
		std::cout << R"(
            |\
   \`-. _.._| \
    |_,'  __`. \
    (.\ _/.| _  |
   ,'      __ \ |
 ,'     __/||\  |
(..)  ,/|||||/  |
   `-'_----    /
      /`-._.-'/
      `-.__.-' 
		)" << std::endl;
	}
};

class ScaredDoggo : public Monster {
public:
	ScaredDoggo() : Monster("Scared Doggo", 1000, 1, 0, "Cry", 80) {}
	ability PackLeader = ability("Cry", 5); 
	virtual std::string aName() { return PackLeader.abilityName; }
	virtual int aPower() { return PackLeader.power; }
	void printAscii() const {
		std::cout << R"(
                              ,.  , 
                          .-. \ \| \ 
             ,---._    _,-.> `.\ \ ( 
            (__,'  `   `>-         -\ 
                     ,-'             `-. 
         ,-'       ,  ,    .       .    `. 
       ,'\       ,' ,-'    `-.      ;    :`. 
      (__;     ,',,'      ,   `     : `. :  \ 
             ,' |  _,'   /_    `    :  ; :   \ 
            /  ,',' |   /  \        '     ;   \ 
           /   | |(o|  /  (o)          |  |    ; 
          /     ___-^-^-----.          |  |    | 
         (   ,---. `-.           :.    |       : 
          ;,'      )  `          :..   |        | 
          :\      /              :.    |        ; 
          :.`-.__,              ,:`    |        | 
          ;`.    .             ':'      \      , 
         /   `-.__\           '      ,   \     \. 
        (   ,'    \`--,-----.       /     \     \`. 
         `-'       \,' ,'   /    / |       \     | `. 
                   /  '   ,'    /-.|        `.   ;   `. 
                  (      /`----'   |          `--'     ` 
                   `.__,' 
 )" << std::endl << std::endl;
	}
};

class MadDoggo : public Monster {
public:
	MadDoggo() : Monster("Mad Doggo", 200, 100, 30, "Rabid Bite", 20) {}
	ability DogEatDog = ability("Rabid Bite", 20); // If Puppers are still alive after the counter, the Doggo will eat them and heal up
	virtual std::string aName() { return DogEatDog.abilityName; }
	virtual int aPower() { return DogEatDog.power; }

	void printAscii() const {
		std::cout << R"(
                                           /\ /\
                                          /  \---._
                                         / / `     `\
                                         \ \   `'<@)@)      
                                         /`         ~ ~._ 
                                        /                `() 
                                       /    \   (` ,_.:.  /
                                      / ~    `\   (vVvvvvV
                                     /       |`\_ `^^^/
                                 ___/________|_  `---'
                                (_____R_E_X____) _
                                _/~          | `(_)
                              _/~             \  
                            _/~               |
                          _/~                 |
                        _/~                   |
                      _/~         ~.          |
                    _/~             \        /\
                 __/~               /`\     `||
               _/~      ~~-._     /~   \     ||
              /~             ~./~'      \    |)
             /                 ~.        \   )|
            /                    :       |   ||
            |                    :       |   ||
            |                   .'       |   ||
       __.-`                __.'--.      |   |`---. 
    .-~  ___.         __.--~`--.))))     |   `---.)))
   `---~~     `-...--.________)))))      \_____)))))
		)" << std::endl << std::endl;
	}
};

class FinalDoggo : public Monster {
public:
	FinalDoggo() : Monster("Final Doggo", 150, 0, 0, "Armadoggen", 0) {}
	ability DeadAsDog = ability("Armadoggen", 99999); // Charges up for a few turns, then does massive damage
	virtual std::string aName() { return DeadAsDog.abilityName; }
	virtual int aPower() { return DeadAsDog.power; }

	void printAscii() const {
		std::cout << R"(
       _
      / \`.
     ||  \ \
     \\  |  \.:```````-.
      \\_/    '-.  .:```-.
      /-.\      `.   .:`-.`_
     |_O.'       |     .`-. `.       _...-----.._
    /`-._       .'   .'    `----'''''            `.
   /      \ _.-'    /                              `.
  /    .- |         |    .'                      `.  \
 (_/ .'  .'.        |    '               .'        \  \
   `-'`-'  ):.      |    :  /            .         |   \
             ):.    '       |__.:`..:::..|         |    \
               ):.   \      |      __.....\        |\    `:.     .`|
                 ))```\      `_..-`  |     \       | \      `-_-'  /
                    \ |      \       |     '       `. \        _.-'
                     \|     .'       |      \       `. `.   __..-`
                      |    |         \      /`.      `.  `-._.-`
                      |    '          `.    |  `.      `-.
                      '   .'            \  / \   `-.    / ]
                    .'   .'|            /  ' ]      |  ' .'
                    .'-. | |          .'  .-'       /   /
                    |   \| '    _.-..'   /         /   |
                   .'    |/    / .-.    /       .-'    /
                .-'      '    /_/___\__/     .'.' .'  |
              .'.' .'  ./                   ( (  (   .'
             ( (  (   .'                     `-`--`-`
              `-`--`-`
)" << std::endl << std::endl;
	}
};

class Pup : public Monster {
public:
	Pup() : Monster("Pupper", 300, 150, 50, "Bork", 10) {} // Bork is an ability that the Pups use that buffs them up, stacking
	int attack() { // for Pup
		if (rand() % 3 < 2) { // special attack - should be 33% for special and 66% for normal, but this method has mod bias
			std::cout << "The pupper howls and gains a stat boost!" << std::endl;
			setStat(HP, getHP() + move.power); // Buffs the Pup with Bork 
			setStat(ATK, getATK() + move.power);
			setStat(DEF, getDEF() + move.power);
			return -5;
		}
		else { //regular attack
			return stats[ATK];
		}
	}

	void printAscii() const {
		std::cout << R"(
  ,_____ ,
  ,._ ,_. 7\
 j `-'     /
 |o_, o    \
.`_y_`-,'   !
|/   `, `._ `-,
|_     \   _.'*\
  >--,-'`-'*_*'``---.
  |\_* _*'-'         '
 /    `               \
 \.         _ .       /
  '`._     /   )     /
   \  |`-,-|  /c-'7 /
    ) \ (_,| |   / (_
   ((_/   ((_;)  \_)))
		)" << std::endl << std::endl;
	}
};

#endif
