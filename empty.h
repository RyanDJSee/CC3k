#ifndef EMPTY_H
#define EMPTY_H

#include "cell.h"
#include "steptype.h"
#include <string>
using namespace std;


class Empty final: public Cell {

public:
  Empty(int chamber, int r, int c); //constructor
  bool isEmpty() const override;
  string getRep() const override; //returns the text representation of this
  StepType Steppable() const override;

};

#endif
