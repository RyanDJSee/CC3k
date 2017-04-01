#ifndef WA_H
#define WA_H

#include "potion.h"
class Subject;

class WA final: public Potion {
  static bool wasUsed; //whether the type of this potion has been used before

public:
  WA(int chamber, int r, int c, int amt=-5); //constructor, default amt is for cell on Floor
  void notify(Subject &whoNotified) override;
  // wN called this.notify(wN), this should do sth on wN
  int getAtk() const override; // returns the Atk amount in this

};


#endif
