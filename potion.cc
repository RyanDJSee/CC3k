#include "cell.h"
#include "potion.h"
#include <string>
using namespace std;


Potion::Potion(int chamber, int row, int col, int amt) :
            Item(chamber, row, col, amt){}


string Potion::getRep() const {
  return "P";
}
