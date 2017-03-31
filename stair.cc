#include "stair.h"
#include "cell.cc"
#include <string>



Stair::Stair(int chamber, int r, int c): Cell(),
                chamber{chamber}, row{r}, col{c} {} //constructor


string Stair::getRep() const { //returns the text representation of this
  return "\";
}
