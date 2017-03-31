#include "door.h"
#include "cell.cc"
#include <string>
#include "steptype.h"
using namespace std;


Door(int chamber, int r, int c): Cell(chamber, r, c) {} //constructor


string Door::getRep() const { //returns the text representation of this
  return "+";
}


StepType Door::Steppable() const {
  return WalkOver;
}
