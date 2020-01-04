#ifndef items_h
#define items_h

#include <iostream>
#include <string>

#include "character.h"

namespace I {
    class Items {
    protected:
        Character & ch;
        bool canSell;
    public:
        Items(Character& c, bool cS = true) : ch(c), canSell(cS) {}

        virtual std::string info() const = 0;
        virtual std::string getName() const = 0;
        virtual int getPrice() const { return 0; };
        virtual int getSellPrice() const { return 0; };
        virtual void consume(){}
        virtual void upgradeWeapon() {}
        virtual std::string getPotency() const { return ""; }
        virtual void upgradeArmor() {}

        bool getCanSell() const { return canSell; }
    };
}
#endif // items_h
