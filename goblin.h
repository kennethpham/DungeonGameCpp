#pragma once
#ifndef GOBLIN_H
#define GOBLIN_H

#include "monster.h"

class Goblin : public Monster {
public:
	Goblin() : Monster("Goblin", 20, 10, 13, "Tantrum", 5) {}
};
#endif
