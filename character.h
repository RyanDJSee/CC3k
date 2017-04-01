#ifndef _CHARACTER_H_
#define _CHARACTER_H_
#include <iostream>
#include <vector>
#include <string>
#include "item.h"
#include "cell.h"
#include "info.h"

class Character: public Cell {

    protected:
    std::vector<items*> properties;
    int atk;
    int def;
    int maxHP;

    public:
    Character(int chamber, int row, int col, int hp, int atk, int def, int maxHP);
    void clearPotion(); //clear temporary potions when move to next floor
    Info getInfo(); //get info of a character
    bool isDead();
    void use(shared_ptr<Item>); // use potion on character
    bool isSuccessAttacked(); // U{0,1} RNG; if 1, then true; if 0, then false

    virtual ~Character();
};

#endif
