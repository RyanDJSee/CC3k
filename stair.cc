#include "stair.h"
#include "cell.cc"
#include <string>
#include "nextfloor.h"



Stair::Stair(int chamber, int r, int c): Cell(chamber, r, c) {}
  //constructor


string Stair::getRep() const { //returns the text representation of this
  return "\";
}


StepType Stair::Steppable() const{
  throw NEXTFLOOR;
}
