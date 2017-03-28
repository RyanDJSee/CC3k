#ifndef ITEM_H
#define ITEM_H

#include "cell.h"
class StepType;

class Item: public Cell {
  int amount const;
public:
  Item(int iniamt); //constructor
  int getHP() const; // return the HP amount in this
  int getAtk() const; // return the Atk amount in this
  int getDef() const; // return the Def amount in this
  int getGold() const; // return the HP amount in this
  StepType Steppable() const;
  //returns the StepType of this: CantStep/PickUp/WalkOver

};


#endif
