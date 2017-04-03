#ifndef POTION_H
#define POTION_H

#include "item.h"
#include "steptype.h"
#include <string>



class Potion: public Item {
public:
  Potion(int chamber, int row, int col, int amt);
  std::string getRep() const override; //returns the text representation of this
  virtual ~Potion()=default;
  StepType Steppable() const;
};

#endif
