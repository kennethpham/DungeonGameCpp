#pragma once
#ifndef ANGRYSPIDER_H
#define ANGRYSPIDER_H

#include "monster.h"

class AngrySpider : public Monster {
public:
	AngrySpider() : Monster("Angry Spider", 25, 13, 8, "Web Shot", 5) {}
};
#endif
