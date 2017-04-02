#include "vampire.h"
#include <math.h>
#include <memory>
#include "rh.h"
#include "dwarf.h"
using namespace std;


Vampire::Vampire(int chamber, int r, int c):
    PC(chamber, r, c, 50, 25, 25, -100) {}

void Vampire::notify(Subject& whoNotified) {
    whoNotified.attackedBy(*this);
}

void Vampire::attackedBy(Dwarf& dwarf) {
    if (!isSuccessAttacked()) return;
    int damage = 5;
    shared_ptr<Item> hp_ptr{new RH{-1, -1, -1, -damage}};
    use(hp_ptr);
}

string Vampire::getName() { return "Vampire"; }
