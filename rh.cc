#include "potion.h"
#include "rh.h"
#include <memory>
using namespace std;



RH::RH(int chamber, int r, int c, int amt):
      Potion(chamber, r, c, amt) {} //constructor, default amt is for cell on Floor


void RH::notify(shared_ptr<Subject>& whoNotified) {
  // wN called this.notify(wN), this should do sth on wN
  //called when PC pass by
  if (wasUsed) {
    //send msg to floor
    observers[0]->addaction("sees an RH");
  }
}


int RH::getHP() const { // returns the HP amount in this
  return amount;
}
