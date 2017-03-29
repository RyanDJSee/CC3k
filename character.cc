#include "character.h"

#if 0
class Character: public Cell {
        std::vector<items*> properties;
	    int hp;
	        int atk;
		    int def;

		        public:
		        Character(int chamber, int r, int c, int hp, int atk, int def);
			    void move(string dir);

};
#endif

Character::Character(int chamber, int r, int c): 
    Cell(chamber, r, c) {}

void Character::move(string dir) {
    if (dir == "no") {
	--r;
    } else if (dir == "so") {
	++r;
    } else if (dir == "ea") {
	++c;
    } else if (dir == "we") {
	--c;
    } else if (dir == "ne") {
	--r;
	++c;
    } else if (dir == "nw") {
	--r;
	--c;
    } else if (dir == "se") {
	++r;
	++c;
    } else if (dir == "sw") {
	++r;
	--c;
    }
}

bool Character::isDead() {
    if (hp == 0) return true;
    return false;
}

Character::~Character() {}
