#ifndef OBSERVER_H
#define OBSERVER_H

#include "subtype.h"
#include <string>

class Subject;

class Observer {
 public:
  virtual void notify(Subject &whoNotified) = 0;
  // wN called this.notify(wN), this should do sth on wN
  virtual SubType subtype() const = 0;
  // returns either CELL or FLOOR
  virtual void addaction(std::string act);
  virtual ~Observer() = default;
};

#endif
