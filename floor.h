#ifndef __FLOOR_H__
#define __FLOOR_H__
#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include "cell.h"
#include "subtype.h"
#include "steptype.h"

class Floor {
	const int floorNum;
	const int board_row = 80;
	const int board_col = 25;
	int pc_row;
	int pc_col;
	void Build_Wall(int row, int start, int end); //done
	void Build_Room(int row, int start, int end); //done
	void Build_Passage ( int row, int col, int counter, std::string direction); //done
	void attach_chamber(hared_ptr<Cell> c, int chamber, int row, int col);//done
	void subject_init(int chamber, int row, int col, std::string type); //done
	void summon_dragon(int chamber, int row, int col); //done
	void enermy_move(); //done
	void floor_given(std::string filename);
	vector<int> check_tile(int row, int col); //done
	bool freeze = false; //done
	shared_ptr<Cell> prevCell = nullptr;
	std::string action;
	std::vector <std::vector < shared_ptr<Cell> >> theFloor; //done
	std::vector <std::vector <int>> theDim; //done
	shared_ptr<Cell> pc = nullptr ; //done
  public:
	Floor(std::string Filename, int floorNum, PC *pc); //done	
	void FloorInit(); //done
	void FloorMove(std::string direction); //done
	~Floor();
	void notify(Subject &s); //done
	void addaction(std::string action);
	vector<int> getRandomPos(); //done
	void attack(std::string direction); //done
	void EnermySwitch(); //done
	void UsePotion(std::string direction); //done
	SubType subtype() override; //done
	void clearaction(); //done
	friend std::ostream &operator<<(std::ostream &out, const Floor &f);
};

#endif
