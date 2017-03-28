#ifndef STAIR_H
#define STAIR_H

#include "cell.h"

class Stair: public Cell {

public:
  Stair(int chamber, int r, int c); //constructor
  char getRep() const override; //returns the text representation of this

};

#endif
