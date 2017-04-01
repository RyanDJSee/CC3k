#ifndef _PC_H_
#define _PC_H_
#include "character.h"
#include <string>
using namespace std;

class Human;
class Dwarf;
class Elf;
class Orcs;
class Merchant;
class Dragon;
class Halfling;

class PC: public Character {

    public:
    PC(int chamber, int row, int col, int hp, int atk, int def, int maxHP);
    string getRep() const;

    virtual void attackedBy(Human& human);
    virtual void attackedBy(Dwarf& dwarf);
    virtual void attackedBy(Elf& elf);
    virtual void attackedBy(Orcs& orcs);
    virtual void attackedBy(Merchant& merchant);
    virtual void attackedBy(Dragon& dragon);
    virtual void attackedBy(Halfling& halfling);

    virtual ~PC();
};

#endif
