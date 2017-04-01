#ifndef _ELF_H_
#define _ELF_H_
#include "enemy.h"

class Subject;

class Elf: public Enemy {

    public:
    Elf(int r, int c);
    void notify(Subject& whoNotified) override;

    void attackedBy(Shade& shade) override;
    void attackedBy(Globin& globin) override;
    void attackedBy(Vampire& vampire) override;
    void attackedBy(Troll& troll) override;

    ~Elf();
};

#endif
