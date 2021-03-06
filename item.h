#ifndef ITEM_H
#define ITEM_H

#include "cell.h"


class Item: public Cell {
protected:
  const int amount;
public:
  Item(int chamber, int row, int col, int amt);//constructor
  virtual int getHP() const; // return the HP amount in this
  virtual int getAtk() const; // return the Atk amount in this
  virtual int getDef() const; // return the Def amount in this
  virtual int getGold() const; // return the HP amount in this
  //returns the StepType of this: CantStep/PickUp/WalkOver
  virtual ~Item()= default;
};


#endif
