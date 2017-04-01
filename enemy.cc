#include "enemy.h"
#include "shade.h"
#include "goblin.h"
#include "vampire.h"
#include "drow.h"
#include "troll.h"
#include <math.h>
#include "rh.h"
#include "treasure.h"

Enemy::Enemy(int chamber, int row, int col, int hp, int atk, int def):
    Character(chamber, row, col, hp, atk, def, -100) {}

void Enemy::attackedBy(Shade& shade) {
    int damage = ceil((100/(100 + getInfo().def))*shade.getInfo().atk);
    shared_ptr<Item> hp_ptr{new RH{-1, -1, -1, -damage}};
    use(hp_ptr);
}


void Enemy::attackedBy(Goblin& goblin) {
    int damage = ceil((100/(100+ getInfo().def))*goblin.getInfo().atk);
    shared_ptr<Item> hp_ptr{new RH{-1, -1, -1, -damage}};
    use(hp_ptr);
    if (isDead()) {
	shared_ptr<Item> gold_ptr{new Treasure{-1, -1, -1, 5}};
	use(gold_ptr);
    }
}

void Enemy::attackedBy(Vampire& vampire) {
    int damage = ceil((100/(100+ getInfo().def))*vampire.getInfo().atk);
    shared_ptr<Item> hp_ptr{new RH{-1, -1, -1, -damage}};
    use(hp_ptr);
    shared_ptr<Item> hp_ptr_vampire {new RH{-1, -1, -1, 5}};
    vampire.use(hp_ptr_vampire); //vampire gains 5 HP every attack
}

void Enemy::attackedBy(Troll& troll) {
    int damage = ceil((100/(100+ getInfo().def))*troll.getInfo().atk);
    shared_ptr<Item> hp_ptr{new RH{-1, -1, -1, -damage}};
    use(hp_ptr);
    shared_ptr<Item> hp_ptr_troll{new RH{-1, -1, -1, 5}};
    troll.use(hp_ptr_troll); //troll gaines 5 HP every turn
}

void Enemy::attackedBy(Drow& drow) {
    int damage = ceil((100/(100+ getInfo().def))*drow.getInfo().atk);
    shared_ptr<Item> hp_ptr{new RH{-1, -1, -1, -damage}};
    use(hp_ptr);
}

Enemy::~Enemy() {}
