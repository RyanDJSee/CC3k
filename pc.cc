#ifndef _PC_H_
#define _PC_H_
#include "character.h"

class PC: public Character {
        int maxPH;
	    bool wasDragonHoard;

	        public:
	        void attackedBy(Human& hu) = 0;
		    void attackedBy(Dwarf& hu) = 0;
		        void attackedBy(Elf& hu) = 0;
			    void attackedBy(Orcs& hu) = 0;
			        void attackedBy(Merchant& hu) = 0;
				    void attackedBy(Dragon& hu) = 0;
				        void attackedBy(Halfling& hu) = 0;

					    void usedOn(Human& hu) = 0;
					        void usedOn(Dwarf& hu) = 0;
						    void usedOn(Elf& hu) = 0;
						        void usedOn(Orcs& hu) = 0;
							    void usedOn(Merchant& hu) = 0;
							        void usedOn(Dragon& hu) = 0;
								    void usedOn(Halfling& hu) = 0;

};

#endif

PC::PC(in):
    Character(int chamber, int r, int c, int hp, int atk, int def), maxHP{maxHP} {}
//was dragon hoard?

char PC::getRep() {
    return '@';
}

void PC::addHP(int hp, int maxHP) {
    if (this->hp + hp >= maxHP) {
	this->hp maxHP;
    } else {
	this->hp += hp;
    }
}



