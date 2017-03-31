#include "subject.h"
#include "observer.h"
#include "subtype.h"


void Subject::attach(shared_ptr<Observer> o) {
  //add to observers
  observers.emplace_back(o);
}


void Subject::notifyObservers(SubType t) {
  //go through all observers and notify ones with type t
  for (auto ob : observers) {
    if (ob->subType()==t) {
      ob->notify(*this);
    }
  }
}


virtual void Subject::AttackedBy(Human &hu){}
virtual void Subject::AttackedBy(Dwarf &dw){}
virtual void Subject::AttackedBy(Halfling &half){}
virtual void Subject::AttackedBy(Elf &elf){}
virtual void Subject::AttackedBy(Orc &orc){}
virtual void Subject::AttackedBy(Merchant &mer){}


Subject:: ~Subject() {}
