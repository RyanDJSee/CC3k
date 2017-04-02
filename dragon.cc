#include "dragon.h"
#include <string>
using namespace std;

class Subject;

Dragon::Dragon(int chamber, int r, int c):
    Enemy{chamber, r, c, 150, 20, 20} {}

string Dragon::getRep() const { return "D"; }

void Dragon::notify(Subject& whoNotified) {
    whoNotified.attackedBy(*this);
}

string Dragon::getName() { return "Dragon"; }
