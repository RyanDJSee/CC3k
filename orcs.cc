#include "orcs.h"
using namespace std;

Orcs::Orcs(int chamber, int r, int c):
    Enemy{chamber, r, c, 180, 30, 25} {}

char Orcs::getRep() { return 'O'; }

void Orcs::notify(Subject& whoNotified) {
    whoNotified.attackedBy(*this);
}

