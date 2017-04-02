#include "orc.h"
#include <string>

using namespace std;

Orc::Orc(int chamber, int r, int c):
    Enemy{chamber, r, c, 180, 30, 25} {}

string Orc::getRep() const { return "O"; }

void Orc::notify(Subject& whoNotified) {
    whoNotified.attackedBy(*this);
}

