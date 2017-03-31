#ifndef POTION_H
#define POTION_H

#include "item.h"
#include <string>
using namespace std;

class Potion: public Item {
public:
  Potion(int chamber, int row, int col, int amt);
  string getRep() const override; //returns the text representation of this
  virtual ~Potion()=default;
};

#endif
