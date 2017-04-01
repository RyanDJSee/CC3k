#include "potion.h"
#include "ph.h"

PH::PH(int chamber, int r, int c, int amt):
      Potion(chamber, r, c, amt) {} //constructor, default amt is for cell on Floor


void PH::notify(Subject &whoNotified) {
  // wN called this.notify(wN), this should do sth on wN
  //called when PC pass by
  if (wasUsed) {
    //send msg to floor
    observers[0]->addaction("sees an PH");
  }
}


int PH::getHP() const { // returns the HP amount in this
  return  amount;
}
