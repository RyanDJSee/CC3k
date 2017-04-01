#include "steptype.h"
#include "subtype.h"
#include "subject.h"
#include "observer.h"
#include <string>
#include <vector>
#include "subtype.h"
#include "steptype.h"
using namespace std;


Cell::Cell(int chamber, int row, int col):
      chamber{chamber}, row{row}, col{col} {}


void Cell::setPos(int r, int c, int cham=-1){ //update location for this
  if (cham!=-1) {
    chamber=cham;
  }
  row=r;
  col=c;
}


virtual vector<int> getPos(){
  //return position as a vector [row,col]
  vector<int> v;
  v.emplace_back(row);
  v.emplace_back(col);
  return v;
}


void Cell::notify(Subject &whoNotified) override {}
  // wN called this.notify(wN), this should do sth on wN
  // default behaviour:do nothing


bool Cell::isEmpty() const { //whether this is empty
  //default is nonEmpty
  return false;
}


SubType Cell::subtype() const{
  //returns the SubType of this: DP/CL
  return SubType::CELL;
}


bool Cell::Moved() const{//returns true if has been Moved
  return moved;
}


void Cell::setMove(bool status) {//change moved to status
    moved=status;
  }


virtual void Cell::use(shared_ptr<item>){}//default: nothing