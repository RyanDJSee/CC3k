#include "vampire.h"
using namespace std;


Vampire(int r, int c):
    PC(r, c, 50, 25, 25, -100} {}

void Vampire::notify(Subject& whoNotified) {
    whoNotified.attackedBy(*this);
}

void Vampire::attackedBy(Dwarf& dwarf) {
    if (!isSuccessAttacked()) return;
    int damage = 5;
    shared_ptr<Item> hp_ptr = make_shared{new RH{-1, -1, -1, -damage}};
    use(hp_ptr);
}

