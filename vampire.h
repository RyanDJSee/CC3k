#ifndef _VAMPIRE_H_
#define _VAMPIRE_H
#include "pc.h"
#include <string>

class Subject;

class Vampire final: public PC {

    public:
    Vampire(int chamber, int r, int c);
    void notify(std::shared_ptr<Subject>& whoNotified) override;
    void attackedBy(Dwarf& dwarf) override;
    std::string getName() const override;

    ~Vampire();
};

#endif
