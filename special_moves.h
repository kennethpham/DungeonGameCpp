#ifndef SPECIAL_MOVES_H
#define SPECIAL_MOVES_H

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

class SpecialMove {
protected:
	std::string name;
	std::string description;
	enum status { PSN, SLP, PAR, statusNum };
	int statusEffect;
	int damage;
	int manaCost;
	bool canUse;


public:
	SpecialMove(std::string n, int s, int d, int m);

	int getDamage() const;

	int getManaCost() const;

	void setCanUse(bool b);

	bool getCanUse() const;

	int getStatusEffect() const;

	std::string getMoveName() const;

	friend std::ostream& operator << (std::ostream& out, const SpecialMove& s);
};

namespace Moves{

	class ParalyzingShock : public SpecialMove {
	public:
		ParalyzingShock() : SpecialMove("Paralyzing Shock", PAR, 15, 15) {
			description = "small shock that causes paralysis";
		}
	};

	class ForbiddenChant : public SpecialMove {
	public:
		ForbiddenChant() : SpecialMove("Forbidden Chant", SLP, 10, 15) {
			description = "weak ability that induces sleep";
		}
	};

	class ToxicStar : public SpecialMove {
	public:
		ToxicStar() : SpecialMove("Toxic Star", PSN, 15, 15) {
			description = "deal damage and poison enemy";
		}
	};
};

#endif
