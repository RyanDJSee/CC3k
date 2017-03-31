#include "door.h"
#include "cell.cc"
#include <string>
using namespace std;


Door(int chamber, int r, int c): Cell(),
                chamber{chamber}, row{r}, col{c} {} //constructor


string Door::getRep() const { //returns the text representation of this
  return "+";
}
