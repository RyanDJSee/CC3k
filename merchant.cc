#include "merchant.h"
#include <string>
#include <math.h>
#include "shade.h"
#include "globin.h"
#include "vampire.h"
#include "drow.h"
#include "troll.h"
#include "rh.h"

using namespace std;

Merchant::Merchant(int chamber, int r, int c):
    Enemy{chamber, r, c, 140, 20, 20} {
    isHostile = false;
}

string Merchant::getRep() { return "M"; }

void Merchant::notify(Subject& whoNotified) {
    whoNotified.attackedBy(*this);
}

void Merchant::attackedBy(Shade& shade) {
    if (isHostile == false) { 
	isHostile = true;
    } else {
    	int damage = ceil((100/(100 + getInfo().def))*shade.getInfo().atk);
    	shared_ptr<Item> hp_ptr{new RH{-1, -1, -1, -damage}};
    	use(hp_ptr);
    }
}

void Merchant::attackedBy(Globin& globin) {        
    if (isHostile == false) { 
	isHostile = true;
    } else {    
	int damage = ceil((100/(100 + getInfo().def))*globin.getInfo().atk);    
	shared_ptr<Item> hp_ptr{new RH{-1, -1, -1, -damage}};    
	use(hp_ptr);
    }
}

void Merchant::attackedBy(Vampire& vampire) {               
    if (isHostile == false) {               
	isHostile = true;                       
    } else {                                        
	int damage = ceil((100/(100 + getInfo().def))*vampire.getInfo().atk);                                        
	shared_ptr<Item> hp_ptr{new RH{-1, -1, -1, -damage}};
	use(hp_ptr);                                                    
    }
}

void Merchant::attackedBy(Drow& drow) {                    
    if (isHostile == false) {                               
	isHostile = true;                                               
    } else {                                                                        
	int damage = ceil((100/(100 + getInfo().def))*drow.getInfo().atk);
	shared_ptr<Item> hp_ptr{new RH{-1, -1, -1, -damage}};
	use(hp_ptr);                                                                                                
    }   
}

void Merchant::attackedBy(Troll& troll) {                    
    if (isHostile == false) {                               
	isHostile = true;                                               
    } else {                                                                        
	int damage = ceil((100/(100 + getInfo().def))*troll.getInfo().atk);
	shared_ptr<Item> hp_ptr{new RH{-1, -1, -1, -damage}};
	use(hp_ptr);                                                                                                
    }   
}