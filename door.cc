#include "door.h"
#include "cell.h"
#include <string>
#include "steptype.h"
using namespace std;


Door::Door(int chamber, int r, int c): Cell(chamber, r, c) {} //constructor


string Door::getRep() const { //returns the text representation of this
  return "+";
}


StepType Door::Steppable() const {
  return StepType::WalkOver;
}
