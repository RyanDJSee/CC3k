#ifndef WALL_H
#define WALL_H

#include "cell.h"
#include "steptype.h"
#include <string>



class Wall final: public Cell {
  const std::string rep;

public:
  Wall(int chamber, int r, int c, string rep); //constructor
  std::string getRep() const override; //returns the text representation of this
  StepType Steppable() const;
};

#endif
