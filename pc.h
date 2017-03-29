#ifndef _PC_H_
#define _PC_H_
#include "character.h"

class PC: public Character {

    protected:
    int maxPH;
    bool wasDragonHoard;

    public:
    PC();
    char getRep();

    void attackedBy(Human& human) = 0;
    void attackedBy(Dwarf& dwarf) = 0;
    void attackedBy(Elf& elf) = 0;
    void attackedBy(Orcs& orcs) = 0;
    void attackedBy(Merchant& merchant) = 0;
    void attackedBy(Dragon& dragon) = 0;
    void attackedBy(Halfling& halfling) = 0;

    void usedOn(Human& human) = 0;
    void usedOn(Dwarf& dwarf) = 0;
    void usedOn(Elf& elf) = 0;
    void usedOn(Orcs& orcs) = 0;
    void usedOn(Merchant& merchant) = 0;
    void usedOn(Dragon& dragon) = 0;		
    void usedOn(Halfling& halfling) = 0;

#if 0
    void usePotion(Treasure& t) = 0;
    void usePotion(RH& rh) = 0;
    void usePotion(BA& ba) = 0;
    void usePotion(BD& bd) = 0;
    void usePotion(PH& ph) = 0;
    void usePotion(WA& wa) = 0;
    void usePotion(WD& wd) = 0;
#endif

    void addHP(int hp, int maxHP);
    virtual ~PC();
};

#endif
