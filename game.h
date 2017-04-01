#ifndef GAME_H
#define GAME_H

#include <string>
#include <memory>
using namespace std;

class PC;
class Floor;
class Cell;

class Game {
  shared_ptr<Floor> currFloor;
  int currFloornum;
  shared_ptr<Cell> pc; //only uses getInfo
  string file;

public:
  Game();
  void GameInit(string PC, string filename="");//needs new character, start from floor 1
  void UsePotion(string dir);
  void Attack(string dir);
  void EnemySwitch();
  void Restart();
  void MoveChar(string dir);
  ~Game();
};

#endif
