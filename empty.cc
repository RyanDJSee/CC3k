#include "empty.h"
#include "cell.cc"
#include <string>
using namespace std;


Empty::Empty(int chamber, int r, int c): Cell(),
              chamber{chamber}, row{r}, col{c} {} //constructor


bool Empty::isEmpty() const {
  return true;
}


string Empty::getRep() const { //returns the text representation of this
  return ".";
}
