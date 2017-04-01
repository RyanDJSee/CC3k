#include "human.h"
using namespace std;

Human::Human(int chamber, int r, int c):
    Enemy{chamber, r, c, 140, 20, 20} {}

char Human::getRep() { return 'H'; }

void Human::notify(Subject& whoNotified) {
    whoNotified.attackedBy(*this);
}

