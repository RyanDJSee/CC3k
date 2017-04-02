#include "character.h"
#include "subtype.h"
#include "rh.h"
#include <math.h>
#include <string>
#include "pc.h"
#include "cell.h"
#include "human.h"
#include "dwarf.h"
#include "elf.h"
#include "orc.h"
#include "merchant.h"
#include "dragon.h"
#include "halfling.h"


using namespace std;

PC::PC(int chamber, int row, int col, int hp, int atk, int def, int maxPH):
    Character(chamber, row, col, hp, atk, def, maxHP) {}

string PC::getRep() const { return "@"; }

void PC::attackedBy(Human& human) {
    if (!isSuccessAttacked()) return;
    int damage = ceil((100/(100+ getInfo().def))*human.getInfo().atk);
    shared_ptr<Item> hp_ptr{new RH{-1, -1, -1, -damage}};
    use(hp_ptr);
}

void PC::attackedBy(Dwarf& dwarf) {
    if (!isSuccessAttacked()) return;
    int damage = ceil((100/(100+ getInfo().def))*dwarf.getInfo().atk);
    shared_ptr<Item> hp_ptr{new RH{-1, -1, -1, -damage}};
    use(hp_ptr);
}

void PC::attackedBy(Elf& elf) {
    if (!isSuccessAttacked()) return;
    int damage = ceil((100/(100+ getInfo().def))*elf.getInfo().atk);
    shared_ptr<Item> hp_ptr{new RH{-1, -1, -1, -damage}};
    use(hp_ptr);
}

void PC::attackedBy(Orc& orc) {
    if (!isSuccessAttacked()) return;
    int damage = ceil((100/(100+ getInfo().def))*orc.getInfo().atk);
    shared_ptr<Item> hp_ptr{new RH{-1, -1, -1, -damage}};
    use(hp_ptr);
}

void PC::attackedBy(Merchant& merchant) {
    if (!isSuccessAttacked()) return;
    int damage = ceil((100/(100+ getInfo().def))*merchant.getInfo().atk);
    shared_ptr<Item> hp_ptr{new RH{-1, -1, -1, -damage}};
    use(hp_ptr);
}

void PC::attackedBy(Dragon& dragon) {
    if (!isSuccessAttacked()) return;
    int damage = ceil((100/(100+ getInfo().def))*dragon.getInfo().atk);
    shared_ptr<Item> hp_ptr{new RH{-1, -1, -1, -damage}};
    use(hp_ptr);
}

void PC::attackedBy(Halfling& halfling) {
    if (!isSuccessAttacked()) return;
    int damage = ceil((100/(100+ getInfo().def))*halfling.getInfo().atk);
    shared_ptr<Item> hp_ptr{new RH{-1, -1, -1, -damage}};
    use(hp_ptr);
}

PC::~PC() {}
