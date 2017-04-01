#ifndef PH_H
#define PH_H

#include "potion.h"
class Subject;

class PH final: public Potion {
  static bool wasUsed; //whether the type of this potion has been used before

public:
  PH(int chamber, int r, int c, int amt=(-10)); //constructor, default amt is for cell on Floor
  void notify(Subject &whoNotified) override;
  // wN called this.notify(wN), this should do sth on wN
  int getHP() const override; // returns the HP amount in this

};


#endif
