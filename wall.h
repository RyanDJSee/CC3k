#ifndef WALL_H
#define WALL_H

#include "cell.h"
#include <string>
using namespace std;

class Wall final: public Cell {
  string rep const;

public:
  Wall(int chamber, int r, int c, string rep); //constructor
  string getRep() const override; //returns the text representation of this

};

#endif
