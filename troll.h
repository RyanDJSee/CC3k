#ifndef _TROLL_H_
#define _TROLL_H_
#include "pc.h"

class Subject;

class Troll: public PC {

    public:
    Troll(int r, int c);
    void notify(Subject& whoNotified) override;

    ~Troll();
};

#endif
