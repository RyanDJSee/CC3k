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
  currFloor = make_shared<Floor(1, pc)>;
  currFloor->FloorInit(filename);
}


  void UsePotion(string dir){
    currFloor->UsePotion(dir);
  }


  void Attack(string dir){
    currFloor->Attack(dir);
  }


  void EnemySwitch(){
    currFloor->EnemySwitch();
  }


  void Restart(){
    throw RESTART;
  }


  void MoveChar(string dir){
    currFloor->Floormove(pc, dir);
  }
