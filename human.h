#ifndef _HUMAN_H_
#define _HUMAN_H_
#include "enemy.h"

class Human: public Enemy {

    public:
    Human(int chamber, int r, int c);
    char getRep() override;
    void notify(Subject& whoNotified) override;

    ~Human();

};

#endif

