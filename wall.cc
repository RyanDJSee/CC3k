#include "wall.h"
#include "cell.cc"
#include <string>
using namespace std;


Wall(int chamber, int r, int c): Cell(),
                chamber{chamber}, row{r}, col{c}, rep{rep} {} //constructor


string Wall::getRep() const { //returns the text representation of this
  return rep;
}
