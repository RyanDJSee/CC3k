#include <string>
#include <memory>
#include "RESTART.h"
#include "game.h"
#include "shade.h"
#include "drow.h"
#include "goblin.h"
#include "vampire.h"
#include "troll.h"
#include "NEXTFLOOR.h"
#include "END.h"
#include "floor.h"
#include "cell.h"
#include <iostream>
using namespace std;

Game::Game(): currFloor(nullptr), currFloornum(1), pc(nullptr) {}


void Game::GameInit(string character, string filename) {//needs new character, start from floor 1


  if (character=="s") {
#ifdef D
    cout<<"try creating s"<<endl;
#endif
    pc = make_shared<Shade>(-1, -1, -1);
#ifdef D
    cout<<"created s"<<endl;
#endif
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
  #ifdef D
      cout<<"try creating floor"<<endl;
  #endif
  currFloor = make_shared<Floor>(currFloornum,pc,file);
  #ifdef D
      cout<<"created floor"<<endl;
  #endif
  if (filename==""){
    #ifdef D
        cout<<"floorinit"<<endl;
    #endif
    currFloor->FloorInit();
    #ifdef D
        cout<<"done floorinit"<<endl;
    #endif
    cout<<currFloor;
    currFloor->clearaction();
  }
  cout<<currFloor;
  currFloor->clearaction();
}


void Game::UsePotion(string dir){
  currFloor->UsePotion(dir);
  cout<<currFloor;
  currFloor->clearaction();
}


void Game::Attack(string dir){
  currFloor->attack(dir);
  cout<<currFloor;
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
      currFloor = make_shared<Floor>(currFloornum,pc,file);
    }
  }
  cout<<currFloor;
  currFloor->clearaction();
}

Game::~Game(){}
