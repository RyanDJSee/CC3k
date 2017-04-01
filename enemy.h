#ifndef _ENEMY_H_
#define _ENEMY_H
#include "character.h"
#include "subject.h"

class Shade;
class Globin;
class Vampire;
class Troll;
class Drow;

class Enemy: public Character {

    public:
    Enemy(int chamber, int row, int col, int hp, int atk, int def);
    virtual char getRep() = 0;

    virtual void attackedBy(Shade& shade);
    virtual void attackedBy(Globin& globin);
    virtual void attackedBy(Vampire& vampire);
    virtual void attackedBy(Troll& troll);
    virtual void attackedBy(Drow& drow);

    virtual ~Enemy();
};

#endif
