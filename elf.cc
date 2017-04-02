#include "elf.h"
#include "shade.h"
#include "globin.h"
#include "vampire.h"
#include "troll.h"
#include <string>
#include <math.h>
#include "rh.h"


using namespace std;

Elf::Elf(int chamber, int r, int c):
    Enemy{chamber, r, c, 140, 30, 10} {}

string Elf::getRep() const { return "W"; }

void Elf::notify(Subject& whoNotified) {
    whoNotified.attackedBy(*this);
}

void Elf::attackedBy(Shade& shade) {
    int damage = ceil((100/(100 + getInfo().def))*shade.getInfo().atk);
    shared_ptr<Item> hp_ptr{new RH{-1, -1, -1, -2*damage}};
    use(hp_ptr);
}

void Elf::attackedBy(Goblin& goblin) {
    int damage = ceil((100/(100 + getInfo().def))*globin.getInfo().atk);
    shared_ptr<Item> hp_ptr{new RH{-1, -1, -1, -2*damage}};
    use(hp_ptr);
}

void Elf::attackedBy(Vampire& vampire) {
    int damage = ceil((100/(100 + getInfo().def))*vampire.getInfo().atk);
    shared_ptr<Item> hp_ptr{new RH{-1, -1, -1, -2*damage}};
    use(hp_ptr);
}

void Elf::attackedBy(Troll& troll) {
    int damage = ceil((100/(100 + getInfo().def))*troll.getInfo().atk);
    shared_ptr<Item> hp_ptr{new RH{-1, -1, -1, -2*damage}};
    use(hp_ptr);
}
