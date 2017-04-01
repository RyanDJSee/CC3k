#ifndef _DRAGON_H_
#define _DRAGON_H_
#include "enemy.h"

class Subject;

class Dragon: public Enemy {

    public:
    Dragon(int r, int c);
    void notify(Subject& whoNotified) override;

    ~Dragon();
};

#endif
