#include "human.h"
#include <string>

using namespace std;

class Subject;

Human::Human(int chamber, int r, int c):
    Enemy{chamber, r, c, 140, 20, 20} {}

string Human::getRep() const{ return "H"; }

void Human::notify(Subject& whoNotified) {
    whoNotified.attackedBy(*this);
}

string Human::getName() const { return "Human"; }
