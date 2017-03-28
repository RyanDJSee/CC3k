#ifndef DOOR_H
#define DOOR_H

#include "cell.h"

class Door: public Cell {
  
public:
  Door(int chamber, int r, int c); //constructor
  char getRep() const override; //returns the text representation of this

};

#endif
