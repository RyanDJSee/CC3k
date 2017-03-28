#ifndef SUBJECT_H
#define SUBJECT_H

#include "subtype.h"
#include <memory>
using namespace std;
class Info;
class Observer;
class SubType

class Subject {
  vector<shared_ptr<Observer>> observers;
 public:
  void attach(shared_ptr<Observer> o); //add o as observer of this
  void notifyObservers(SubType t);
  virtual ~Subject() = 0;
};

#endif
