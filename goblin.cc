#include "goblin.h"
#include "orc.h"
#include <string>
#include <math.h>
#include <memory>
#include "rh.h"
using namespace std;


Goblin::Goblin(int chamber, int r, int c):
    PC(chamber, r, c, 110, 15, 25, 110) {}

// whoNotified notifies that it can be attacked
void Goblin::notify(shared_ptr<Subject>& whoNotified) {
    whoNotified->attackedBy(*this);
}

void Goblin::attackedBy(Orc& orc) { // Orcs does 50% more damage to globins
    if (!isSuccessAttacked()) return;
    int damage = ceil((100/(100+ getInfo().def))*orc.getInfo().atk);
    shared_ptr<Item> hp_ptr{new RH{-1, -1, -1, (int)ceil(-1.5*damage)}};
}

string Goblin::getName() const { return "Goblin"; }

Goblin::~Goblin(){}
