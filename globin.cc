#include "globin.h"
#include <string>
using namespace std;


Globin(int r, int c):
    PC(r, c, 110, 15, 25, 110} {}

// whoNotified notifies that it can be attacked
void Globin::notify(Subject& whoNotified) {
    whoNotified.attackedBy(*this);
}

void Globin::attackedBy(Orcs& orcs) { // Orcs does 50% more damage to globins
    if (!isSuccessAttacked()) return;
    int damage = ceil((100/(100+ getInfo().def))*orcs.getInfo().atk);
    shared_ptr<Item> hp_ptr = make_shared{new RH{-1, -1, -1, -1.5*damage}};
    use(hp_ptr);
}
