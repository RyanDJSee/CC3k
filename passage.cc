#include "passage.h"
#include "cell.cc"
#include <string>
using namespace std;



Passage::Passage(int chamber, int r, int c): Cell(),
                chamber{chamber}, row{r}, col{c} {} //constructor


string Passage::getRep() const { //returns the text representation of this
  return "#";
}
