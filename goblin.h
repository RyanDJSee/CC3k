#ifndef _GOBLIN_H_
#define _GOBLIN_H_
#include "pc.h"
#include <string>

class Orc;
class Subject;

class Goblin final: public PC {

    public:
    Goblin(int chamber, int r, int c);
    void notify(std::shared_ptr<Subject>& whoNotified) override;
    void attackedBy(Orc& orc) override;
    std::string getName() const override;

    ~Goblin();
};

#endif
