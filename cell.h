#ifndef CELL_H
#define CELL_H

#include "steptype.h"
#include "subtype.h"
#include "subject.h"
#include "observer.h"
#include <string>
using namespace std;

class Cell : public Subject, public Observer {
  int chamber; //which chamber is this in
  int row;
  int col;

 public:
  virtual void setPos(int chamber=-1, int r, int c); //update location for this
  void notify(Subject &whoNotified) override; //default behaviour
  // wN called this.notify(wN), this should do sth on wN
  virtual bool isEmpty() const; //whether this is empty
  virtual string getRep() const=0; //returns the text representation of this
  virtual StepType Steppable() const; //returns the StepType of this: CantStep/PickUp/WalkOver
  virtual SubType subtype() const; //returns the SubType of this: DP/CL
  virtual ~Cell() =default;
};

#endif
