#include "item.h"
#include "treasure.h"
#include <string>
using namespace std;

Treasure::Treasure(int chamber, int r, int c, int amt):
      Item(chamber, r, c, amt) {}
      //constructor


void Treasure::notify(shared_ptr<Subject>& whoNotified) {
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
    return StepType::WalkOver;
  }
  return StepType::PickUp; //default, for potions
}
