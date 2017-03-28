#ifndef EMPTY_H
#define EMPTY_H

#include "cell.h"

class Empty: public Cell {
public:
  bool isEmpty() const override;
  char getRep() const override; //returns the text representation of this

};

#endif
