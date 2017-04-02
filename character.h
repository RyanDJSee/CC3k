#ifndef _CHARACTER_H_
#define _CHARACTER_H_
#include <iostream>
#include <vector>
#include <string>
#include "item.h"
#include "cell.h"
#include "info.h"
#include "subtype.h"

class Character: public Cell, public std::enable_shared_from_this<Character>{
    protected:
    std::vector<std::shared_ptr<Item>> properties;
    int atk;
    int def;
    int maxHP;

    public:
    Character(int chamber, int row, int col, int hp, int atk, int def, int maxHP);
    void clearPotion(); //clear temporary potions when move to next floor
    Info getInfo() const; //get info of a character
    bool isDead() const;
    void use(std::shared_ptr<Item>) override; // use potion on character
    bool isSuccessAttacked() const; // U{0,1} RNG; if 1, then true; if 0, then false
    StepType Steppable() const;

    virtual ~Character();
};

#endif
