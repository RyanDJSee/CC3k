#ifndef TREASURE_H
#define TREASURE_H

#include "item.h"
#include "steptype.h"
#include "subtype.h"
#include <string>


class Treasure: public Item {

public:
  Treasure(int chamber, int r, int c, int amt); //constructor
  void notify(Subject &whoNotified) override;
  // wN called this.notify(wN), this should do sth on wN
  std::string getRep() const override; //returns the text representation of this
  StepType Steppable() const;
  //returns the StepType of this: CantStep/PickUp/WalkOver

};


#endif
