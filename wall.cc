#include "wall.h"
#include "cell.h"
#include <string>
using namespace std;


Wall::Wall(int chamber, int r, int c, string rep):
        Cell(chamber, r, c), rep{rep} {} //constructor


string Wall::getRep() const { //returns the text representation of this
  return rep;
}


StepType Wall::Steppable() const{
  return StepType::CantStep;
}
