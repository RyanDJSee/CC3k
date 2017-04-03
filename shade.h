#ifndef _SHADE_H_
#define _SHADE_H_
#include "pc.h"
#include <string>
#include <memory>

class Subject;

class Shade final: public PC {

public:
  Shade(int chamber, int r, int c);
  void notify(std::shared_ptr<Subject>& whoNotified) override;
  std::string getName() const override;

  ~Shade() = default;
};

#endif
