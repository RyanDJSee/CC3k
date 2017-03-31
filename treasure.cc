#include "item.h"
#include "treasure.h"

Treasure::Treasure(int chamber, int r, int c, int amt):
      Item(), chamber{chamber}, row{r}, col{c}, amt{amt} {}
      //constructor


void Treasure::notify(Subject &whoNotified) override {
  // wN called this.notify(wN), this should do sth on wN
  //called when PC pass by
  if (observers.size()>1) {//guarded dragon hoard
    //notify dragon
    observers[1]->notify(whoNotified);
  }
}


string Treasure::getRep() const {
  return "G";
}


StepType Treasure::Steppable() const {
  //returns the StepType of this: CantStep/PickUp/WalkOver
  if (observers.size()>1) {//guarded
    return WalkOver;
  }
  return PickUp; //default, for potions
}
