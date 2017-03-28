#ifndef DOOR_H
#define DOOR_H

#include "cell.h"

class Door: public Cell {
public:
  char getRep() const override; //returns the text representation of this

};

#endif
