#ifndef _ORC_H_
#define _ORC_H_
#include "enemy.h"
#include <string>

class Subject;

class Orc final: public Enemy {

    public:
    Orc(int chamber,int r, int c);
    std::string getRep() const;
    void notify(Subject& whoNotified) override;

    ~Orc();
};

#endif
