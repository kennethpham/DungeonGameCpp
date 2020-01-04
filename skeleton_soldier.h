#ifndef SKELETON_SOLDIER_H
#define SKELETON_SOLDIER_H

#include "monster.h"

class SkeletonSoldier : public Monster {
public:
	SkeletonSoldier() : Monster("Skeleton Soldier", 45, 32, 20, "Sword Slash", 8) {}
};
#endif
