#ifndef CHIMERA_H
#define CHIMERA_H

#include "monster.h"

class Chimera : public Monster {
public:
	Chimera() : Monster("Chimera", 60, 20, 24, "Maul", 8) {}
};
#endif
