#ifndef _MERCHANT_H_
#define _MERCHANT_H_
#include "enemy.h"
#include <string>

class Subject;
class Shade;
class Globin;
class Vampire;
class Troll;
class Drow;

class Merchant final: public Enemy {
    static bool isHostile;

    public:
    Merchant(int chamber, int r, int c);
    std::string getRep() override;

    void notify(Subject& whoNotified) override;

    void attackedBy(Shade& shade) override;
    void attackedBy(Globin& globin) override;
    void attackedBy(Vampire& vampire) override;
    void attackedBy(Troll& troll) override;
    void attackedBy(Drow& drow) override;

    ~Merchant();
};

#endif