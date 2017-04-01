#include "elf.h"
using namespace std;

Elf::Elf(int chamber, int r, int c):
    Enemy{chamber, r, c, 140, 30, 10} {}

char Elf::getRep() { return 'W'; }

void Elf::notify(Subject& whoNotified) {
    whoNotified.attackedBy(*this);
}

void Elf::attackedBy(Shade& shade) {
    int damage = ceil((100/(100 + getInfo().def))*shade.getInfo().atk);
    shared_ptr<Item> hp_ptr = make_shared{new RH{-1, -1, -1, -2*damage}};
    use(hp_ptr);
}

void Elf::attackedBy(Globin& globin) {
    int damage = ceil((100/(100 + getInfo().def))*globin.getInfo().atk);
    shared_ptr<Item> hp_ptr = make_shared{new RH{-1, -1, -1, -2*damage}};
    use(hp_ptr);
}

void Elf::attackedBy(Vampire& vampire) {
    int damage = ceil((100/(100 + getInfo().def))*vampire.getInfo().atk);
    shared_ptr<Item> hp_ptr = make_shared{new RH{-1, -1, -1, -2*damage}};
    use(hp_ptr);
}

void Elf::attackedBy(Troll& troll) {
    int damage = ceil((100/(100 + getInfo().def))*troll.getInfo().atk);
    shared_ptr<Item> hp_ptr = make_shared{new RH{-1, -1, -1, -2*damage}};
    use(hp_ptr);
}

