

#ifndef _HUMAN_H_
#define _HUMAN_H_
#include "enemy.h"

class Human: public Enemy {



ass Enemy: public Character {
            
        public:
	        Enemy();                
		    char getRep();
		                            
		        void attackedBy(Shade& shade) = 0;
			    void attackedBy(Globin& globin) = 0;
			        void attackedBy(Vampire& vampire) = 0;
				    void attackedBy(Troll& troll) = 0;
				        void attackedBy(Drow& drow) = 0;
					                                                    
					    void usedOn(Shade& shade) = 0;
					        void usedOn(Globin& globin) = 0;
						    void usedOn(Vampire& vampire) = 0;
						        void usedOn(Troll& troll) = 0;
							    void usedOn(Drow& drow) = 0;

							        void addHP(int hp);
								    virtual ~Enemy();
};

#endif


Human::Human(int chamber, int r, int c, int hp, int atk, int def):
    Enemy(chamber, r, c), hp{140}, atk{20}, def{20} {}

char Human::getRep() {
    return 'H';
}

// drop treasure if dead
// how to?


void Human::usedOn(Shade& shade) {
    int damage = ceil((100/(100+shade.def))*atk);
    shade.addHP(damage);
}

void Human::usedOn(Globin& globin) {
    int damage = ceil((100/(100+globin.def))*atk);
    globin.addHP(damage);
}

void Human::usedOn(Vampire& vampire) {
    int damage = ceil((100/(100+vampire.def))*atk);
    vampire.addHP(damage);
}

void Human::usedOn(Troll& troll) {
    int damage = ceil((100/(100+troll.def))*atk);
    troll.addHP(damage);
}

void Human::usedOn(Drow& drow) {
    int damage = ceil((100/(100+drow.def))*atk);
    drow.addHP(damage);
}



void attackedBy(Shade& shade) { shade.useOn(*this); }
void attackedBy(Globin& globin) { globin.useOn(*this); }
void attackedBy(Vampire& vampire) { vampire.useOn(*this); }
void attackedBy(Troll& troll) { troll.useOn(*this); }
void attackedBy(Drow& drow) { drow.useOn(*this); }
