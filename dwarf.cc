#include "dwarf.h"
using namespace std;

Dwarf::Dwarf(int chamber, int r, int c):
    Enemy{chamber, r, c, 140, 20, 20} {}

char Dwarf::getRep() { return 'W'; }

void Dwarf::notify(Subject& whoNotified) {
    whoNotified.attackedBy(*this);
}

