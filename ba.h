#ifndef BA_H
#define BA_H

#include "potion.h"
#include <memory>
class Subject;

class BA final: public Potion {
  public:
  static bool wasUsed; //whether the type of this potion has been used before
  BA(int chamber, int r, int c, int amt=5); //constructor, default amt is for cell on Floor
  void notify(std::shared_ptr<Subject>& whoNotified) override;
  // wN called this.notify(wN), this should do sth on wN
  int getAtk() const override; // returns the Atk amount in this

};


#endif
