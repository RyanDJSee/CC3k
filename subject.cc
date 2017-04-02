#include "subject.h"
#include "observer.h"
#include "subtype.h"
#include <memory>
#include <vector>
using namespace std;


void Subject::attach(shared_ptr<Observer> o) {
  //add to observers
  observers.emplace_back(o);
}


void Subject::dettachall(){
  int len=observers.size();
  for (int i=0;i<len;++i){
    observers.pop_back();
  }
}


void Subject::notifyObservers(SubType t) {
  //go through all observers and notify ones with type t
  for (auto ob : observers) {
    if (ob->subtype()==t) {
      auto thisptr=shared_from_this();
      ob->notify(thisptr);
    }
  }
}


void Subject::attackedBy(Human &hu){}
void Subject::attackedBy(Dwarf &dw){}
void Subject::attackedBy(Halfling &half){}
void Subject::attackedBy(Elf &elf){}
void Subject::attackedBy(Orc &orc){}
void Subject::attackedBy(Merchant &mer){}
void Subject::attackedBy(Dragon &dra){}
void Subject::attackedBy(Shade& shade){}
void Subject::attackedBy(Goblin& goblin) {}
void Subject::attackedBy(Vampire& vampire) {}
void Subject::attackedBy(Troll& troll){}
void Subject::attackedBy(Drow& drow){}


vector<int> Subject::getPos() const{
  //will be implemented in Cell
  vector<int> v;
  v.emplace_back(-1);
  v.emplace_back(-1);
  return v;
}


Subject:: ~Subject() {}
