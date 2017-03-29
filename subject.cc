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

Subject:: ~Subject() {}
