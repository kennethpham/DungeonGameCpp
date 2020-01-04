#ifndef SKELETONKING_H
#define SKELETONKING_H

#include "monster.h"

class SkeletonKing : public Monster {
public:
	SkeletonKing() : Monster("Skeleton King", 80, 50, 35, "Sword Slash", 20) {}
};
#endif
