#ifndef STAIR_H
#define STAIR_H

#include "cell.h"

class Stair: public Cell {
public:
  char getRep() const override; //returns the text representation of this

};

#endif
