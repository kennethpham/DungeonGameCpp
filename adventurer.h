#include <string>
#include <vector> 
#include "character.h"

class Adventurer : public Character // A character that gets bonus upgrades when upgrading items 
{
private:
	int upgradeFactor = 2;
						   
public:
	Adventurer();
};
