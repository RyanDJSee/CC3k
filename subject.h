#ifndef SUBJECT_H
#define SUBJECT_H

#include "subtype.h"
#include <memory>
#include <vector>
using namespace std;
class Info;
class Observer;
class Human;
class Dwarf;
class Halfling;
class Elf;
class Orc;
class Merchant;

class Subject {
protected:
  vector<shared_ptr<Observer>> observers;
 public:
  void attach(shared_ptr<Observer> o); //add o as observer of this
  void dettachall();//detatch all observers
  void notifyObservers(SubType t);
  //default do nothing: only implemented in PC
  virtual void AttackedBy(Human &hu);
  virtual void AttackedBy(Dwarf &dw);
  virtual void AttackedBy(Halfling &half);
  virtual void AttackedBy(Elf &elf);
  virtual void AttackedBy(Orc &orc);
  virtual void AttackedBy(Merchant &mer);

  virtual ~Subject() = 0;
};

#endif
