#ifndef CELL_H
#define CELL_H

#include "steptype.h"
#include "subtype.h"
#include "subject.h"
#include "observer.h"
#include <string>
#include <vector>


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
  std::vector<int> getPos() const override;//return position as a vector [row,col]

  void notify(Subject &whoNotified) override; //default behaviour
  // wN called this.notify(wN), this should do sth on wN

  virtual bool isEmpty() const; //whether this is empty
  virtual StepType Steppable() const=0;
  //returns the StepType of this: CantStep/PickUp/WalkOver
  SubType subtype() const; //returns the SubType of this: CELL/FLOOR
  bool Moved() const;//returns true if has been Moved
  void setMoved(bool status);

  virtual Info getInfo() const;//add const
  virtual std::string getRep() const=0; //returns the text representation of this
  virtual void use(std::shared_ptr<Item>);//default: nothing
  virtual std::string getName() const;
};

#endif
