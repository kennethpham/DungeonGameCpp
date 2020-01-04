#ifndef	LADDER_H
#define LADDER_H

#include "event.h"
#include <iostream>

class Ladder : public Event {
public:
	Ladder(Character& ch, Inventory& i) : Event(ch, i, "<L>") {
	}

	void performEvent();
};
#endif