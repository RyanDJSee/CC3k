#include "empty.h"
#include "cell.h"
#include <string>
#include "steptype.h"
using namespace std;


Empty::Empty(int chamber, int r, int c): Cell(chamber, r, c) {}
  //constructor


bool Empty::isEmpty() const {
  return true;
}


string Empty::getRep() const { //returns the text representation of this
  return ".";
}


StepType Empty::Steppable() const{
  return StepType::PickUp;
}
