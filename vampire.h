#ifndef _VAMPIRE_H_
#define _VAMPIRE_H
#include "pc.h"

class Subject;

class Vampire: public PC {

    public:
    Vampire(int r, int c);
    void notify(Subject& whoNotified) override;    
    void attackedBy(Dwarf& dwarf) override;

    ~Vampire();
};

#endif
