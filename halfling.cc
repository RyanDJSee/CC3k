#include "halfing.h"
using namespace std;

Halfing::Halfing(int chamber, int r, int c):
    Enemy{chamber, r, c, 100, 15, 20} {}

char Halfing::getRep() { return 'L'; }

void Halfing::notify(Subject& whoNotified) {
    whoNotified.attackedBy(*this);
}

void Halfing::attackedBy(Shade& shade) {
    if (!isSuccessAttacked()) return;        
    int damage = ceil((100/(100 + getInfo().def))*shade.getInfo().atk);     
    shared_ptr<Item> hp_ptr = make_shared{new RH{-1, -1, -1, -2*damage}};               
    use(hp_ptr);
}

void Halfing::attackedBy(Globin& globin) {            
    if (!isSuccessAttacked()) return;                   
    int damage = ceil((100/(100 + getInfo().def))*globin.getInfo().atk);                     
    shared_ptr<Item> hp_ptr = make_shared{new RH{-1, -1, -1, -2*damage}};                                       
    use(hp_ptr);        
}  

void Halfing::attackedBy(Drow& drow) {            
    if (!isSuccessAttacked()) return;                   
    int damage = ceil((100/(100 + getInfo().def))*drow.getInfo().atk);                     
    shared_ptr<Item> hp_ptr = make_shared{new RH{-1, -1, -1, -2*damage}};                                       
    use(hp_ptr);        
}  

void Halfing::attackedBy(Vampire& vampire) {            
    if (!isSuccessAttacked()) return;                   
    int damage = ceil((100/(100 + getInfo().def))*vampire.getInfo().atk);                     
    shared_ptr<Item> hp_ptr = make_shared{new RH{-1, -1, -1, -2*damage}};                                       
    use(hp_ptr);        
}

void Halfing::attackedBy(Troll& troll) {            
    if (!isSuccessAttacked()) return;                   
    int damage = ceil((100/(100 + getInfo().def))*troll.getInfo().atk);                     
    shared_ptr<Item> hp_ptr = make_shared{new RH{-1, -1, -1, -2*damage}};                                       
    use(hp_ptr);        
}  
