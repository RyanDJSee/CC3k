#ifndef _SHADE_H_
#define _SHADE_H_
#include "pc.h"

class Subject;

class Shade: public PC {
    
    public:
    Shade(int r, int c);
    void notify(Subject& whoNotified) override;

    ~Shade();
};

#endif
