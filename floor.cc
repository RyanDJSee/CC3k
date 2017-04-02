#include <iostream>
#include <memory>
#include <string>
#include <fstream>
#include "floor.h"

using namespace std;

//Floor::Floor(){}

Floor::~Floor(){}

Floor::Floor(int floorNum, shared_ptr<Cell> pc, string filename): floorNum{floorNum}, pc{pc}{
	
	if ( filename == ""){
	//initialize empty space for each chamber
	vector<int> C1;
	vector<int> C2;
	vector<int> C3;
	vector<int> C4;
	vector<int> C5;
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
	vector <shared_ptr <Cell> > temp;
	for ( int i = 0 ; i < board_col ; i++){
		shared_ptr<Cell> cel;
		temp.push_back(cel);
	}
	for ( int j = 0; j < board_row ; j++){
		theFloor.push_back(temp);
	}
	Build_Wall(0, 0, board_col - 1,0);
	Build_Wall(board_row -1, 0, board_col - 1,0);

	//Building first chamber
	int rowChamber1_start = 2;
	int rowChamber1_end = 7;
	int colChamber1_start = 2;
	int colChamber1_end = 29;
	for ( int i = rowChamber1_start; i <= rowChamber1_end ; i++){
		if (i == rowChamber1_start || i == rowChamber1_end){
			Build_Wall(i, colChamber1_start, colChamber1_end, 1);
		}else{
			Build_Room(i, colChamber1_start, colChamber1_end, 1);
		}
	}
	theFloor[4][29]=make_shared<Door>(1,4,29);
	theFloor[4][29]->setPos(4,29,1);
	theFloor[4][29]->attach(shared_from_this());
	theFloor[7][13] = make_shared<Door>(1,7,13);
	theFloor[7][13]->setPos(7,13,1);
	theFloor[7][13]->attach(shared_from_this());
	
	//Building second Chamber
	int rowChamber2_start = 9;
	int rowChamber2_end = 13;
	int colChamber2_start = 37;
	int colChamber2_end = 50;
        for ( int i = rowChamber2_start; i <= rowChamber2_end ; i++){
                if (i == rowChamber2_start || i == rowChamber2_end){
                        Build_Wall(i, colChamber2_start, colChamber2_end,2);
                }else{
                        Build_Room(i, colChamber2_start, colChamber2_end,2);
                }
        }
	theFloor[9][43] = make_shared<Door>(2,9, 43);
	theFloor[9][43]->setPos(9,43,2);
	theFloor[9][43]->attach(shared_from_this());
	theFloor[13][43] = make_shared<Door>(2,13,43);
	theFloor[13][43]->setPos(13,43,2);
	theFloor[13][43]->attach(shared_from_this());

	//Building third Chamber
	int rowChamber3_start = 14; 
	int rowChamber3_end = 22;
	int colChamber3_start = 3;
	int colChamber3_end = 25;
        for ( int i = rowChamber3_start; i <= rowChamber3_end ; i++){
                if (i == rowChamber3_start || i == rowChamber3_end){
                        Build_Wall(i, colChamber3_start, colChamber3_end,3);
                }else{
                        Build_Room(i, colChamber3_start, colChamber3_end,3);
                }
        }
	theFloor[14][13] = make_shared<Door>(3,14,13);
	theFloor[14][13]->setPos(14,13,3);
	theFloor[14][13]->attach(shared_from_this());
	theFloor[20][25] = make_shared<Door>(3, 20, 25);
	theFloor[20][25]->setPos(20,25,3);
	theFloor[20][25]->attach(shared_from_this());

	//Building fourth Chamber
	int rowChamber4_start = 2;
	int rowChamber4_end = 13;
	int colChamber4_start = 38;
	int colChamber4_end = 76;
	Build_Wall(rowChamber4_start , colChamber4_start, 62,4);
	Build_Room(rowChamber4_start + 1 , colChamber4_start, 62,4);
	Build_Room(rowChamber4_start + 2 , colChamber4_start, 62,4);
	Build_Wall(rowChamber4_start + 2 ,62, 70,4);
	Build_Room(rowChamber4_start + 3, colChamber4_start, 70,4);
	Build_Wall(rowChamber4_start + 3, 70, 73,4);
	Build_Room(rowChamber4_start + 4, colChamber4_start, 73,4);
	Build_Wall(rowChamber4_start + 4, 73, 76,4);
	Build_Wall(rowChamber4_start + 5, colChamber4_start, 60,4);
	Build_Room(rowChamber4_start + 5, 60, colChamber4_end,4);
	for ( int i = rowChamber4_start + 6; i <= rowChamber4_end ; i++){
		if ( i == rowChamber4_end ){
			Build_Wall(i, 60, colChamber4_end,4);
		}else{
			Build_Room(i, 60, colChamber4_end,4);
		}
	}
	theFloor[7][43] = make_shared<Door>(4 , 7, 43);
	theFloor[7][43]->setPos(7,43,4);
	theFloor[7][43]->attach(shared_from_this());
	theFloor[11][60] = make_shared<Door>( 4 , 11 ,60);
	theFloor[11][60]->setPos(11,60,4);
	theFloor[11][60]->attach(shared_from_this());
	theFloor[13][69] = make_shared<Door>( 4, 13 , 69);
	theFloor[13][69]->setPos(13,69,4);
	theFloor[13][69]->attach(& theFloor);

	//Building fifth Chamber
	int rowChamber5_start = 15;
	int rowChamber5_end = 22;
	int colChamber5_start = 36;
	int colChamber5_end = 76;
	for ( int i = rowChamber5_start ; i<= rowChamber5_end -1; i++){
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
	theFloor[15][69] = make_shared<Door>(5, 15,69);
	theFloor[15][69]->setPos(15,69,5);
	theFloor[15][69]->attach(shared_from_this());
	theFlooor[18][43] = make_shared<Door>(5,18,43);
	theFloor[18][43]->setPos(18,43,5);
	theFloor[18][43]->attach(shared_from_this());
	theFloor[20][36] = make_shared<Door>(5, 20, 36);
	theFloor[20][36]->setPos(20,36,5);
	theFloor[20][36]->attach(shared_from_this());

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
	}else{
		floor_given(filename);
	}
}

void Floor::Build_Passage(int row, int col , int counter, string direction){
   for ( int i = 0 ; i< counter ; i++){
	if (direction == "hori"){
		theFloor[row+i][col]=  make_shared<Passage>(0, row+i, col);
		theFloor[row+i][col]->setPos(row+i, col,0);
		theFloor[row+1][col]->attach(shared_from_this());
	}else if (direction =="verti"){
		theFloor[row][col+i] = make_shared<Passage>(0, row, col + i);
		theFloor[row][col+i]->setPos(row, col+i,0);
		theFloor[row][col+i]->attach(shared_from_this());
	}
   }
}

void Floor::Build_Wall(int row, int start, int end, int chamber){
	theFloor[row][start] = make_shared<Wall>(chamber, row, start, "|");
	theFloor[row][end] = make_shared<Wall>(chamber, row, end, "|");
	for ( int i = start + 1; i < end ; i ++){
		theFloor[row][i] = make_shared<Wall>(chamber, row , i , "-");
		theFloor[row][i]->setPos(row, i,chamber);
		theFloor[row][i]->attach(shared_from_this());
	}
}

void Floor::Build_Room(int row, int start, int end,int chamber){
	theFloor[row][start] = make_shared<Wall>(chamber, row, start, "|");
	theFloor[row][end] = make_shared<Wall>(chamber, row, end, "|");
	for ( int i = start + 1; i < end; i++){
		theFloor[row][i] = make_shared<Empty>(chamber, row, i);
		theFloor[row][i]->setPos(row, i,chamber);
		theFloor[row][i]->attach(shared_from_this());
	}
}

void Floor:floor_given(string filename){
	ifstream fin{filename};
	char s;
	int row = 0;
	int col = 0;
	while (fin.get(s){
		if ( s == '\n'){
			row++;
			col = 0;
			if(!fin.get(s)) break;
		}
		if(s == '|' ){
			theFloor[row][col] = make_shared<Wall>(0, row,col, "|");
		}else if ( s == '-'){
			theFloor[row][col] = make_shared<Wall>(0, row, col, "-");
		}else if ( s == '.' ){
			theFloor[row][col] = make_shared<Empty>(0, row,col);
		}else if ( s == '+'){
			theFloor[row][col] = make_shared<Door>(0, row,col);
		}else if( s == '#'){
			theFloor[row][col] = make_shared<Passage>(0, row, col);
		}else if( s == '\\'){
			theFloor[row][col] = make_shared<Stair>(0, row, col);
		}else if( s == '@'){
			theFloor[row][col] = pc;
		}else if( s == 'L'){
			theFloor[row][col] = make_shared<Hafling>(0, row, col);
		}else if( s == 'O'){
			theFloor[row][col] = make_shared<Orc>(0, row, col);
		}else if (s == 'D'){
			theFloor[row][col] = make_shared<Dragon>(0, row, col);
		}else if( s == 'E'){
			thefloor[row][col] = make_shared<Elf>(0, row, col);
		}else if( s == 'H'){
			theFloor[row][col] = make_shared<Human>(0,row, col);
		}else if (s == 'W'){
			theFloor[row][col] = make_shared<Dwarf>(0, row, col);
		}else if ( s == '0'){
			theFloor[row][col] = make_shared<RH>(0, row, col);
		}else if ( s == '1'){
			theFloor[row][col] = make_shared<BA>(0, row, col);
		}else if ( s == '2'){
			theFloor[row][col] = make_shared<BD>(0, row, col);
		}else if ( s == '3'){		
			theFloor[row][col] = make_shared<PH>(0,row, col);
		}else if ( s == '4'){	
			theFloor[row][col] = make_shared<WA>(0, row, col);
		}else if ( s == '5'){
			theFloor[row][col] = make_shared<WD>(0, row, col);
		}else if ( s == '6'){
			theFloor[row][col] = make_shared<Treasure>(0, row, col, 2, false); 
		}else if ( s == '7'){
			theFloor[row][col] = make_shared<Treasure>(0, row, col, 1, false);
		}else if ( s == '8'){
			theFloor[row][col] = make_shared<Treasure>(0, row, col, 4, false);
		}else if ( s == '9'){
			theFloor[row][col] = make_shared<Treasure>(0, row, col, 6, true);
		}		
			theFloor[row][col]->setPos(row,col, 0);
			theFloor[row][col]->notify( & theFloor);
		col++; 
	}
}

void Floor::FloorInit(){
  //init pc
	vector<int> pos = getRandomPos();
	subject_init(pos[0], pos[1], pos[2], "PC");
	attach_chamber(theFloor[pos[1]][pos[2]],pos[0], pos[1], pos[2]);

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
		subject_init(pos[0], pos[1], pos[2], "ENERMY");
	}
}

void Floor::subject_init(int chamber, int row, int col,string type){
	if ( type == "PC"){
		theFloor[row][col]  = pc;
		pc_row = row;
		pc_col = col;
	}else if ( type == "STAIR"){
		theFloor[row][col] = make_shared<Stair>(chamber, row, col);
	}else if ( type == "POTIONS"){
		int potion_type = rand() % 6 + 1 ;
		if ( potion_type == 1){
			theFloor[row][col] = make_shared<RH>(chamber, row,col);
		}else if ( potion_type == 2){
			theFloor[row][col] = make_shared<BA>(chamber, row, col);
		}else if( potion_type == 3){
			theFloor[row][col] = make_shared<BD>(chamber, row, col);
		}else if (potion_type == 4){
			theFloor[row][col] = make_shared<PH>(chamber, row, col);
		}else if (potion_type == 5){
			theFloor[row][col] = make_shared<WA>(chamber, row, col);
		}else{
			theFloor[row][col] = make_shared<WD>(chamber, row, col);
		}
	}else if ( type == "GOLD"){
		int gold_type = rand() % 8 + 1;
		if ( gold_type <= 5){ //normal 
			theFloor[row][col] = make_shared<Treasure>(chamber, row, col, 2, false);
		}else if (gold_type == 6){ //dragon hoard
			theFloor[row][col] = make_shared<Treasure>(chamber, row, col, 6, true);
			summon_dragon(chamber, row,col);
		}else{ // small hoard
			theFloor[row][col] = make_shared<Treasure>(chamber, row, col, 1, false);
		}
	}else {//type == "ENERMY"
		int enermy_type = rand() % 18 + 1;
		if ( enermy_type <= 4 ){ //human
			theFloor[row][col] = make_shared<Human>(chamber, row, col);
		} else if ( enermy_type <= 7){ // Dwarf
			theFloor[row][col] = make_shared<Dwarf>(chamber, row, col);
		} else if (enermy_type <= 12){ // Hafling
			theFloor[row][col] = make_shared<Hafling>(chamber, row, col);
		} else if (enermy_type <= 14){ // Elf
			theFloor[row][col] = make_shared<Elf>(chamber, row, col);
		} else if (enermy_type <= 16){ // Orc
			theFloor[row][col] = make_shared<Orc>(chamber, row, col);
		}else{ //Merchant
			theFloor[row][col] = make_shared<Merchant>(chamber, row, col);
		}
	}
	theFloor[row][col]->setPos(row,col,chamber);
}



vector<int> Floor:check_tile(int row, int col){
	int tile = 0;
	vector < vector<int> > xy;
	vector<int> temp;
	if ( theFloor[row-1][col-1]->isEmpty()){
		 tile++;
		 temp.clear();
		 temp.push_back(row-1);
		 temp.push_back(col-1);
		 xy.push_back(temp);
	}
        if ( theFloor[row-1][col]->isEmpty()){
                 tile++;
                 temp.clear();
                 temp.push_back(row-1);
                 temp.push_back(col-1);
                 xy.push_back(temp);
        }
        if ( theFloor[row-1][col+1]->isEmpty()){
                 tile++;
                 temp.clear();
                 temp.push_back(row-1);
                 temp.push_back(col-1);
                 xy.push_back(temp);
        }
        if ( theFloor[row][col-1]->isEmpty()){
                 tile++;
                 temp.clear();
                 temp.push_back(row-1);
                 temp.push_back(col-1);
                 xy.push_back(temp);
        }
        if ( theFloor[row][col+1]->isEmpty(){
                 tile++;
                 temp.clear();
                 temp.push_back(row-1);
                 temp.push_back(col-1);
                 xy.push_back(temp);
        }
        if ( theFloor[row+1][col-1]->isEmpty()){
                 tile++;
                 temp.clear();
                 temp.push_back(row-1);
                 temp.push_back(col-1);
                 xy.push_back(temp);
        }
        if ( theFloor[row+1][col1]->isEmpty()){
                 tile++;
                 temp.clear();
                 temp.push_back(row-1);
                 temp.push_back(col-1);
                 xy.push_back(temp);
        }
        if ( theFloor[row+1][col+1]->isEmpty()){
                 tile++;
                 temp.clear();
                 temp.push_back(row-1);
                 temp.push_back(col-1);
                 xy.push_back(temp);
        }
	int ran = rand() % tile + 1;
	temp = xy[ran];
	return temp;
}

void Floor::summon_dragon(int chamber, int row, int col){
	vector<int> temp = check_tile(row, col);
	int pos_row = temp[0];
	int pos_col = temp[1];
	theFloor[pos_row][pos_col] = make_shared<Dragon>(chamber, pos_row, pos_col,theFloor[row][col]);
	theFloor[pos_row][pos_col]->attach(& theFloor[row][col]);
	theFloor[pos_row][pos_col]->getPos(chamber, pos_row, pos_col);
	theFloor[row][col]->attach(& theFloor[pos_row][pos_col];
} 


void Floor::attach_chamber(shared_ptr<Cell> c, int chamber, int row, int col){
	c->attach(& c[row-1][col-1];
        c->attach(& c[row-1][col];
        c->attach(& c[row-1][col+1];
        c->attach(& c[row][col-1];
        c->attach(& c[row][col+1];
        c->attach(& c[row+1][col-1];
        c->attach(& c[row+1][col];
        c->attach(& c[row+1][col+1];
}

void Floor::FloorMove(string direction){
	//PC MOVE
	int adjust_row = 0;
	int adjust_col = 0;
	if (direction == "no") { //north 
		adjust_row = -1;
		action = "north";
	}else if(direction == "so"){ //south
		adjust_row = 1;
		action = "south";
	}else if(direction == "ea"){ //east
		adjust_col = 1;
		action = "east";
	}else if(direction == "we"){ //west
		adjust_col = -1;
		action = "west";
	}else if(direction == "ne"){ //north east
		adjust_row = -1;
		adjust_col = 1;
		action = "north east";
	}else if(direction == "nw"){ //north west
		adjust_row = -1;
		adjust_col = -1;
		action = "north west";
	}else if(direction == "se"){ //south east
		adjust_row = 1;
		adjust_col = 1;
		action = "south east";
	}else if(direction == "sw"){ //south west
		adjust_row = 1;
		adjust_col = -1;
		action = "south west";
	}else{ // exception
		
	}
	int current_row = pc_row;
	int current_col = pc_col;
	int new_row = pc_row + adjust_row;
	int new_col = pc_col + adjust_col;
	vector<int> info = theFloor[current_row][current_col]->getPos();
	int chamber = info[0];
	pc_row = new_row;
	pc_col = new_col;
	//condition

	if(theFloor[new_row][new_col]->Steppable() != StepType::CantStep){ //!= "CantStep"
		pc.detachall();
//		detach_chamber(theFloor[current_row][current_col], chamber, current_row, currnet_col);
		theFloor[current_row][current_col] = prevCell;
		prevCell = theFloor[new_row][new_col];
		if ( theFloor[new_row][new_col]->Steppable() == StepType::PickUp){
			if (prevCell.isEmpty() == false){
				PC->use(prevCell);
				prevCell = make_shared<Empty>(chamber, current_row, current_col);
			}	
		}		
		theFloor[new_row][new_col] = pc;
		attach_chamber(theFloor[new_row][new_col], chamber, new_row, new_col);
		theFloor[new_row][new_col]->setPos(chamber, new_row, new_col);
		theFloor[new_row][new_col]->notify(theFloor[new_row][new_col].subType());
		PC.notifyobs( SubType::CELL );
		action = "PC move to " + action ".";
	}
	//ENERMY
	if ( freeze == false ){	
	enermy_move();
	}
}

void Floor::clearaction(){
	action = "";
}

void Floor::enermy_move(){
	for ( int i = 0; i < board_row ; i++){
		for ( int j = 0; j < board_col ; j++){
			if (dynamic_pointer_cast<Enermy>(theFloor[i][j]) && //it is an enermy
			 	  theFloor[i][j]->Moved() == false ){
				int count = 0;
				vector<int> temp = check_tile(i, j);
				int new_row = temp[0];
				int new_col = temp[1];
				vector <int> info = theFloor[i][j]->getPos();		
				shared_ptr<Cell> temp = theFloor[new_row][new_col];
				theFloor[new_row][new_col] = theFloor[i][j];
				theFloor[new_row][new_col]->setPos(info[0], new_row, new_col];
				theFloor[i][j] = temp;
				theFloor[new_row][new_col]->setMoved(true);	
			}
		}
	}
	for ( int i = 0; i < board_row ; i++){
		for ( int j = 0; j <board_col; j++){
			theFloor[i][j]->setMoved(false);
		}

	}
}




vector<int> Floor::getRandomPos(){
	vector <int> result;
	int row = 0;
	int col = 0;
  while ( dynamic_pointer_cast<Wall>(theFloor[row][col]) ){
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
	if (theFloor[row_operate][col_operate]->isEmpty()){
		row = row_operate;
		col = col_operate;
	}
  }
	result.push_back(chamber);
	result.push_back(row);
	result.push_back(col);

	return result;
}


void EnermySwitch(){
	if (freeze == false){
		freeze = true;
	}if ( freeze == true){
		freeze = false;
	}
}

void attack(string direction){
	vector<int> info = PC->getPos();
	int adjust_row = 0;
        int adjust_col = 0;
        if (direction == "no") { //north
                adjust_row = -1;
        }else if(direction == "so"){ //south
                adjust_row = 1;
        }else if(direction == "ea"){ //east
                adjust_col = 1;
        }else if(direction == "we"){ //west
                adjust_col = -1;
        }else if(direction == "ne"){ //north east
                adjust_row = -1;
                adjust_col = 1;
        }else if(direction == "nw"){ //north west
                adjust_row = -1;
                adjust_col = -1;
        }else if(direction == "se"){ //south east
                adjust_row = 1;
                adjust_col = 1;
        }else if(direction == "sw"){ //south west
                adjust_row = 1;
                adjust_col = -1;
        }else{ // exception

        }
	int new_row = adjust_row + info[1];
	int new_col = adjust_row + info[2];
	int new_chamber = info[0];
	if( dynamic_pointer_cast<Enemy>(theFloor[new_row][new_col]) ){
		theFloor[new_row][new_col]->attackedBy(pc);
		pc.notifyobs( SubType::CELL );
	}
}

void UsePotion(string direction){
	vector<int> info = pc->getPos();
        int adjust_row = 0;
        int adjust_col = 0;
        if (direction == "no") { //north
                adjust_row = -1;
        }else if(direction == "so"){ //south
                adjust_row = 1;
        }else if(direction == "ea"){ //east
                adjust_col = 1;
        }else if(direction == "we"){ //west
                adjust_col = -1;
        }else if(direction == "ne"){ //north east
                adjust_row = -1;
                adjust_col = 1;
        }else if(direction == "nw"){ //north west
                adjust_row = -1;
                adjust_col = -1;
        }else if(direction == "se"){ //south east
                adjust_row = 1;
                adjust_col = 1;
        }else if(direction == "sw"){ //south west
                adjust_row = 1;
                adjust_col = -1;
        }else{ // exception

        }
        int new_row = adjust_row + info[1];
        int new_col = adjust_row + info[2];
        int new_chamber = info[0];
	if (dynamic_pointer_cast<Potion>(theFloor[new_row][new_col]) ){
		pc->use(c);
		
	}
}

void Floor::addaction(string action2){
	action = action +", and "+ action2;
}

void Floor::notify(Subject &s){
	//when enermy died
	vector<int> info = s.getPos();
	theFloor[info[1]][info[2]] = make_shared<Gold>(chamber,info[1][info[2]]);
	//for dragon human merchant
	if ( dynamic_pointer_cast<Dragon>(s)){
		theFloor[info[1]][info[2]] = make_shared<Empty>(\
			info[0],info[1],info[2]);
	
	}else if  (dynamic_pointer_cast<Human>(s){
               theFloor[info[1]][info[2]] = make_shared<Treasure>(\
                        info[0],info[1],info[2],4, false ));

	}else if( dynamic_pointer_cast<Merchant>(s){
               theFloor[info[1]][info[2]] = make_shared<Treasure>(\
                        info[0],info[1],info[2],4, false ));		
	}else{ //others
		int val = rand % 2 + 1;
		theFloor[info[1]][info[2]] = make_shared<Treasure>(\
			info[0],info[1],info[2],val, false ));
		PC->use(theFloor[info[1]][info[2]]);
		theFloor[info[1]][info[2]] = make_shared<Empty>(info[0],info[1]\
			info[2]));
	}
}

Subtype Floor::subtype(){
	return SubType::FLOOR;
}

ostream &operator<<(ostream &out, const Floor &f){
	string s;
	info o = f.pc->getinfo();
	for ( int i = 0; i < board_row ; i++){
		for ( int j = 0; j < board_col; j++){
			if ( f.theFloor[i][j] == nullptr ) {
				out << " ";
			}else{
				out<<  f.theFloor[i][j]->getRep();
			}
		}
		out <<"\n";
	}
	out <<"\n";
	s = s + "Race: " + o.name + " Gold: " + to_string(o.gold);
	int spaces = 70;
	spaces = spaces - strlen(s) - 1;
	for ( int i = 0; i < spaces; i++){
		s = s + " ";
	}
	s  = s + "Floor " + to_string(floorNum);
	out << s;
	out << "\n";
	out <<"HP: ";
	out << o.hp;
	out <<"\n";
	out <<"ATK: ";
	out << o.atk;
	out <<"\n";
	out <<"DEF: ";
	out << o.def;
	out <<"\n";
	out <<"Action: ";
	out << f.action;
	out <<"\n";
	out <<"\n";
	return out;
}
