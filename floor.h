#ifndef __FLOOR_H__
#define __FLOOR_H__

#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include "cell.h"


class Floor {
	const int floorNum;
	const int board_row = 80;
	const int board_col = 25;
	int pc_row;
	int pc_col;
	void Build_Wall(int row, int start, int end);
	void Build_Room(int row, int start, int end);
	void Build_Passage ( int row, int col, int counter, std::string direction);
	void attach_chamber(Cell *c, int chamber, int row, int col);
	void subject_init(int chamber, int row, int col, std::string type);
	void summon_dragon(int chamber, int row, int col);
  public:
	std::vector <std::vector <Cell*>> theFloor;
	std::vector <std::vector <int>> theDim;
	PC *pc = new PC;
	Floor(int floorNum, PC *pc);
	void FloorInit(); 
	void FloorMove(std::string sx, std::string sy);
	vector<int> getRandomPos();
	void notify(Subject &s);
	~Floor();
};

#endif
