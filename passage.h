#ifndef PASSAGE_H
#define PASSAGE_H

#include "cell.h"

class Passage: public Cell {
public:
  char getRep() const override; //returns the text representation of this

};

#endif
