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
class Shade;
class Goblin;
class Vampire;
class Troll;
class Drow;
class Dragon;


class Subject {
protected:
  vector<shared_ptr<Observer>> observers;
public:
  void attach(shared_ptr<Observer> o); //add o as observer of this
  void dettachall();//detatch all observers
  void notifyObservers(SubType t);
  //default do nothing: only implemented in PC
  virtual void attackedBy(Human &hu);
  virtual void attackedBy(Dwarf &dw);
  virtual void attackedBy(Halfling &half);
  virtual void attackedBy(Elf &elf);
  virtual void attackedBy(Orc &orc);
  virtual void attackedBy(Merchant &mer);
  virtual void attackedBy(Dragon &dra);
  virtual void attackedBy(Shade& shade);
  virtual void attackedBy(Goblin& goblin);
  virtual void attackedBy(Vampire& vampire);
  virtual void attackedBy(Troll& troll);
  virtual void attackedBy(Drow& drow);

  virtual ~Subject() = 0;
};

#endif
