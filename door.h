#ifndef DOOR_H
#define DOOR_H

#include "cell.h"
#include <string>
using namespace std;

class Door final: public Cell {

public:
  Door(int chamber, int r, int c); //constructor
  string getRep() const override; //returns the text representation of this

};

#endif
