#ifndef _CHARACTER_H_
#define _CHARACTER_H_
#include <iostream>
#include <vector>
#include <string>

class Character: public Cell {

    protected:
    std::vector<items*> properties;
    int hp;
    int atk;
    int def;

    public:
    Character();
    void move(string dir);
    bool isDead();

    virtual ~Character();
};

#endif
