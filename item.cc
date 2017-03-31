#include "cell.h"
#include "item.h"
#include "steptype.h"


int Item::getHP() const { // return the HP amount in this
    return 0; //defult
  }


int Item::getAtk() const { // return the Atk amount in this
  return 0; //defult
}


int Item::getDef() const { // return the Def amount in this
  return 0; //defult
}


int Item::getGold() const{ // return the HP amount in this
  return 0; //defult
}


StepType Item::Steppable() const {
  //returns the StepType of this: CantStep/PickUp/WalkOver
  return CantStep; //default, for potions
}
