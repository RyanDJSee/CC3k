#ifndef _HUMAN_H_
#define _HUMAN_H_
#include "enemy.h"

class Shade;
class Globin;
class Drow;
class Vampire;
class Troll;

class Human: public Enemy {

    public:
    Human(int chamber, int r, int c, int hp, int atk, int def);
    char getRep() override;

    void attackedBy(Shade& shade) override;
    void attackedBy(Globin& globin) override;
    void attackedBy(Drow& drow) override;
    void attackedBy(Vampire& vampire) override;
    void attackedBy(Troll& troll) override;

    void usedOn(Shade& shade) override;
    void usedOn(Globin& globin) override;
    void usedOn(Drow& drow) override;
    void usedOn(Vampire& vampire) override;
    void usedOn(Troll& troll) override;


};

#endif

