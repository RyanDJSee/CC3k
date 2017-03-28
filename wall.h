#ifndef WALL_H
#define WALL_H

#include "cell.h"
#include <string>
using namespace std;

class Wall: public Cell {
  string rep;

public:
  Wall(int chamber, int r, int c, string rep); //constructor
  char getRep() const override; //returns the text representation of this

};

#endif
