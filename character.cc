#include "character.h"
#include <math.h>
#include "rh.h"
#include "ba.h"
#include "bd.h"
#include "treasure.h"
#include <memory>
#include "drow.h"
#include "dragon.h"
#include "vampire.h"
#include "subject.h"
#include "END.h"
#include "cell.h"

using namespace std;


Character::Character(int chamber, int row, int col, int hp, int atk, int def, int maxHP):
Cell(chamber, row, col), atk{atk}, def{def}, maxHP{maxHP} {

  shared_ptr<RH> hp_ptr{new RH(-1, -1, -1, hp)};
  properties.emplace_back(hp_ptr);
  #ifdef D
  cout<<"character is"<<getName()<<endl;
  cout<<"maxhp is"<<maxHP<<endl;;
  #endif
}

bool Character::isSuccessAttacked() const{
  if (rand() % 2 == 1) return true;
  return false;
}

bool Character::isDead() const{
  #ifdef D
  cout<<"inside character isdead, hp is"<<getInfo().hp<<endl;

  #endif
  if (getInfo().hp <= 0) return true;
  return false;
}

void Character::clearPotion() {
  int i = 1;
  while (true) {
    if (!(dynamic_pointer_cast<RH>(properties.at(properties.size()-i)))) {
      properties.erase(properties.end()-i); // remove non-HP potions
    } else {
      ++i;
    }
    if ((int)properties.size() == i) break;
  }
}


Info Character::getInfo() const{
  Info info;
  info.name = getName();
  info.hp = 0;
  info.atk = atk;
  info.def = def;
  info.gold = 0;

  for (auto item : properties) {
    info.hp += item->getHP();
    info.atk += item->getAtk();
    info.def += item->getDef();
    info.gold += item->getGold();
  }
  return info;
}

/*
void Character::use(shared_ptr<Item> item) {
#ifdef D
cout<<"max, actual"<<maxHP<<getInfo().hp<<endl;
#endif
auto thisptr=shared_from_this();
if (dynamic_pointer_cast<Drow>(thisptr)) { // for Drow, all potions have their effect magnified by 1.5
int amt = (item->getHP() + item->getAtk() + item->getDef() + item->getGold())*1.5;
if (item->getHP() != 0) { shared_ptr<Item> item_ptr{new RH{-1, -1, -1, amt}}; }
if (item->getAtk() != 0) { shared_ptr<Item> item_ptr{new BA{-1, -1, -1, amt}}; }
if (item->getDef() != 0) { shared_ptr<Item> item_ptr{new BD{-1, -1, -1, amt}}; }
if (item->getGold() != 0) { shared_ptr<Item> item_ptr{new Treasure{-1, -1, -1, amt}}; }
}
int newHP = item->getHP();
int newAtk = item->getAtk();
int newDef = item->getDef();


if (dynamic_pointer_cast<PC>(thisptr)) { //if the character is PC
if (newHP != 0) { //if potion is HP
if (!dynamic_pointer_cast<Vampire>(thisptr)) { // if the character is not vampire
if (getInfo().hp + newHP > maxHP) { // if the item is HP, check if exceed maxHP
newHP = maxHP - getInfo().hp;
shared_ptr<Item> hp_ptr{new RH{-1, -1, -1, newHP}};
properties.emplace_back(hp_ptr);
} else { //otherwise, add
properties.emplace_back(item);
}
} else { // if vampire
properties.emplace_back(item);
}
}else {
properties.emplace_back(item);
}
} else if (newAtk!=0){
if (getInfo().atk + newAtk < 0) { // if the item is Atk, check if < 0
newAtk = -getInfo().atk;
#ifdef D
cout<<"new atk is "<<getInfo().hp<<getInfo().atk<<getInfo().def<<endl;
#endif
shared_ptr<Item> atk_ptr{new BA{-1, -1, -1, newAtk}};
properties.emplace_back(atk_ptr);
} else if (getInfo().def + newDef < 0) { // if the item is Def, check if < 0
newDef = -getInfo().def;
shared_ptr<Item> def_ptr{new BD{-1, -1, -1, newDef}};
properties.emplace_back(def_ptr);
} else { // otherwise, add the item to properties with no change
properties.emplace_back(item);
}
if (isDead()) {
#ifdef D
cout<<"inside character throw END"<<endl;
#endif
throw END();
} // if PC is dead, throw an exception
}

else { // if the character is Enemy
properties.emplace_back(item);
if (isDead()) { // if the enemy is dead
if (dynamic_pointer_cast<Dragon>(thisptr)) {
dynamic_pointer_cast<Subject>(observers[1])->dettachall();
}
notifyObservers(SubType::FLOOR); // notify floor to remove the enemy from floor

}
}
}
*/

void Character::use(shared_ptr<Item> item) {
  auto thisptr=shared_from_this();
  if (dynamic_pointer_cast<Drow>(thisptr)) { // for Drow, all potions have their effect magnified by 1.5
    int amt = (item->getHP() + item->getAtk() + item->getDef() + item->getGold())*1.5;
    if (item->getHP() != 0) { shared_ptr<Item> item_ptr{new RH{-1, -1, -1, amt}}; }
    if (item->getAtk() != 0) { shared_ptr<Item> item_ptr{new BA{-1, -1, -1, amt}}; }
    if (item->getDef() != 0) { shared_ptr<Item> item_ptr{new BD{-1, -1, -1, amt}}; }
    if (item->getGold() != 0) { shared_ptr<Item> item_ptr{new Treasure{-1, -1, -1, amt}}; }
  }
  int newHP = item->getHP();
  int newAtk = item->getAtk();
  int newDef = item->getDef();
  int newGold = item->getGold();
  #ifdef D
    cout<<"inside use amt is "<<newHP<<" "<<newAtk<<" "<<newDef<<" "<<newGold<<endl;
  #endif

  if (dynamic_pointer_cast<PC>(thisptr)) { //if the character is PC
#ifdef D
  cout<<"inside use is pc"<<endl;
#endif
    if (newHP != 0) { //if potion is HP
      #ifdef D
        cout<<"inside use is hp"<<endl;
      #endif
      if (!dynamic_pointer_cast<Vampire>(thisptr)) { // if the character is not vampire
        if (getInfo().hp + newHP > maxHP) { // if the item is HP, check if exceed maxHP
          newHP = maxHP - getInfo().hp;
          shared_ptr<Item> hp_ptr{new RH{-1, -1, -1, newHP}};
          properties.emplace_back(hp_ptr);
        } else { //otherwise, add
          properties.emplace_back(item);
        }
      } else { // if vampire
        properties.emplace_back(item);
      }

    } else if (newAtk != 0) { //if item is Atk
      #ifdef D
        cout<<"inside use is atk"<<endl;
      #endif
      if (getInfo().atk + newAtk < 0) { // if the item is Atk, check if < 0
        newAtk = -getInfo().atk;
        shared_ptr<Item> atk_ptr{new BA{-1, -1, -1, newAtk}};
        properties.emplace_back(atk_ptr);
      } else {
        properties.emplace_back(item);
      }
    } else if (newDef != 0) {
      #ifdef D
        cout<<"inside use is def"<<endl;
      #endif
      if (getInfo().def + newDef < 0) { // if the item is Def, check if < 0
        newDef = -getInfo().def;
        shared_ptr<Item> def_ptr{new BD{-1, -1, -1, newDef}};
        properties.emplace_back(def_ptr);
      } else {
        properties.emplace_back(item);
      }
    } else { // if gold, add to back
      #ifdef D
        cout<<"inside use is gold"<<endl;
      #endif
      properties.emplace_back(item);
    }
    if (isDead()) { throw END(); } // if PC is dead, throw an exception
  }

  else { // if the character is Enemy
    properties.emplace_back(item);
    if (isDead()) { // if the enemy is dead
      if (dynamic_pointer_cast<Dragon>(thisptr)) {
        dynamic_pointer_cast<Subject>(observers[1])->dettachall();
      }
      notifyObservers(SubType::FLOOR); // notify floor to remove the enemy from floor

    }
  }
}




StepType Character::Steppable() const {
  // returns the StepType of this: CantStep/PickUp/WalkOver
  return StepType::CantStep; //default, for charaters
}

Character::~Character() {}
