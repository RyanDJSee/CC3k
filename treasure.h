#ifndef TREASURE_H
#define TREASURE_H

#include "item.h"
class Subject;
class StepType;

class Treasure: public Item {

public:
  Treasure(int chamber, int r, int c, int amt, bool isGuarded); //constructor
  void notify(Subject &whoNotified) override;
  // wN called this.notify(wN), this should do sth on wN
  char getRep() const override; //returns the text representation of this
  StepType Steppable() const;
  //returns the StepType of this: CantStep/PickUp/WalkOver

};


#endif
