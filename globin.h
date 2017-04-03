#ifndef _GLOBIN_H_
#define _GLOBIN_H_
#include "pc.h"

class Subject;

class Globin: public PC {

    public:
    Globin(int r, int c);
    void notify(Subject& whoNotified) override;
    void attackedBy(Orc& orc) override;

    ~Globin();
};

#endif
