#ifndef _DRAGON_H_
#define _DRAGON_H_
#include "enemy.h"
#include <string>

class Subject;

class Dragon final: public Enemy {

    public:
    Dragon(int chamber, int r, int c);
    void notify(Subject& whoNotified) override;
    std::string getRep() const;
    std::string getName() const override;

    ~Dragon();
};

#endif
