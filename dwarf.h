#ifndef _DWARF_H_
#define _DWARF_H_
#include "enemy.h"

class Subject;

class Dwarf: public Enemy {

    public:
    Dwarf(int r, int c);
    void notify(Subject& whoNotified) override;

    ~Dwarf();
};

#endif
