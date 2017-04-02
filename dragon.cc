#include "dragon.h"
#include <string>
#include <memory>

using namespace std;

class Subject;

Dragon::Dragon(int chamber, int r, int c):
    Enemy{chamber, r, c, 150, 20, 20} {}

string Dragon::getRep() const { return "D"; }

void Dragon::notify(shared_ptr<Subject>& whoNotified) {
    whoNotified->attackedBy(*this);
}

string Dragon::getName() const { return "Dragon"; }
