#include "potion.h"
#include "wa.h"

WA::WA(int chamber, int r, int c, int amt=-5):
      Potion(), chamber{chamber}, row{r}, col{c}, amt{amt} {} //constructor, default amt is for cell on Floor


void WA::notify(Subject &whoNotified) override {
  // wN called this.notify(wN), this should do sth on wN
  //called when PC pass by
  if (wasUsed) {
    //send msg to floor
    observers[0]->addaction("sees an WA")
  }
}


int WA::getAtk() const override{ // returns the HP amount in this
  return amt;
}
