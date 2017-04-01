#ifndef _VAMPIRE_H_
#define _VAMPIRE_H
#include "pc.h"

class Subject;

class Vampire final: public PC {

    public:
    Vampire(int chamber, int r, int c);
    void notify(Subject& whoNotified) override;
    void attackedBy(Dwarf& dwarf) override;

    ~Vampire();
};

#endif
