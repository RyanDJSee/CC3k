#ifndef _SHADE_H_
#define _SHADE_H_
#include "pc.h"
#include <string>

class Subject;

class Shade final: public PC {

public:
  Shade(int chamber, int r, int c);
  void notify(Subject& whoNotified) override;
  std::string getName() override;

  ~Shade();
};

#endif
