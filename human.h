#ifndef _HUMAN_H_
#define _HUMAN_H_
#include "enemy.h"
#include <string>

class Subject;

class Human final: public Enemy {

    public:
    Human(int chamber, int r, int c);
    std::string getRep() const;
    void notify(Subject& whoNotified) override;
    std::string getName() const override;

    ~Human();

};

#endif
