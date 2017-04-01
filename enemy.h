#ifndef _ENEMY_H_
#define _ENEMY_H
#include "character.h"
#include "subject.h"

class Shade;
class Goblin;
class Vampire;
class Troll;
class Drow;

class Enemy: public Character {

    public:
    Enemy(int chamber, int row, int col, int hp, int atk, int def);
    virtual char getRep() = 0;

    virtual void attackedBy(Shade& shade) override;
    virtual void attackedBy(Goblin& goblin) override;
    virtual void attackedBy(Vampire& vampire) override;
    virtual void attackedBy(Troll& troll) override;
    virtual void attackedBy(Drow& drow) override;

    virtual ~Enemy();
};

#endif
