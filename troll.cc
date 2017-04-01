#include "troll.h"
#include <string>
using namespace std;


Troll::Troll(int chamber, int r, int c):
    PC(chamber, r, c, 120, 25, 15, 120) {}

// whoNotified notifies that it can be attacked
void Troll::notify(Subject& whoNotified) {
    whoNotified.attackedBy(*this);
}
