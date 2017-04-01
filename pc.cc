#include "character.h"
#include "subType.h"

using namespace std;

PC::PC(int row, int col, int hp, int atk, int def, int maxPH): 
    Character{chamber, row, col, hp, atk, def, maxHP} {}

char PC::getRep() { return '@'; }

void PC::attackedBy(Human& human) { 
    if (!isSuccessAttacked()) return;
    int damage = ceil((100/(100+ getInfo().def))*human.getInfo().atk);
    shared_ptr<Item> hp_ptr = make_shared{new RH{-1, -1, -1, -damage}};
    use(hp_ptr);
}

virtual void PC::attackedBy(Dwarf& dwarf) { 
    if (!isSuccessAttacked()) return;
    int damage = ceil((100/(100+ getInfo().def))*dwarf.getInfo().atk);
    shared_ptr<Item> hp_ptr = make_shared{new RH{-1, -1, -1, -damage}};
    use(hp_ptr);
}

virtual void PC::attackedBy(Elf& elf) {  
    if (!isSuccessAttacked()) return;
    int damage = ceil((100/(100+ getInfo().def))*elf.getInfo().atk);
    shared_ptr<Item> hp_ptr = make_shared{new RH{-1, -1, -1, -damage}};
    use(hp_ptr);
}

virtual void PC::attackedBy(Orcs& orcs) {
    if (!isSuccessAttacked()) return;
    int damage = ceil((100/(100+ getInfo().def))*orcs.getInfo().atk);
    shared_ptr<Item> hp_ptr = make_shared{new RH{-1, -1, -1, -damage}};
    use(hp_ptr);
}

virtual void PC::attackedBy(Merchant& merchant) { 
    if (!isSuccessAttacked()) return;
    int damage = ceil((100/(100+ getInfo().def))*merchant.getInfo().atk);
    shared_ptr<Item> hp_ptr = make_shared{new RH{-1, -1, -1, -damage}};
    use(hp_ptr);
}

virtual void PC::attackedBy(Dragon& dragon) { 
    if (!isSuccessAttacked()) return;
    int damage = ceil((100/(100+ getInfo().def))*dragon.getInfo().atk);
    shared_ptr<Item> hp_ptr = make_shared{new RH{-1, -1, -1, -damage}};
    use(hp_ptr);
}

virtual void PC::attackedBy(Halfling& halfling) {
    if (!isSuccessAttacked()) return;
    int damage = ceil((100/(100+ getInfo().def))*halfing.getInfo().atk);
    shared_ptr<Item> hp_ptr = make_shared{new RH{-1, -1, -1, -damage}};
    use(hp_ptr);
}

PC::~PC() {}


