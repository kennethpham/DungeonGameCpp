#include "special_moves.h"

SpecialMove::SpecialMove(std::string n, int s, int d, int m) : name(n), statusEffect(s), damage(d), manaCost(m), canUse(false) {}

int SpecialMove::getDamage() const {
	return damage;
}

int SpecialMove::getManaCost() const {
	return manaCost;
}

void SpecialMove::setCanUse(bool b) {
	canUse = b;
}

bool SpecialMove::getCanUse() const {
	return canUse;
}

int SpecialMove::getStatusEffect() const {
	return statusEffect;
}

std::string SpecialMove::getMoveName() const {
	return name;
}

std::ostream& operator << (std::ostream& out, const SpecialMove& s) {
	std::string name = s.name + ": " + s.description;
	std::string damage = "Damage: " + std::to_string(s.damage), mana = "| Mana Cost: " + std::to_string(s.manaCost);
	out << std::setw(55) << name << std::setw(13) << damage << mana;
	if (s.canUse) {
		out << "\tUNLOCKED!";
	}
	else {
		out << "\t[LOCKED...]";
	}
	return out;
}