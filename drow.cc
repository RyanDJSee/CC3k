#include "drow.h"
#include <string>
using namespace std;


Drow::Drow(int chamber, int r, int c):
    PC(chamber, r, c, 150, 25, 15, 150) {}

// whoNotified notifies that it can be attacked
void Drow::notify(Subject& whoNotified) {
    whoNotified.attackedBy(*this);
}

string Drow::getName() const { return "Drow"; }
