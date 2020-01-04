#ifndef BULKYORC_H
#define BULKYORC_H

#include "monster.h"

class BulkyOrc : public Monster {
public:
	BulkyOrc() : Monster("Bulky Orc", 100, 30, 60, "Axe Swing", 15) {}
};
#endif
