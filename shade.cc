#include "shade.h"
#include <string>


Shade(int chamber, int r, int c, int hp = 125, int atk = 25, int def = 25):
    PC(chamber, r, c), hp{125}, atk{25}, def{25}, maxHP{125} {}

// attackedBy Enemies
void Shade::attackedBy(Human& human) { human.useOn(*this); }

void Shade::attackedBy(Dwarf& dwarf) { dwarf.useOn(*this); }

void Shade::attackedBy(Elf& elf) { elf.useOn(*this); }

void Shade::attackedBy(Orcs& orcs) { orcs.useOn(*this); }

void Shade::attackedBy(Merchant& merchant) { merchant.useOn(*this); }

void Shade::attackedBy(Dragon& dragon) { dragon.useOn(*this); }

void Shade::attackedBy(Halfling& halfling) { halfling.useOn(*this); }

// usedOn Enemies
void Shade::useOn(Human& human) {
    int damage = ceil((100/(100+ human.def))*this->atk);
    human.addHP(-damage);
}

void Shade::useOn(Dwarf& dwarf) {
    int damage = ceil((100/(100+ dwarf.def))*this->atk);
    dwarf.addHP(-damage);
}

void Shade::useOn(Elf& elf) {
    int damage = ceil((100/(100+ elf.def))*this->atk);
    elf.addHP(-damage);
}

void Shade::useOn(Orcs& orcs) {
    int damage = ceil((100/(100+ orcs.def))*this->atk);
    orcs.addHP(-damage);
}

void Shade::useOn(Merchant& merchant) {
    int damage = ceil((100/(100+ merchant.def))*this->atk);
    merchant.addHP(-damage);
}

void Shade::useOn(Dragon& dragon) {
    int damage = ceil((100/(100+ dragon.def))*this->atk);
    dragon.addHP(-damage);
}

void Shade::useOn(Halfling& halfling) {
    int damage = ceil((100/(100+ halfling.def))*this->atk);
    halfling.addHP(-damage);
}

// usePotion
void Shade::usePotion(Treasure& t) { t.useOn(*this); }
void Shade::usePotion(RH& rh) { rh.useOn(*this); }
void Shade::usePotion(BA& ba) { ba.useOn(*this); }
void Shade::usePotion(BD& bd) { bd.useOn(*this); }
void Shade::usePotion(PH& ph) { ph.useOn(*this); }
void Shade::usePotion(WA& wa) { wa.useOn(*this); }
void Shade::usePotion(WD& wd) { wd.useOn(*this); }
