#include "potion.h"
#include "wd.h"

WD::WD(int chamber, int r, int c, int amt=-5):
      Potion(chamber, r, c, amt) {} //constructor, default amt is for cell on Floor


void WD::notify(Subject &whoNotified) override {
  // wN called this.notify(wN), this should do sth on wN
  //called when PC pass by
  if (wasUsed) {
    //send msg to floor
    observers[0]->addaction("sees an WD")
  }
}


int WD::getDef() const override{ // returns the HP amount in this
  return amt;
}
