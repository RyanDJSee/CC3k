#include "shade.h"
#include "pc.h"
#include <memory>
#include <string>
using namespace std;


Shade::Shade(int chamber, int r, int c):
    PC(chamber, r, c, 125, 25, 25, 125) {}

// whoNotified notifies that it can be attacked
void Shade::notify(shared_ptr<Subject> &whoNotified) {
  whoNotified->attackedBy(*this);
}

string Shade::getName() const { return "Shade"; }

