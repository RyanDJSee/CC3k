#include <string>
#include <memory>
#include "RESTART.h"
#include "game.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "NEXTFLOOR.h"
#include "END.h"
#include "floor.h"
using namespace std;

Game::Game(): currFloor(nullptr), currFloornum(1), pc(nullptr) {}


void Game::GameInit(string character, string filename) {//needs new character, start from floor 1
  if (character=="s") {
    pc = make_shared<Shade>(-1, -1, -1);
  } else if (character=="d") {
    pc = make_shared<Drow>(-1, -1, -1);
  } else if (character=="v") {
    pc = make_shared<Vampire>(-1, -1, -1);
  } else if (character=="g") {
    pc = make_shared<Goblin>(-1, -1, -1);
  } else if (character=="t") {
    pc = make_shared<Troll>(-1, -1, -1);
  }
  file=filename;
  currFloor = make_shared<Floor>(currFloornum,pc,filename);
  if (filename==""){
    currFloor->FloorInit();
  }
}


void Game::UsePotion(string dir){
  currFloor->UsePotion(dir);
  currFloor->clearaction();
}


void Game::Attack(string dir){
  currFloor->attack(dir);
  currFloor->clearaction();
}


void Game::EnemySwitch(){
  currFloor->EnermySwitch();
}


void Game::Restart(){
  throw RESTART();
}


void Game::MoveChar(string dir){
  try {
    currFloor->FloorMove(dir);
  } catch (NEXTFLOOR &next){
    ++currFloornum;
    if (currFloornum>=6) {
      throw END();
    } else{
      currFloor = make_shared<Floor>(currFloornum,pc,filename);
    }
  }
  currFloor->clearaction();
}
