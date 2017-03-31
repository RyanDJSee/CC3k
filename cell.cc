#include "steptype.h"
#include "subtype.h"
#include "subject.h"
#include "observer.h"
#include <string>
using namespace std;


void Cell::setPos(int r, int c){ //update location for this
  row=r;
  col=c;
}


void Cell::notify(Subject &whoNotified) override {}
  // wN called this.notify(wN), this should do sth on wN
  // default behaviour:do nothing


bool Cell::isEmpty() const { //whether this is empty
  //default is nonEmpty
  return false;
}


StepType Cell::Steppable() const{ 
  //returns the StepType of this: CantStep/PickUp/WalkOver
  //default:CantStep
  return CantStep;
}


SubType Cell::subtype() const{
  //returns the SubType of this: DP/CL
  return CL;
}
