#include "drow.h"
#include <string>
using namespace std;


Drow(int r, int c):
    PC(r, c, 150, 25, 15, 150} {}

// whoNotified notifies that it can be attacked
void Drow::notify(Subject& whoNotified) {
    whoNotified.attackedBy(*this);
}
