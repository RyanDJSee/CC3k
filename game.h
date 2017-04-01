#ifndef GAME_H
#define GAME_H

#include <string>
using namespace std;


Class Floor;
Class Cell;

class Game {
  shared_ptr<Floor> currFloor;
  int currFloornum;
  shared_ptr<PC> pc; //only uses getInfo

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
