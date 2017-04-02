#ifndef RH_H
#define RH_H

#include "potion.h"
#include <memory>
class Subject;

class RH final: public Potion {
  static bool wasUsed; //whether the type of this potion has been used before

public:
  RH(int chamber, int r, int c, int amt=10); //constructor, default amt is for cell on Floor
  void notify(std::shared_ptr<Subject>& whoNotified) override;
  // wN called this.notify(wN), this should do sth on wN
  int getHP() const override; // returns the HP amount in this

};


#endif
