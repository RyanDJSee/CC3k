#ifndef _ORCS_H_
#define _ORCS_H_
#include "enemy.h"

class Subject;

class Orcs final: public Enemy {

    public:
    Orcs(int chamber,int r, int c);
    void notify(Subject& whoNotified) override;

    ~Orcs();
};

#endif
