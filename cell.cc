#include "steptype.h"
#include "subtype.h"
#include "subject.h"
#include "observer.h"
#include <string>
#include <vector>
#include <memory>
#include "subtype.h"
#include "steptype.h"
#include "cell.h"
using namespace std;


Cell::Cell(int chamber, int row, int col):
      chamber{chamber}, row{row}, col{col} {}


void Cell::setPos(int r, int c, int cham){ //update location for this
  if (cham!=-1) {
    chamber=cham;
  }
  row=r;
  col=c;
}


vector<int> Cell::getPos() const{
  //return position as a vector [row,col]
  vector<int> v;
  v.emplace_back(row);
  v.emplace_back(col);
  return v;
}


void Cell::notify(Subject &whoNotified){}
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


void Cell::setMoved(bool status) {//change moved to status
    moved=status;
}


Info Cell::getInfo() const{
  Info info;
  info.name=this->getName();
  return info;
}

Info Cell::getName() const{
  return "";
}


void Cell::use(shared_ptr<Item>){}//default: nothing
