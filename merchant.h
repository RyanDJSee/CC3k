#ifndef _MERCHANT_H_
#define _MERCHANT_H_
#include "enemy.h"

class Subject;

class Merchant: public Enemy {
    static bool isHostile;

    public:
    Merchant(int r, int c);
    void notify(Subject& whoNotified) override;

    void attackedBy(Shade& shade) override;
    void attackedBy(Globin& globin) override;
    void attackedBy(Vampire& vampire) override;
    void attackedBy(Troll& troll) override;
    void attackedBy(Drow& drow) override;

    ~Merchant();
};

#endif
