#include <iostream>
#include <string>

#include "floor.h"

using namespace std;

Floor::Floor(){}

Floor::~Floor(){}

Floor::Floor(int floorNum, PC *pc): floorNum{floorNum}{
	//initialize empty space for each chamber
	vector<int> C1;
	vector<int> C2;
	vector<int> c3;
	vector<int> c4;
	vector<int> c5;
	for ( int i =0; i < 4; i++){
		C1.push_back(26);
	}
	for ( int i = 0; i < 3; i++){
		C2.push_back(12);
	}
	for ( int i = 0; i < 7; i++){
		C3.push_back(21);
	}
	C4.push_back(23);
	C4.push_back(23);
	C4.push_back(31);
	C4.push_back(34);
	for (int i = 0; i < 6; i++){
		C4.push_back(15);
	}
	for ( int i = 0; i < 3; i++){
		C5.push_back(11);
	}
	for(int i = 0; i < 3; i++){
		C5.push_back(39);
	}

	//initilize the board:
	vector <Cell*> temp;
	for ( int i = 0 ; i < board_col ; i++){
		Cell *cel;
		temp.push_back(cel);
	}
	for ( int j = 0; j < board_row ; i++){
		theFloor.push_back(temp);
	}
	Build_Wall(0, 0, board_col - 1);
	Build_Wall(board_row -1, 0, board_col - 1);

	//Building first chamber
	int rowChamber1_start = 2;
	int rowChamber1_end = 7;
	int colChamber1_start = 2;
	int colChamber1_end = 29;
	for ( int i = rowChamber1_start; i <= rowChamber1_end ; i++){
		if (i == rowChamber1_start || i == rowChamber1_end){
			Build_Wall(i, colChamber1_start, colChamber_end, 1);
		}else{
			Build_Room(i, colChamber1_start, colChamber_end, 1);
		}
	}
	theFloor[4][29] = new door(1,4,29);
	theFloor[7][13] = new door(1,7,13);
	
	//Building second Chamber
	int rowChamber2_start = 9;
	int rowChamber2_end = 13;
	int colChamber2_start = 37;
	int colChamber2_end = 50;
        for ( int i = rowChamber1_start; i <= rowChamber1_end ; i++){
                if (i == rowChamber1_start || i == rowChamber1_end){
                        Build_Wall(i, colChamber1_start, colChamber_end,2);
                }else{
                        Build_Room(i, colChamber1_start, colChamber_end,2);
                }
        }
	theFloor[9][43] = new door(2,9, 43);
	theFloor[13][43] = new door(2,13,43);

	//Building third Chamber
	int rowChamber3_start = 14; 
	int rowChamber3_end = 22;
	int colChamber3_start = 3;
	int colChamber3_end = 25;
        for ( int i = rowChamber1_start; i <= rowChamber1_end ; i++){
                if (i == rowChamber1_start || i == rowChamber1_end){
                        Build_Wall(i, colChamber1_start, colChamber_end,3);
                }else{
                        Build_Room(i, colChamber1_start, colChamber_end,3);
                }
        }
	theFloor[14][13] = new door(3,14,13);
	theFloor[20][25] = new door(3, 20, 25);

	//Building fourth Chamber
	int rowChamber4_start = 2;
	int rowChamber4_end = 13;
	int colChamber4_start = 38;
	int colChamber4_end = 76;
	Build_Wall(rowChamber4_start , colChamber4_start, 62,4);
	Build_Room(rowChamber4_start + 1 , colChamber4_start, 62,4);
	BUild_Room(rowChamber4_start + 2 , colChamber4_start, 62,4);
	Build_Wall(rowChamber4_start + 2 ,62, 70,4);
	Build_Room(rowChamber4_start + 3, colChamber4_start, 70,4);
	Build_Wall(rowChamber4_start + 3, 70, 73,4);
	Build_Room(rowChamber4_start + 4, colChamer4_start, 73,4);
	Build_Wall(rowChamber4_start + 4, 73, 76,4);
	Build_Wall(rowChamber4_start + 5, colChamber4_start, 60,4);
	Build_Room(rowChamber4_start + 5, 60, colChamber4_end,4);
	for ( int i = rowChamer4_start + 6, i <= rowChamber4_end ; i++){
		if ( i == rowChamber4_end ){
			Build_Wall(i, 60, colChamber4_end,4);
		}else{
			Build_Room(i, 60, colChamber4_end,4);
		}
	}
	theFloor[7][43] = new door(4 , 7, 43);
	theFloor[11][60] = new door( 4 , 11 ,60);
	theFloor[13][69] = new door( 4, 13 , 69);

	//Building fifth Chamber
	int rowchamber5_start = 15;
	int rowChamber5_end = 22;
	int colChamber5_start = 36;
	int colChamber5_end = 76;
	for ( int i = rowchamber5_start ; i<= rowChamber5_end -1; i++){
		if( i <= rowChamber5_start + 3){
			if( i == rowChamber5_start){
				Build_Wall(i, 64, colChamber5_end,5);
			}else if ( i == rowChamber5_start + 3){		
				Build_Wall(i, colChamber5_start, 64,5);
				Build_Room(i, 64, colChamber5_end,5);
			}else{
				Build_Room(i, 64, colChamber5_end,5);
			}
		}else{
			Build_Room(i, colChamber5_start, colChamber5_end,5);
		}
	}
	Build_Wall(rowChamber5_end, colChamber5_start, colChamber5_end,5 );
	theFloor[15][69] = new door(5, 15,69);
	theFlooor[18][43] = new door(5,18,43);
	theFloor[20][36] = new door(5, 20, 36);

	//Building board passage between CHAMBER
	Build_Passage(4, 30, 8, "verti"); //between 1 & 4
	Build_Passage(8, 31, 13 , "verti");
	Build_Passage(11, 13, 19, "verti"); 
	Build_Passage(11, 54, 6, "verti");
	Build_Passage(16, 31, 24, "verti");
	Build_Passage(20, 26, 10, "verti");
	Build_Passage(5, 33, 3, "hori");
	Build_Passage(8, 13, 5, "hori");
	Build_Passage(8, 31, 12, "hori");
	Build_Passage(14, 43, 4, "hori");
	Build_Passage(11, 54, 6, "hori");
}

void Floor:Build_Passage(int row, int col , int counter, string direction){
   for ( int i = 0 ; i< counter ; i++){
	if (direction == "hori"){
		theFloor[row+i][col]=  new passage(0, row+i, col);
	}else if (direction =="verti"){
		theFloor[row][col+i] = new passage(0, row, col + i);
	}
   }
}

void Floor::Build_Wall(int row, int start, int end, int chamber){
	theFloor[row][start] = new wall(chamber, row, start, '|');
	theFloor[row][end] = new wall(chamber, row, end, '|');
	for ( int i = start + 1; i < end ; i ++){
		theFloor[row][i] = new wall(chamber, row , i , '-'); 
	}
}

void Floor::Build_Room(int row, int start, int end,int chamber){
	theFloor[row][start] = new wall(chamber, row, start, '|');
	theFloor[row][end] = new wall(chamber, row, end, '|');
	for ( int i = start + 1; i < end; i++){
		theFloor[row][i] = new empty(chamber, row, end);
	}
}

void Floor::FloorInit(){
  //init pc
	vector<int> pos = getRandomPos();
	subject_init(pos[0], pos[1], pos[2], "PC");
	attach_chamber(chamber+1, theFloor[pos_row][pos_col], pos_row, pos_col);
  //init stairway
	pos = getRandomPos();
	subject_init(pos[0], pos[1], pos[2], "STAIR");
  // init POTIONS
	for ( int i = 0; i < 10 ; i++){
		pos = getRandomPos();
		subject_init(pos[0], pos[1], pos[2], "POTIONS");
	}
  // init GOLD 
	for ( int i = 0; i < 10; i++){
		pos = getRandomPos();
		subject_init(pos[0], pos[1], pos[2], "GOLD");
	}
  // init ENERMY
	for ( int i = 0; i < 20; i++){
		pos = getRandomPos();
		subject_init(pos[0], pos[1]. pos[2], "ENERMY");
	}
}

void Floor::subject_init(int chamber, int row, int col,string type){
	delete theFloor[row][col];
	if ( type == "PC"){
		theFloor[row][col]  = pc;
		pc->createCharacter(chamber + 1, row, col, type)
	}else if ( type == "STAIR"){
		theFloor[row][col] = new Stair(chamber, row, col);
	}else if ( type == "POTIONS"){
		int potion_type = rand() % 6 + 1 ;
		if ( potion_type == 1){
			theFloor[row][col] = new RH(chamber, row,col);
		}else if ( potion_type == 2){
			theFloor[row][col] = new BA(chamber, row, col);
		}else if( potion_type == 3){
			theFloor[row][col] = new BD(chamber, row, col);
		}else if (potion_type == 4){
			theFloor[row][col] = new PH(chamber, row, col);
		}else if (potion_type == 5){
			theFloor[row][col] = new WA(chamber, row, col);
		}else{
			theFloor[row][col] = new WD(chamber, row, col);
		}
	}else if ( type == "GOLD"){
		int gold_type = rand() % 8 + 1;
		if ( gold_type <= 5){ //normal 
			theFloor[row][col] = new Treasure(chamber, row, col, 2, false);
		}else if (gold_type == 6){ //dragon hoard
			theFloor[row][col] = new Treasure(chamber, row, col, 6, true);
			summon_dragon(chamber, row,col);
		}else{ // small hoard
			theFloor[row][col] = new Treasure(chamber, row, col, 1, false);
		}
	}else {//type == "ENERMY"
		int enermy_type = rand() % 18 + 1;
		if ( enermy_type <= 4 ){ //human
			theFloor[row][col] = new Human(chamber, row, col, 140, 20, 20);
		} else if ( enermy_type <= 7){ // Dwarf
			theFloor[row][col] = new Dwarf(chamber, row, col, 100, 20, 30);
		} else if (enermy_type <= 12){ // Hafling
			theFloor[row][col] = new Hafling(chamber, row, col, 140, 30, 10);
		} else if (enermy_type <= 14){ // Elf
			theFloor[row][col] = new Elf(chamber, row, col, 140, 30, 10);
		} else if (enermy_type <= 16){ // Orc
			theFloor[row][col] = new Orc(chamber, row, col, 180, 30 , 25);
		}else{ //Merchant
			theFloor[row][col] = new Merchant(chamber, row, col, 30, 70, 5);
		}
	}
}

void Floor::summon_dragon(int chamber, int row, int col){
	int tile = 0;
	vector < vector<int> > xy;
	vector<int> temp;
	if ( theFloor[row-1][col-1].getRep() == '-'){
		 tile++;
		 temp.clear();
		 temp.push_back(row-1);
		 temp.push_back(col-1);
		 xy.push_back(temp);
	}
        if ( theFloor[row-1][col].getRep() == '-'){
                 tile++;
                 temp.clear();
                 temp.push_back(row-1);
                 temp.push_back(col-1);
                 xy.push_back(temp);
        }
        if ( theFloor[row-1][col+1].getRep() == '-'){
                 tile++;
                 temp.clear();
                 temp.push_back(row-1);
                 temp.push_back(col-1);
                 xy.push_back(temp);
        }
        if ( theFloor[row][col-1].getRep() == '-'){
                 tile++;
                 temp.clear();
                 temp.push_back(row-1);
                 temp.push_back(col-1);
                 xy.push_back(temp);
        }
        if ( theFloor[row][col+1].getRep() == '-'){
                 tile++;
                 temp.clear();
                 temp.push_back(row-1);
                 temp.push_back(col-1);
                 xy.push_back(temp);
        }
        if ( theFloor[row+1][col-1].getRep() == '-'){
                 tile++;
                 temp.clear();
                 temp.push_back(row-1);
                 temp.push_back(col-1);
                 xy.push_back(temp);
        }
        if ( theFloor[row+1][col1].getRep() == '-'){
                 tile++;
                 temp.clear();
                 temp.push_back(row-1);
                 temp.push_back(col-1);
                 xy.push_back(temp);
        }
        if ( theFloor[row+1][col+1].getRep() == '-'){
                 tile++;
                 temp.clear();
                 temp.push_back(row-1);
                 temp.push_back(col-1);
                 xy.push_back(temp);
        }
	int ran = rand() % tile + 1;
	temp = xy[ran];
	int pos_row = temp[0];
	int pos_col = temp[1];
	delete theFloor[pos_row][pos_col];
	theFloor[pos_row][pos_col] = new Dragon(chamber, pos_row, pos_col,150, 20,20,theFloor[row][col]);
	theFloor[pos_row][pos_col]->attach(& theFloor[row][col]);
	theFloor[row][col]->attach(& theFloor[pos_row][pos_col];
} 


void Floor::attach_chamber(int chamber, Cell *c, int row, int col){
	c->attach(& c[row-1][col-1];
        c->attach(& c[row-1][col];
        c->attach(& c[row-1][col+1];
        c->attach(& c[row][col-1];
        c->attach(& c[row][col+1];
        c->attach(& c[row+1][col-1];
        c->attach(& c[row+1][col];
        c->attach(& c[row+1][col+1];
}

void Floor::FloorMove(string sx, string sy){}


vector<int> Floor::getRandomPos(){
	vector <int> result;
	int row = 0;
	int col = 0;
  while ( theFloor[row][col] == nullptr ){
	int chamber = rand() % 5; // which chamber?
        int c_size = theDim[chamber].size(); //how many row in the chamber?
        int line = rand() % c_size; // which row in the selected chamber?
        int block = rand() % theDim[chamber][line]; // which col is the selected chamber?
	int row_start;
	int col_start;
		if ( chamber == 0 ){ //first chamber
			row_start = 3;
			col_start = 3;
		}else if ( chamber == 1){ //second chamber
			row_start = 10;
			col_start = 38;
		}else if ( chamber == 2){ //third chamber
			row_start = 15;
			col_start = 4;
		}else if ( chamber == 3){ //fourth chamber
			if ( line <= 3 ){
				row_start = 3;
				col_start = 39;
			}else{
				row_start = 7;
				col_start = 61
			}
		}else if ( chamber == 4){ //fifth chamber
			if ( line <= 2){
				row_start = 16;
				col_start = 65;
			}else{
				row_start = 19;
				col_start = 37;
			}
		}
	int row_operate = row_start + line;
	int col_operate = col_start + line;
	if (theFloor[row_operate][col_operate]->getRep() == '.'){
		row = row_operate;
		col = col_operate;
	}
  }
	result.push_back(chamber);
	result.push_back(row);
	result.push_back(col);

	return result;
} 
