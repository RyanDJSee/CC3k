#ifndef WALL_H
#define WALL_H

#include "cell.h"

class Wall: public Cell {
public:
  char getRep() const override; //returns the text representation of this

};

#endif
