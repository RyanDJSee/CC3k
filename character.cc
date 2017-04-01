#include "character.h"
#include <math.h>

using namespace std;


Character::Character(int chamber, int row, int col, int hp, int atk, int def, int maxHP):
    Cell{chamber, row, col}, atk{atk}, def{def} {
    shared_ptr<RH> hp_ptr = make_shared{new RH{-1, -1, -1, hp}};
    properties.emplace_back(hp_ptr);
}

bool Character::isSuccessAttacked() {
    if (rand() % 2 == 1) return true;
    return false;
}

bool Character::isDead() {
    if (getInfo().hp <= 0) return true;
    return false;
}

void Character::clearPotion() {
    int i = properties.size() - 1;
    while (i >= 0) {
	if (!dynamic_pointer_cast<HP>(properties.at(i))) {
    	    properties.pop_back(i);
	    --i;
	} else {
	    --i;
	}
    }
}

Info Character::getInfo() {
    Info info;
    info.hp = 0;
    info.atk = atk;
    info.def = def;
    info.gold = 0;

    for (auto item : properties) {
	info.hp += item->getHP();
	info.atk += item->getAtk();
	info.def += item->getDef();
	info.gold += item->getDef();
    }
    return info;
}


void Character::use(shared_ptr<Item> item) {
    if (dynamic_pointer_cast<Drow>(shared_from_this())) { // for Drow, all potions have their effect magnified by 1.5
	int amt = item->getHP() + item->getAtk() + item->getDef() + item->getGold();
	shared_ptr<Item> item_ptr = make_shared{new Item{-1, -1, -1, 1.5*amt}};
    }
    int newHP = item->getHP();
    int newAtk = item->getAtk();
    int newDef = item->getDef();

    if (dynamic_pointer_cast<PC>(shared_from_this())) { //if the character is PC
	if (!dynamic_pointer_cast<Vampire>) { // if the character is not vampire
	    if (getInfo().hp + newHP > maxHP) { // if the item is HP, check if exceed maxHP
		newHP = maxHP - getInfo().hp;
		shared_ptr<Item> hp_ptr = make_shared{new RH{-1, -1, -1, newHP}};
		properties.emplace_back(hp_ptr);
	    }
	} else if (getInfo().atk + newAtk < 0) { // if the item is Atk, check if < 0
	    newAtk = -getInfo().atk;
	    shared_ptr<Item> atk_ptr = make_shared{new BA{-1, -1, -1, newAtk}};
	    properties.emplace_back(atk_ptr);
	} else if (getInfo().def + newDef < 0) { // if the item is Atk, check if < 0
	    newDef = -getInfo().def;
	    shared_ptr<Item> def_ptr = make_shared{new BD{-1, -1, -1, newDef}};
	    properties.emplace_back(def_ptr);
	} else { // otherwise, add the item to properties with no change
	    properties.emplace_back(item);
	}
	if (isDead()) { throw END; } // if PC is dead, throw an exception
    }

    else { // if the character is Enemy
	properties.emplace_back(item);
	if (isDead()) { // if the enemy is dead
	    if (dynamic_pointer_cast<Dragon>(shared_from_this())) {
		observers[1]->detachall();
	    }
	    notifyObs(SubType::FLOOR); // notify floor to remove the enemy from floor
	}
    }
}


StepType Character::Steppable() const {
  //returns the StepType of this: CantStep/PickUp/WalkOver
  return StepType::CantStep; //default, for charaters
}


Character::~Character() {}
