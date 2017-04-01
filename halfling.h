#ifndef _HALFING_H_
#define _HALFING_H_
#include "enemy.h"

class Subject;

class Enemy: public Enemy {

    public:
    Halfing(int r, int c);
    void notify(Subject& whoNotified) override;

    void attackedBy(Shade& shade) override;
    void attackedBy(Globin& globin) override;
    void attackedBy(Vampire& vampire) override;
    void attackedBy(Troll& troll) override;
    void attackedBy(Drow& drow) override;

    ~Halfing();
};

#endif
