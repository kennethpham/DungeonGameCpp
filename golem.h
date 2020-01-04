#ifndef GOLEM_H
#define GOLEM_H

#include "monster.h"

class Golem : public Monster {
public:
	Golem() : Monster("Golem", 79, 15, 30, "Rock Smash", 7) {}
};
#endif
