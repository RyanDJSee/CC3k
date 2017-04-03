#include "character.h"
#include "subtype.h"
#include "rh.h"
#include <math.h>
#include <string>
#include "pc.h"
#include "cell.h"
#include "human.h"
#include "dwarf.h"
#include "elf.h"
#include "orc.h"
#include "merchant.h"
#include "dragon.h"
#include "halfling.h"
#include <iostream>


using namespace std;

PC::PC(int chamber, int row, int col, int hp, int atk, int def, int maxHP):
    Character(chamber, row, col, hp, atk, def, maxHP) {
      #ifdef D
        cout<<"character is"<<getName()<<endl;
        cout<<"maxhp is"<<maxHP<<endl;;
#endif
    }

string PC::getRep() const { return "@"; }

void PC::attackedBy(Human& human) {
  #ifdef D
    cout<<"inside pc attackedby human"<<endl;
  #endif
    if (!isSuccessAttacked()) return;
    #ifdef D
      cout<<"pc info is"<<getInfo().def<<human.getInfo().atk<<endl;
    #endif
    int damage = round((100*human.getInfo().atk/(100+ getInfo().def)));//*human.getInfo().atk);
    #ifdef D
      cout<<"damage is"<<damage<<endl;
    #endif
    shared_ptr<Item> hp_ptr{new RH{-1, -1, -1, -damage}};
    use(hp_ptr);
    #ifdef D
      cout<<"pc info is"<<getInfo().hp<<getInfo().def<<getInfo().atk<<endl;
    #endif
}

void PC::attackedBy(Dwarf& dwarf) {
    if (!isSuccessAttacked()) return;
    int damage = ceil((100/(100+ getInfo().def))*dwarf.getInfo().atk);
    shared_ptr<Item> hp_ptr{new RH{-1, -1, -1, -damage}};
    use(hp_ptr);
}

void PC::attackedBy(Elf& elf) {
    if (!isSuccessAttacked()) return;
    int damage = ceil((100/(100+ getInfo().def))*elf.getInfo().atk);
    shared_ptr<Item> hp_ptr{new RH{-1, -1, -1, -damage}};
    use(hp_ptr);
}

void PC::attackedBy(Orc& orc) {
    if (!isSuccessAttacked()) return;
    int damage = ceil((100/(100+ getInfo().def))*orc.getInfo().atk);
    shared_ptr<Item> hp_ptr{new RH{-1, -1, -1, -damage}};
    use(hp_ptr);
}

void PC::attackedBy(Merchant& merchant) {
    if (!isSuccessAttacked()) return;
    int damage = ceil((100/(100+ getInfo().def))*merchant.getInfo().atk);
    shared_ptr<Item> hp_ptr{new RH{-1, -1, -1, -damage}};
    use(hp_ptr);
}

void PC::attackedBy(Dragon& dragon) {
#ifdef D
  cout<<"inside pc attackedBy dragon"<<endl;
#endif
    if (!isSuccessAttacked()) return;
    int damage = ceil((100/(100+ getInfo().def))*dragon.getInfo().atk);
    shared_ptr<Item> hp_ptr{new RH{-1, -1, -1, -damage}};
    #ifdef D
      cout<<"inside pc attackedBy dragon, damage is"<<damage<<endl;
    #endif
    use(hp_ptr);
    #ifdef D
      cout<<"done pc attackedBy dragon"<<endl;
    #endif
}

void PC::attackedBy(Halfling& halfling) {
    if (!isSuccessAttacked()) return;
    int damage = ceil((100/(100+ getInfo().def))*halfling.getInfo().atk);
    shared_ptr<Item> hp_ptr{new RH{-1, -1, -1, -damage}};
    use(hp_ptr);
}

PC::~PC() {}
