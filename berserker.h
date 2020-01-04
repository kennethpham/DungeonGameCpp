#ifndef BERSERKER_H
#define BERSERKER_H

#include "monster.h"

class Berserker : public Monster {
public:
	Berserker() : Monster("Berserker", 45, 30, 15, "Mace Pummel", 13) {}
};
#endif
