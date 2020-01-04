#ifndef NO_EVENT_H
#define NO_EVENT_H

#include "event.h"
#include <iostream>

class NoEvent : public Event {
public:
	NoEvent(Character& ch, Inventory& i) : Event(ch, i) {
		
	}

	void performEvent() {
		isVisited = true;
		return;
	}
};

#endif
