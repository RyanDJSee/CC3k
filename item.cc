#include "cell.h"
#include "item.h"
#include "steptype.h"


Item::Item(int chamber, int row, int col, int amt) :
              Cell(chamber, row, col), amount{amt} {}

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
