#include "halfling.h"
#include "shade.h"
#include "vampire.h"
#include "troll.h"
#include "drow.h"
#include "goblin.h"
#include <string>
#include <math.h>
#include "rh.h"
#include "item.h"


using namespace std;

Halfling::Halfling(int chamber, int r, int c):
    Enemy{chamber, r, c, 100, 15, 20} {}

string Halfling::getRep() { return "L"; }

void Halfling::notify(Subject& whoNotified) {
    whoNotified.attackedBy(*this);
}

void Halfling::attackedBy(Shade& shade) {
    if (!isSuccessAttacked()) return;
    int damage = ceil((100/(100 + getInfo().def))*shade.getInfo().atk);
    shared_ptr<Item> hp_ptr{new RH{-1, -1, -1, -2*damage}};
    use(hp_ptr);
}

void Halfling::attackedBy(Goblin& goblin) {
    if (!isSuccessAttacked()) return;
    int damage = ceil((100/(100 + getInfo().def))*goblin.getInfo().atk);
    shared_ptr<Item> hp_ptr{new RH{-1, -1, -1, -2*damage}};
    use(hp_ptr);
}

void Halfling::attackedBy(Drow& drow) {
    if (!isSuccessAttacked()) return;
    int damage = ceil((100/(100 + getInfo().def))*drow.getInfo().atk);
    shared_ptr<Item> hp_ptr{new RH{-1, -1, -1, -2*damage}};
    use(hp_ptr);
}

void Halfling::attackedBy(Vampire& vampire) {
    if (!isSuccessAttacked()) return;
    int damage = ceil((100/(100 + getInfo().def))*vampire.getInfo().atk);
    shared_ptr<Item> hp_ptr{new RH{-1, -1, -1, -2*damage}};
    use(hp_ptr);
}

void Halfling::attackedBy(Troll& troll) {
    if (!isSuccessAttacked()) return;
    int damage = ceil((100/(100 + getInfo().def))*troll.getInfo().atk);
    shared_ptr<Item> hp_ptr{new RH{-1, -1, -1, -2*damage}};
    use(hp_ptr);
}
