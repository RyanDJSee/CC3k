#ifndef DOOR_H
#define DOOR_H

#include "cell.h"
#include "steptype.h"
#include <string>



class Door final: public Cell {

public:
  Door(int chamber, int r, int c); //constructor
  std::string getRep() const override; //returns the text representation of this
  StepType Steppable() const override;
};

#endif
