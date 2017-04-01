#include "troll.h"
#include <string>
using namespace std;


Troll(int r, int c):
    PC(r, c, 120, 25, 15, 120} {}

// whoNotified notifies that it can be attacked
void Troll::notify(Subject& whoNotified) {
    whoNotified.attackedBy(*this);
}
