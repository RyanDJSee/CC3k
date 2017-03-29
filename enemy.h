#ifndef _ENEMY_H_
#define _ENEMY_H
#include "character.h"

class Enemy: public Character {

    public:
    Enemy();
    char getRep() = 0;

    void attackedBy(Shade& shade) = 0;
    void attackedBy(Globin& globin) = 0;
    void attackedBy(Vampire& vampire) = 0;
    void attackedBy(Troll& troll) = 0;
    void attackedBy(Drow& drow) = 0;

    void usedOn(Shade& shade) = 0;
    void usedOn(Globin& globin) = 0;
    void usedOn(Vampire& vampire) = 0;
    void usedOn(Troll& troll) = 0;
    void usedOn(Drow& drow) = 0;

    void addHP(int hp);
    virtual ~Enemy();
};

#endif
