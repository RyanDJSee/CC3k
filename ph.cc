#include "potion.h"
#include "ph.h"

PH::PH(int chamber, int r, int c, int amt=-10):
      Potion(chamber, r, c, amt) {} //constructor, default amt is for cell on Floor


void PH::notify(Subject &whoNotified) override {
  // wN called this.notify(wN), this should do sth on wN
  //called when PC pass by
  if (wasUsed) {
    //send msg to floor
    observers[0]->addaction("sees an PH")
  }
}


int PH::getHP() const override{ // returns the HP amount in this
  return amt;
}
