#ifndef _DWARF_H_
#define _DWARF_H_
#include "enemy.h"
#include <string>

class Subject;

class Dwarf final: public Enemy {

    public:
    Dwarf(int chamber, int r, int c);
    std::string getRep() const;
    void notify(std::shared_ptr<Subject>& whoNotified) override;
    std::string getName() const override;

    ~Dwarf();
};

#endif
