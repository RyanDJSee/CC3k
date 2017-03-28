#ifndef SUBJECT_H
#define SUBJECT_H

#include "subtype.h"
class Info;
class Observer;
class SubType

class Subject {
  std::vector<Observer*> observers;
 public:
  void attach(Observer *o); //add o as observer of this
  void notifyObservers(SubType t); 
  virtual ~Subject() = 0;
};

#endif
