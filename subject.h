#ifndef SUBJECT_H
#define SUBJECT_H

#include "subtype.h"
#include <memory>
#include <vector>

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


class Subject: public std::enable_shared_from_this<Subject> {
protected:
  std::vector<std::shared_ptr<Observer>> observers;
public:
  virtual void attach(std::shared_ptr<Observer> o); //add o as observer of this
  virtual void dettachall();//detatch all observers
  virtual void notifyObservers(SubType t);
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
  virtual SubType subtype() const=0;
  virtual ~Subject() = 0;
  virtual std::vector<int> getPos() const;//return position as a vector [row,col]
};

#endif
