#ifndef _ELF_H_
#define _ELF_H_
#include "enemy.h"
#include <string>

class Subject;
class Shade;
class Globin;
class Vampire;
class Troll;

class Elf final: public Enemy {

    public:
    Elf(int chamber, int r, int c);
    std::string getRep() const;

    void notify(Subject& whoNotified) override;

    void attackedBy(Shade& shade) override;
    void attackedBy(Goblin& goblin) override;
    void attackedBy(Vampire& vampire) override;
    void attackedBy(Troll& troll) override;

    ~Elf();
};

#endif
