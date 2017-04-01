#ifndef _ORCS_H_
#define _ORCS_H_
#include "enemy.h"

class Subject;

class Orcs: public Enemy {

    public:
    Orcs(int r, int c);
    void notify(Subject& whoNotified) override;

    ~Orcs();
};

#endif
