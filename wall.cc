#include "wall.h"
#include "cell.cc"
#include <string>
using namespace std;


Wall(int chamber, int r, int c, stringrep):
        Cell(chamber, r, c), rep{rep} {} //constructor


string Wall::getRep() const { //returns the text representation of this
  return rep;
}


StepType Wall::Steppable() const{
  return CantStep;
}
