#ifndef PASSAGE_H
#define PASSAGE_H

#include "cell.h"

class Passage final: public Cell {

public:
  Passage(int chamber, int r, int c); //constructor
  string getRep() const override; //returns the text representation of this

};

#endif
