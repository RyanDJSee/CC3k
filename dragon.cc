#include "dragon.h"
using namespace std;

Dragon::Dragon(int chamber, int r, int c):
    Enemy{chamber, r, c, 150, 20, 20} {}

char Dragon::getRep() { return 'D'; }

void Dragon::notify(Subject& whoNotified) {
    whoNotified.attackedBy(*this);
}

