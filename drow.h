#ifndef _DROW_H_
#define _DROW_H_
#include "pc.h"
#include <string>

class Subject;

class Drow final: public PC {

    public:
    Drow(int chamber, int r, int c);
    void notify(Subject& whoNotified) override;
    std::string getName() override;

    ~Drow();
};

#endif
