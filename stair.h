#ifndef STAIR_H
#define STAIR_H

#include "cell.h"
#include <string>
#include "steptype.h"
using namespace std;

class Stair final: public Cell {

public:
  Stair(int chamber, int r, int c); //constructor
  string getRep() const override; //returns the text representation of this
  StepType Steppable() const override;


};

#endif
