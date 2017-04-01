#include "subject.h"
#include "observer.h"
#include "subtype.h"


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
    if (ob->subType()==t) {
      ob->notify(*this);
    }
  }
}


virtual void Subject::attackedBy(Human &hu){}
virtual void Subject::attackedBy(Dwarf &dw){}
virtual void Subject::attackedBy(Halfling &half){}
virtual void Subject::attackedBy(Elf &elf){}
virtual void Subject::attackedBy(Orc &orc){}
virtual void Subject::attackedBy(Merchant &mer){}
virtual void Subject::attackedBy(Dragon &dra){}
virtual void Subject::attackedBy(Shade& shade){}
virtual void Subject::attackedBy(Goblin& goblin) {}
virtual void Subject::attackedBy(Vampire& vampire) {}
virtual void Subject::attackedBy(Troll& troll){}
virtual void Subject::attackedBy(Drow& drow){}


Subject:: ~Subject() {}
