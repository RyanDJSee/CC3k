#ifndef _TROLL_H_
#define _TROLL_H_
#include "pc.h"
#include <string>

class Subject;

class Troll final: public PC {

    public:
    Troll(int chamber, int r, int c);
    void notify(Subject& whoNotified) override;
    std::string getName() const override;

    ~Troll();
};

#endif
