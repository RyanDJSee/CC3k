#include "troll.h"
#include <string>
#include <memory>
using namespace std;


Troll::Troll(int chamber, int r, int c):
    PC(chamber, r, c, 120, 25, 15, 120) {}

// whoNotified notifies that it can be attacked
void Troll::notify(shared_ptr<Subject>& whoNotified) {
    whoNotified->attackedBy(*this);
}

string Troll::getName() const { return "Troll"; }
