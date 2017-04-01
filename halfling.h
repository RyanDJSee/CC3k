#ifndef _HALFING_H_
#define _HALFING_H_
#include "enemy.h"
#include <string>

class Subject;
class Shade;
class Globin;
class Vampire;
class Troll;
class Drow;

class Halfling final: public Enemy {

    public:
    Halfling(int chamber, int r, int c);
    std::string getRep() override;

    void notify(Subject& whoNotified) override;

    void attackedBy(Shade& shade) override;
    void attackedBy(Globin& globin) override;
    void attackedBy(Vampire& vampire) override;
    void attackedBy(Troll& troll) override;
    void attackedBy(Drow& drow) override;

    ~Halfling();
};

#endif