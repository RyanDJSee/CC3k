#ifndef CELL_H
#define CELL_H

#include "steptype.h"
#include "subtype.h"
#include "subject.h"
#include "observer.h"
#include <string>
#include <vector>
using namespace std;

class Cell : public Subject, public Observer {
  int chamber; //which chamber is this in
  int row;
  int col;
  int moved=false;

 public:
  Cell(int chamber, int row, int col);//constructor
  virtual ~Cell() =default;

  void setPos(int chamber=-1, int r, int c); //update location for this
  vector<int> getPos() const;//return position as a vector [row,col]

  void notify(Subject &whoNotified) override; //default behaviour
  // wN called this.notify(wN), this should do sth on wN

  virtual bool isEmpty() const; //whether this is empty
  virtual StepType Steppable() const=0;
  //returns the StepType of this: CantStep/PickUp/WalkOver
  virtual SubType subtype() const; //returns the SubType of this: DP/CL
  bool Moved() const;//returns true if has been Moved
  void setMove(bool status);

  virtual string getRep() const=0; //returns the text representation of this
  virtual void use(shared_ptr<item>);//default: nothing

};

#endif
