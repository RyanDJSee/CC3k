#ifndef _DROW_H_
#define _DROW_H_
#include "pc.h"

class Subject;

class Drow: public PC {

    public:
    Drow(int r, int c);
    void notify(Subject& whoNotified) override;

    ~Drow();
};

#endif
