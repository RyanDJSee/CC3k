#include "dwarf.h"
#include <string>
#include <memory>

using namespace std;

Dwarf::Dwarf(int chamber, int r, int c):
    Enemy{chamber, r, c, 140, 20, 20} {}

string Dwarf::getRep() const{ return "W"; }

void Dwarf::notify(shared_ptr<Subject>& whoNotified) {
    whoNotified->attackedBy(*this);
}

string Dwarf::getName() const { return "Dwarf"; }
