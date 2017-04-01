#include "cell.h"
#include "potion.h"
#include <string>
using namespace std;


Potion::Potion(int chamber, int row, int col, int amt) :
            Item(chamber, row, col, amt){}


string Potion::getRep() const {
  return "P";
}

StepType Potion::Steppable() const {
  //returns the StepType of this: CantStep/PickUp/WalkOver
  return StepType::CantStep; //default, for potions
}
