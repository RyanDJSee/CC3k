#ifndef _SHADE_H_
#define _SHADE_H
#include "pc.h"
class Human;
class Dwarf;
class Elf;
class Orcs;
class Merchant;
class Dragon;
class Halfling;

class Shade: public PC {
    
    public:
    Shade(int chamber, int r, int c);

    void attackedBy(Human& human) override;
    void attackedBy(Dwarf& dwarf) override;
    void attackedBy(Elf& elf) override;
    void attackedBy(Orcs& orcs) override;
    void attackedBy(Merchant& merchant) override;
    void attackedBy(Dragon& dragon) override;
    void attackedBy(Halfling& halfling) override;

    void usedOn(Human& human) override;
    void usedOn(Dwarf& dwarf) override;
    void usedOn(Elf& elf) override;
    void usedOn(Orcs& orcs) override;
    void usedOn(Merchant& merchant) override;
    void usedOn(Dragon& dragon) override;
    void usedOn(Halfling& halfling) override;

#if 0
    void usePotion(Treasure& t) override;
    void usePotion(RH& rh) override;
    void usePotion(BA& ba) override;
    void usePotion(BD& bd) override;
    void usePotion(PH& ph) override;
    void usePotion(WA& wa) override;
    void usePotion(WD& wd) override;
#endif

    ~Shade();
};

#endif
