#ifndef BD_H
#define BD_H

#include "potion.h"
class Subject;

class BD final: public Potion {
  static bool wasUsed; //whether the type of this potion has been used before

public:
  BD(int chamber, int r, int c, int amt=5); //constructor, default amt is for cell on Floor
  void notify(std::shared_ptr<Subject>& whoNotified) override;
  // wN called this.notify(wN), this should do sth on wN
  int getDef() const override; // returns the Def amount in this

};


#endif
