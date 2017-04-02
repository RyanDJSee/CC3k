#ifndef GAME_H
#define GAME_H

#include <string>
#include <memory>


class PC;
class Floor;
class Cell;

class Game {
  std::shared_ptr<Floor> currFloor;
  int currFloornum;
  std::shared_ptr<Cell> pc; //only uses getInfo
  std::string file;

public:
  Game();
  void GameInit(std::string PC, std::string filename="");//needs new character, start from floor 1
  void UsePotion(std::string dir);
  void Attack(std::string dir);
  void EnemySwitch();
  void Restart();
  void MoveChar(std::string dir);
  ~Game()=default;
};

#endif
