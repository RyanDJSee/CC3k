#ifndef CELL_H
#define CELL_H

#include "steptype.h"
#include "subtype.h"
#include "subject.h"
#include "observer.h"

class Cell : public Subject, public Observer {
  int chamber; //which chamber is this in

 public:
  void setPos(int r, int c); //update location for this
  void notify(Subject &whoNotified) override; //default behaviour
  // wN called this.notify(wN), this should do sth on wN
  bool isEmpty() const; //whether this is empty
  virtual char getRep() const; //returns the text representation of this
  StepType Steppable() const; //returns the StepType of this: CantStep/PickUp/WalkOver
  SubType subtype() const; //returns the SubType of this: DP/CL

};

#endif
