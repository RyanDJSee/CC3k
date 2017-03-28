#ifndef POTION_H
#define POTION_H

#include "item.h"

class Potion: public Item {
public:
  char getRep() const; //returns the text representation of this

};

#endif
