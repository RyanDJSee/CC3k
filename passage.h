#ifndef PASSAGE_H
#define PASSAGE_H

#include "cell.h"

class Passage: public Cell {
  
public:
  Passage(int chamber, int r, int c); //constructor
  char getRep() const override; //returns the text representation of this

};

#endif
