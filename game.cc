#include <string>
#include <memory>
#include "RESTART.h"
#include "game.h"
#include "Shade.h"
using namespace std;

Game::Game(): currFloor(nullptr), currFloornum(1), pc(nullptr) {}


void Game::GameInit(string character, string filename="") {//needs new character, start from floor 1
  if (character=="s") {
    pc = make_shared<Shade{-1, -1, -1}>;
  } else if (character=="d") {
    pc = make_shared<Drow{-1, -1, -1}>;
  } else if (character=="v") {
    pc = make_shared<Vampire{-1, -1, -1}>;
  } else if (character=="g") {
    pc = make_shared<Goblin{-1, -1, -1}>;
  } else if (character=="t") {
    pc = make_shared<Troll{-1, -1, -1}>;
  }
  currFloor = make_shared{new Floor(filename,currFloornum,pc)};
  if (filename==""){
    currFloor->FloorInit();
  }
}


void Game::UsePotion(string dir){
  currFloor->UsePotion(dir);
  currFloor->clearaction();
}


void Game::Attack(string dir){
  currFloor->Attack(dir);
  currFloor->clearaction();
}


void Game::EnemySwitch(){
  currFloor->EnemySwitch();
}


void Game::Restart(){
  throw RESTART;
}


void Game::MoveChar(string dir){
  try {
    currFloor->Floormove(pc, dir);
  } catch (NEXTFLOOR &next){
    ++currFloornum;
    if (currFloornum>=6) {
      throw END();
    } else{
      currFloor = make_shared{new Floor(filename,currFloornum,pc)};
    }
  }
  currFloor->clearaction();
}
