#ifndef PASSAGE_H
#define PASSAGE_H

#include "cell.h"
#include "steptype.h"
#include <string>

class Passage final: public Cell {

public:
  Passage(int chamber, int r, int c); //constructor
  std::string getRep() const override; //returns the text representation of this
  StepType Steppable() const override;
};

#endif
