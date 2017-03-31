#include "potion.h"
#include "ba.h"


BA::BA(int chamber, int r, int c, int amt=5):
      Potion(chamber, r, c, amt) {} //constructor, default amt is for cell on Floor


void BA::notify(Subject &whoNotified) override {
  // wN called this.notify(wN), this should do sth on wN
  //called when PC pass by
  if (wasUsed) {
    //send msg to floor
    observers[0]->addaction("sees an BA")
  }
}


int BA::getAtk() const override{ // returns the HP amount in this
  return amt;
}
