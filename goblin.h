#ifndef _GOBLIN_H_
#define _GOBLIN_H_
#include "pc.h"

class Orc;
class Subject;

class Goblin final: public PC {

    public:
    Goblin(int chamber, int r, int c);
    void notify(Subject& whoNotified) override;
    void attackedBy(Orc& orc) override;

    ~Goblin();
};

#endif
