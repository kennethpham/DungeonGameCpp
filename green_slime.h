#ifndef GREEN_SLIME_H
#define GREEN_SLIME_H

#include "monster.h"

class GreenSlime : public Monster {
public:
	GreenSlime() : Monster("Green Slime", 30, 8, 5, "Slime Toss", 5) {}
};
#endif
