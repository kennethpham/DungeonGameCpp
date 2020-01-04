#ifndef NECROMANCER_H
#define NECROMANCER_H

#include "monster.h"

class Necromancer : public Monster {
public:
	Necromancer() : Monster("Necromancer", 90, 30, 35, "Rising of the Dead", 25) {}
};
#endif

