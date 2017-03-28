#ifndef OBSERVER_H
#define OBSERVER_H

#include "subtype.h"
class Subject;
class Cell;

class Observer {
 public:
  virtual void notify(Subject &whoNotified) = 0;
  // wN called this.notify(wN), this should do sth on wN
  virtual SubType subtype() const = 0;
  // returns either DP or CL
  virtual ~Observer() = default;
};

#endif
