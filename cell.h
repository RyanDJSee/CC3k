#ifndef CELL_H
#define CELL_H

#include "steptype.h"
#include "subtype.h"
#include "subject.h"
#include "observer.h"
#include <string>
#include <vector>
using namespace std;

class Item;

class Cell : public Subject, public Observer {
  int chamber; //which chamber is this in
  int row;
  int col;
  int moved=false;

 public:
  Cell(int chamber, int row, int col);//constructor
  virtual ~Cell() =default;

  virtual void setPos(int r, int c, int chamber=-1); //update location for this
  virtual vector<int> getPos() const;//return position as a vector [row,col]

  void notify(Subject &whoNotified) override; //default behaviour
  // wN called this.notify(wN), this should do sth on wN

  virtual bool isEmpty() const; //whether this is empty
  virtual StepType Steppable() const=0;
  //returns the StepType of this: CantStep/PickUp/WalkOver
  SubType subtype() const; //returns the SubType of this: CELL/FLOOR
  bool Moved() const;//returns true if has been Moved
  void setMove(bool status);

  virtual Info getInfo();//add const
  virtual string getRep() const=0; //returns the text representation of this
  virtual void use(shared_ptr<Item>);//default: nothing

};

#endif