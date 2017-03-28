#ifndef GAME_H
#define GAME_H

#include <string>
using namespace std;


Class Floor;
Class Cell;

class Game {
  Floor *currFloor;
  int currFloornum;
  PC *pc; //only uses getInfo

public:
  Game();
  void GameInit(string char);//needs new character, start from floor 1
  void Restart();
  void MoveChar(string dir);
  void isWon();
  ~Game();
};

#endif
