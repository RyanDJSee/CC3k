#include <iostream>
#include <memory>
#include <string>
#include <string.h>
#include <fstream>
#include <time.h>

#include "cell.h"
#include "floor.h"
#include "wall.h"
#include "passage.h"
#include "empty.h"
#include "stair.h"
#include "door.h"


#include "pc.h"
#include "shade.h"
#include "goblin.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"

#include "enemy.h"
#include "human.h"
#include "dwarf.h"
#include "halfling.h"
#include "elf.h"
#include "orc.h"
#include "merchant.h"
#include "dragon.h"

#include "item.h"
#include "potion.h"
#include "rh.h"
#include "ba.h"
#include "bd.h"
#include "ph.h"
#include "wa.h"
#include "wd.h"

#include "treasure.h"
using namespace std;

//Floor::Floor(){}

Floor::~Floor(){}

Floor::Floor(int floorNum, shared_ptr<Cell> pc): floorNum{floorNum}, pc{pc}{
  #ifdef D
  if(!pc){
    cout<<"nullptr"<<endl;
  } else{
    ;
  }
  #endif
  prevCell=shared_ptr<Cell> {new Empty(pc->getPos()[0],pc->getPos()[1],pc->getPos()[2])};
}

void Floor::FloorInit1(string filename) {
  auto f=shared_from_this();
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
    theDim.push_back(C1);
    theDim.push_back(C2);
    theDim.push_back(C3);
    theDim.push_back(C4);
    theDim.push_back(C5);


    //initilize the board:
    #ifdef D
    cout<<"initilize the board board_col is "<<board_col<<endl;
    #endif
    vector <shared_ptr <Cell> > temp;
    for ( int i = 0 ; i < board_col ; i++){
      #ifdef D2
      cout<<"push back some shared_ptrcell"<<i<<endl;
      #endif
      //shared_ptr<Cell> cel;
      //auto cel=make_shared<Empty>{-1,-1,-1};
      temp.push_back(nullptr);
    }
    for ( int j = 0; j < board_row ; j++){
      #ifdef D2
      cout<<"push back some row"<<j<<endl;
      #endif
      theFloor.push_back(temp);
    }
    #ifdef D
    cout<<"build wall"<<endl;
    #endif
    Build_Wall(0, 0, board_col - 1,0);
    Build_Wall(board_row -1, 0, board_col - 1,0);
    for (int i = 1; i < board_row -1; i++){
      Build_Wall(i,0,0,0);
      Build_Wall(i,board_col-1,board_col-1,0);
    }



    //Building first chamber
    #ifdef D
    cout<<"Building first chamber"<<endl;
    #endif
    int rowChamber1_start = 2;
    int rowChamber1_end = 7;
    int colChamber1_start = 2;
    int colChamber1_end = 29;
    for ( int i = rowChamber1_start; i <= rowChamber1_end ; i++){
      #ifdef D2
      cout<<"loop"<<i<<endl;
      #endif
      if (i == rowChamber1_start || i == rowChamber1_end){
        #ifdef D2
        cout<<"loop"<<i<<"start wall"<<endl;
        #endif
        Build_Wall(i, colChamber1_start, colChamber1_end, 1);
        #ifdef D2
        cout<<"loop"<<i<<"done wall"<<endl;
        #endif
      }else{
        #ifdef D
        cout<<"try build room"<<endl;
        #endif
        Build_Room(i, colChamber1_start, colChamber1_end, 1);
        #ifdef D
        cout<<"done room"<<endl;
        #endif
      }
    }
    theFloor[4][29]= shared_ptr<Cell> {new Door(1,4,29)};
    theFloor[4][29]->setPos(4,29,1);
    theFloor[4][29]->attach(shared_from_this());
    theFloor[7][13] = shared_ptr<Cell> {new Door(1,7,13)};
    theFloor[7][13]->setPos(7,13,1);
    theFloor[7][13]->attach(shared_from_this());

    //Building second Chamber
    #ifdef D
    cout<<"Building second chamber"<<board_col<<endl;
    #endif
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
    theFloor[9][43] = shared_ptr<Cell> {new Door(2,9, 43)};
    theFloor[9][43]->setPos(9,43,2);
    theFloor[9][43]->attach(shared_from_this());
    theFloor[13][43] = shared_ptr<Cell> {new Door(2,13,43)};
    theFloor[13][43]->setPos(13,43,2);
    theFloor[13][43]->attach(shared_from_this());

    //Building third Chamber
    #ifdef D
    cout<<"Building third chamber"<<endl;
    #endif
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
    #ifdef D
    cout<<"try works?"<<endl;
    #endif
    theFloor[14][13] = shared_ptr<Cell> {new Door(3,14,13)};
    #ifdef D
    cout<<"works?"<<endl;
    #endif
    theFloor[14][13]->setPos(14,13,3);
    theFloor[14][13]->attach(shared_from_this());
    theFloor[20][25] = make_shared<Door>(3, 20, 25);
    #ifdef D
    cout<<"makeshare?"<<endl;
    #endif
    theFloor[20][25]->setPos(20,25,3);
    theFloor[20][25]->attach(shared_from_this());

    //Building fourth Chamber
    #ifdef D
    cout<<"Building 4 chamber"<<endl;
    #endif
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
    theFloor[13][69]->attach(shared_from_this());
    theFloor[4][38] = make_shared<Door>(4, 4, 38);
    theFloor[4][38]->setPos(4,38,4);
    theFloor[4][38]->attach(shared_from_this());

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
    theFloor[18][43] = make_shared<Door>(5,18,43);
    theFloor[18][43]->setPos(18,43,5);
    theFloor[18][43]->attach(shared_from_this());
    theFloor[20][36] = make_shared<Door>(5, 20, 36);
    theFloor[20][36]->setPos(20,36,5);
    theFloor[20][36]->attach(shared_from_this());

    //Building board passage between CHAMBER
    #ifdef D
    cout<<"passage?"<<endl;
    #endif
    Build_Passage(4, 30, 8, "verti"); //between 1 & 4
    #ifdef D
    cout<<"done 1 p"<<endl;
    #endif
    Build_Passage(8, 31, 13 , "verti");
    Build_Passage(11, 13, 19, "verti");
    Build_Passage(11, 54, 6, "verti");
    Build_Passage(16, 31, 24, "verti");
    Build_Passage(20, 26, 10, "verti");
    #ifdef D
    cout<<"done all v"<<endl;
    #endif
    Build_Passage(5, 33, 3, "hori");
    #ifdef D
    cout<<"done 1 vp"<<endl;
    #endif
    Build_Passage(8, 13, 6, "hori");
    Build_Passage(8, 31, 12, "hori");
    Build_Passage(14, 43, 4, "hori");
    #ifdef D
    cout<<"done 3 h"<<endl;
    #endif
    Build_Passage(11, 54, 6, "hori");
    Build_Passage(14,69, 1, "hori");
  }else{
    floor_given(filename);
  }
  #ifdef D
  cout<<"done init1"<<endl;
  #endif
}

void Floor::Build_Passage(int row, int col , int counter, string direction){
  #ifdef D
  cout<<"enter build passage"<<endl;
  #endif
  for ( int i = 0 ; i< counter ; i++){
    #ifdef D2
    cout<<"loop "<<i<<endl;
    #endif
    if (direction == "hori"){
      theFloor[row+i][col]=  make_shared<Passage>(0, row+i, col);
      theFloor[row+i][col]->setPos(row+i, col,0);
      theFloor[row+i][col]->attach(shared_from_this());
    }else if (direction =="verti"){
      theFloor[row][col+i] = make_shared<Passage>(0, row, col + i);
      theFloor[row][col+i]->setPos(row, col+i,0);
      theFloor[row][col+i]->attach(shared_from_this());
    }
  }
}

void Floor::Build_Wall(int row, int start, int end, int chamber){
  #ifdef D
  cout<<"inside build wall"<<endl;
  #endif
  auto f=shared_from_this();
  #ifdef D2
  cout<<"inside build wall shared?"<<endl;
  #endif
  //shared_ptr<Cell> n1{new Wall(chamber, row, start, "|")};
  theFloor[row][start] = shared_ptr<Cell> {new Wall(chamber, row, start, "|")};
  //shared_ptr<Cell> n2{new Wall(chamber, row, end, "|")};
  theFloor[row][end] = shared_ptr<Cell> {new Wall(chamber, row, end, "|")};
  #ifdef D2
  cout<<"inside build wall2"<<endl<<"end is "<<end<<endl;
  #endif
  for ( int i = start + 1; i < end ; i ++){
    #ifdef D2
    cout<<"inside build wall loop"<<i<<endl<<"start is "<<start<<"end is "<<end<<endl;
    #endif
    shared_ptr<Cell> n{new Wall(chamber, row , i , "-")};
    theFloor[row][i] = n;
    #ifdef D2
    cout<<"inside build wall loop"<<i<<endl;
    #endif
    theFloor[row][i]->setPos(row, i,chamber);
    theFloor[row][i]->attach(f);
    #ifdef D2
    cout<<"inside build wall"<<i<<endl;
    #endif
  }
}

void Floor::Build_Room(int row, int start, int end,int chamber){
  //shared_ptr<Cell> n1{new Wall(chamber, row, start, "|")};
  theFloor[row][start] = shared_ptr<Cell> {new Wall(chamber, row, start, "|")};
  //shared_ptr<Cell> n2{new Wall(chamber, row, end, "|")};
  theFloor[row][end] = shared_ptr<Cell> {new Wall(chamber, row, end, "|")};
  for ( int i = start + 1; i < end; i++){
    shared_ptr<Cell> n{new Empty(chamber, row, i)};
    theFloor[row][i] = n;
    theFloor[row][i]->setPos(row, i,chamber);
    theFloor[row][i]->attach(shared_from_this());
  }
}

void Floor::floor_given(string filename){
  ifstream fin{filename};
  char s;
  int row = 0;
  int col = 0;
  while (fin.get(s)){
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
      theFloor[row][col] = make_shared<Halfling>(0, row, col);
    }else if( s == 'O'){
      theFloor[row][col] = make_shared<Orc>(0, row, col);
    }else if (s == 'D'){
      theFloor[row][col] = make_shared<Dragon>(0, row, col);
    }else if( s == 'E'){
      theFloor[row][col] = make_shared<Elf>(0, row, col);
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
      theFloor[row][col] = make_shared<Treasure>(0, row, col, 2);//, false
    }else if ( s == '7'){
      theFloor[row][col] = make_shared<Treasure>(0, row, col, 1);//, false
    }else if ( s == '8'){
      theFloor[row][col] = make_shared<Treasure>(0, row, col, 4);//, false
    }else if ( s == '9'){
      theFloor[row][col] = make_shared<Treasure>(0, row, col, 6);//, true
    }
    theFloor[row][col]->setPos(row,col, 0);
    theFloor[row][col]->attach(shared_from_this() );
    col++;
  }
}

void Floor::FloorInit(){
  #ifdef D
  cout<<"enter floorinit"<<endl;
  #endif
  //init pc
  vector<int> pos = getRandomPos();
  #ifdef D
  cout<<"pos is "<<pos[0]<<pos[1]<<pos[2]<<endl;
  #endif
  subject_init(pos[0], pos[1], pos[2], "PC");
  attach_chamber(theFloor[pos[1]][pos[2]],pos[0], pos[1], pos[2]);
  #ifdef D
  cout<<"done pc "<<endl;
  #endif

  //init stairway
  pos = getRandomPos();
  subject_init(pos[0], pos[1], pos[2], "STAIR");
  // init POTIONS
  #ifdef D
  cout<<"start potion"<<endl;
  #endif
  for ( int i = 0; i < 10 ; i++){
    pos = getRandomPos();
    #ifdef D
    cout<<"pos is"<<pos[0]<<" "<<pos[1]<<" "<<pos[2]<<endl;
    #endif
    subject_init(pos[0], pos[1], pos[2], "POTIONS");
  }
  // init GOLD
  #ifdef D
  cout<<"start gold"<<endl;
  #endif
  for ( int i = 0; i < 10; i++){
    pos = getRandomPos();
    subject_init(pos[0], pos[1], pos[2], "GOLD");
  }
  // init ENERMY
  #ifdef D
  cout<<"start enermy"<<endl;
  #endif
  for ( int i = 0; i < 20; i++){
    pos = getRandomPos();
    subject_init(pos[0], pos[1], pos[2], "ENERMY");
  }
}

void Floor::subject_init(int chamber, int row, int col,string type){
  #ifdef D
  cout<<"enter subject_init "<<endl;
  #endif
  if ( type == "PC"){
    #ifdef D
    cout<<"pc: row col: "<<row<<" "<<col<<endl;
    #endif
    theFloor[row][col]  = shared_ptr<Cell> {pc};
    #ifdef D
    cout<<"inside subject_init done pc"<<endl;
    #endif
    pc_row = row;
    pc_col = col;
  }else if ( type == "STAIR"){
    theFloor[row][col] = make_shared<Stair>(chamber, row, col);
  }else if ( type == "POTIONS"){
    int potion_type = rand() % 6 + 1 ;
    if ( potion_type == 1){
      theFloor[row][col] = shared_ptr<RH>{ new RH(chamber, row,col)};
    }else if ( potion_type == 2){
      theFloor[row][col] = shared_ptr<BA>{ new BA(chamber, row, col)};
    }else if( potion_type == 3){
      theFloor[row][col] = shared_ptr<BD>{ new BD(chamber, row, col)};
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
      theFloor[row][col] = make_shared<Treasure>(chamber, row, col, 2);//, false
    }else if (gold_type == 6){ //dragon hoard
      theFloor[row][col] = make_shared<Treasure>(chamber, row, col, 6);//, true
      summon_dragon(chamber, row,col);
    }else{ // small hoard
      theFloor[row][col] = make_shared<Treasure>(chamber, row, col, 1);//, false
    }
  }else {//type == "ENERMY"
  int enermy_type = rand() % 18 + 1;
  if ( enermy_type <= 4 ){ //human
    theFloor[row][col] = make_shared<Human>(chamber, row, col);
  } else if ( enermy_type <= 7){ // Dwarf
    theFloor[row][col] = make_shared<Dwarf>(chamber, row, col);
  } else if (enermy_type <= 12){ // Hafling
    theFloor[row][col] = make_shared<Halfling>(chamber, row, col);
  } else if (enermy_type <= 14){ // Elf
    theFloor[row][col] = make_shared<Elf>(chamber, row, col);
  } else if (enermy_type <= 16){ // Orc
    theFloor[row][col] = make_shared<Orc>(chamber, row, col);
  }else{ //Merchant
    theFloor[row][col] = make_shared<Merchant>(chamber, row, col);
  }
}
#ifdef D
cout<<"setpos row col"<<row<<" "<<col<<endl;
#endif
#ifdef D
cout<<"the floor size "<<theFloor.size()<<" "<<theFloor[19].size()<<endl;
#endif
theFloor[row][col]->setPos(row,col,chamber);
#ifdef D
cout<<"done subject_init "<<endl;
#endif
}



vector<int> Floor::check_tile(int row, int col){
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
    temp.push_back(col);
    xy.push_back(temp);
  }
  if ( theFloor[row-1][col+1]->isEmpty()){
    tile++;
    temp.clear();
    temp.push_back(row-1);
    temp.push_back(col+1);
    xy.push_back(temp);
  }
  if ( theFloor[row][col-1]->isEmpty()){
    tile++;
    temp.clear();
    temp.push_back(row);
    temp.push_back(col-1);
    xy.push_back(temp);
  }
  if ( theFloor[row][col+1]->isEmpty()){
    tile++;
    temp.clear();
    temp.push_back(row);
    temp.push_back(col+1);
    xy.push_back(temp);
  }
  if ( theFloor[row+1][col-1]->isEmpty()){
    tile++;
    temp.clear();
    temp.push_back(row+1);
    temp.push_back(col-1);
    xy.push_back(temp);
  }
  if ( theFloor[row+1][col]->isEmpty()){
    tile++;
    temp.clear();
    temp.push_back(row+1);
    temp.push_back(col);
    xy.push_back(temp);
  }
  if ( theFloor[row+1][col+1]->isEmpty()){
    tile++;
    temp.clear();
    temp.push_back(row+1);
    temp.push_back(col+1);
    xy.push_back(temp);
  }
  int ran = rand() % tile;
  temp = xy[ran];
  return temp;
}

void Floor::summon_dragon(int chamber, int row, int col){
  vector<int> temp = check_tile(row, col);
  int pos_row = temp[0];
  int pos_col = temp[1];
  theFloor[pos_row][pos_col] = make_shared<Dragon>(chamber, pos_row, pos_col);//,theFloor[row][col]
  theFloor[pos_row][pos_col]->attach(theFloor[row][col]);
  theFloor[pos_row][pos_col]->setPos(pos_row, pos_col,chamber);
  theFloor[row][col]->attach(theFloor[pos_row][pos_col]);
}


void Floor::attach_chamber(shared_ptr<Cell> c, int chamber, int row, int col){
  if(theFloor[row-1][col-1])  c->attach(theFloor[row-1][col-1]);
  if(theFloor[row-1][col]) c->attach(theFloor[row-1][col]);
  if(theFloor[row-1][col+1]) c->attach(theFloor[row-1][col+1]);
  if(theFloor[row][col-1]) c->attach(theFloor[row][col-1]);
  if(theFloor[row][col+1]) c->attach(theFloor[row][col+1]);
  if(theFloor[row+1][col-1]) c->attach(theFloor[row+1][col-1]);
  if(theFloor[row+1][col]) c->attach(theFloor[row+1][col]);
  if(theFloor[row+1][col+1]) c->attach(theFloor[row+1][col+1]);
}

void Floor::FloorMove(string direction){
  #ifdef D
  cout<<"start floor move"<<endl;
  #endif
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

  if(theFloor[new_row][new_col] && \
    theFloor[new_row][new_col]->Steppable() != StepType::CantStep){
      vector<int> info = theFloor[current_row][current_col]->getPos();
      int chamber = info[0];
      pc_row = new_row;
      pc_col = new_col;
      //condition

      #ifdef D2
      cout<<"done getpos"<<endl;
      #endif

      #ifdef D2
      cout<<"not can't step"<<endl;
      #endif
      pc->dettachall();
      theFloor[current_row][current_col] = prevCell;

      #ifdef D2
      if(!prevCell){
        cout<<"prevCell is nullptr"<<endl;
      } else {
        cout<<"prevCell is not nullptr"<<endl;
      }
      cout<<"newrow, newcol, currrow, currcol"<<new_row<<" "<<new_col<<" "<<current_row<<" "<<current_col<<" "<<endl;
      #endif
      prevCell = theFloor[new_row][new_col];
      if ( theFloor[new_row][new_col]->Steppable() == StepType::PickUp){
        #ifdef D2
        cout<<"pickup"<<endl;
        #endif
        if (prevCell->isEmpty() == false){
          #ifdef D2
          cout<<"not empty"<<endl;
          #endif
          shared_ptr<Item> potion=dynamic_pointer_cast<Item>(prevCell);
          pc->use(potion);
          prevCell = make_shared<Empty>(chamber, current_row, current_col);
        }
      }
      theFloor[new_row][new_col] = pc;
      attach_chamber(theFloor[new_row][new_col], chamber, new_row, new_col);
      #ifdef D2
      cout<<"done attach_chamber"<<endl;
      #endif
      theFloor[new_row][new_col]->setPos(new_row, new_col,chamber);
      #ifdef D2
      cout<<"done setPos"<<endl;
      cout<<*shared_from_this()<<endl;
      #endif
      //	theFloor[new_row][new_col]->attach(theFloor[new_row][new_col]->subtype());

      pc->notifyObservers( SubType::CELL );
      #ifdef D
      cout<<"done notifyObservers"<<endl;
      #endif

      //change enemy status
      if((dynamic_pointer_cast<BA>(theFloor[new_row-1][new_col-1])&&(!BA::wasUsed))
      || (dynamic_pointer_cast<BD>(theFloor[new_row-1][new_col-1])&&(!BD::wasUsed))
      || (dynamic_pointer_cast<PH>(theFloor[new_row-1][new_col-1])&&(!PH::wasUsed))
      || (dynamic_pointer_cast<RH>(theFloor[new_row-1][new_col-1])&&(!RH::wasUsed))
      || (dynamic_pointer_cast<WA>(theFloor[new_row-1][new_col-1])&&(!WA::wasUsed))
      || (dynamic_pointer_cast<WD>(theFloor[new_row-1][new_col-1])&&(!WD::wasUsed))

      || (dynamic_pointer_cast<BA>(theFloor[new_row-1][new_col+1])&&(!BA::wasUsed))
      || (dynamic_pointer_cast<BD>(theFloor[new_row-1][new_col+1])&&(!BD::wasUsed))
      || (dynamic_pointer_cast<PH>(theFloor[new_row-1][new_col+1])&&(!PH::wasUsed))
      || (dynamic_pointer_cast<RH>(theFloor[new_row-1][new_col+1])&&(!RH::wasUsed))
      || (dynamic_pointer_cast<WA>(theFloor[new_row-1][new_col+1])&&(!WA::wasUsed))
      || (dynamic_pointer_cast<WD>(theFloor[new_row-1][new_col+1])&&(!WD::wasUsed))

      || (dynamic_pointer_cast<BA>(theFloor[new_row-1][new_col])&&(!BA::wasUsed))
      || (dynamic_pointer_cast<BD>(theFloor[new_row-1][new_col])&&(!BD::wasUsed))
      || (dynamic_pointer_cast<PH>(theFloor[new_row-1][new_col])&&(!PH::wasUsed))
      || (dynamic_pointer_cast<RH>(theFloor[new_row-1][new_col])&&(!RH::wasUsed))
      || (dynamic_pointer_cast<WA>(theFloor[new_row-1][new_col])&&(!WA::wasUsed))
      || (dynamic_pointer_cast<WD>(theFloor[new_row-1][new_col])&&(!WD::wasUsed))

      || (dynamic_pointer_cast<BA>(theFloor[new_row][new_col-1])&&(!BA::wasUsed))
      || (dynamic_pointer_cast<BD>(theFloor[new_row][new_col-1])&&(!BD::wasUsed))
      || (dynamic_pointer_cast<PH>(theFloor[new_row][new_col-1])&&(!PH::wasUsed))
      || (dynamic_pointer_cast<RH>(theFloor[new_row][new_col-1])&&(!RH::wasUsed))
      || (dynamic_pointer_cast<WA>(theFloor[new_row][new_col-1])&&(!WA::wasUsed))
      || (dynamic_pointer_cast<WD>(theFloor[new_row][new_col-1])&&(!WD::wasUsed))

      || (dynamic_pointer_cast<BA>(theFloor[new_row][new_col+1])&&(!BA::wasUsed))
      || (dynamic_pointer_cast<BD>(theFloor[new_row][new_col+1])&&(!BD::wasUsed))
      || (dynamic_pointer_cast<PH>(theFloor[new_row][new_col+1])&&(!PH::wasUsed))
      || (dynamic_pointer_cast<RH>(theFloor[new_row][new_col+1])&&(!RH::wasUsed))
      || (dynamic_pointer_cast<WA>(theFloor[new_row][new_col+1])&&(!WA::wasUsed))
      || (dynamic_pointer_cast<WD>(theFloor[new_row][new_col+1])&&(!WD::wasUsed))

      || (dynamic_pointer_cast<BA>(theFloor[new_row+1][new_col-1])&&(!BA::wasUsed))
      || (dynamic_pointer_cast<BD>(theFloor[new_row+1][new_col-1])&&(!BD::wasUsed))
      || (dynamic_pointer_cast<PH>(theFloor[new_row+1][new_col-1])&&(!PH::wasUsed))
      || (dynamic_pointer_cast<RH>(theFloor[new_row+1][new_col-1])&&(!RH::wasUsed))
      || (dynamic_pointer_cast<WA>(theFloor[new_row+1][new_col-1])&&(!WA::wasUsed))
      || (dynamic_pointer_cast<WD>(theFloor[new_row+1][new_col-1])&&(!WD::wasUsed))

      || (dynamic_pointer_cast<BA>(theFloor[new_row+1][new_col])&&(!BA::wasUsed))
      || (dynamic_pointer_cast<BD>(theFloor[new_row+1][new_col])&&(!BD::wasUsed))
      || (dynamic_pointer_cast<PH>(theFloor[new_row+1][new_col])&&(!PH::wasUsed))
      || (dynamic_pointer_cast<RH>(theFloor[new_row+1][new_col])&&(!RH::wasUsed))
      || (dynamic_pointer_cast<WA>(theFloor[new_row+1][new_col])&&(!WA::wasUsed))
      || (dynamic_pointer_cast<WD>(theFloor[new_row+1][new_col])&&(!WD::wasUsed))

      || (dynamic_pointer_cast<BA>(theFloor[new_row+1][new_col+1])&&(!BA::wasUsed))
      || (dynamic_pointer_cast<BD>(theFloor[new_row+1][new_col+1])&&(!BD::wasUsed))
      || (dynamic_pointer_cast<PH>(theFloor[new_row+1][new_col+1])&&(!PH::wasUsed))
      || (dynamic_pointer_cast<RH>(theFloor[new_row+1][new_col+1])&&(!RH::wasUsed))
      || (dynamic_pointer_cast<WA>(theFloor[new_row+1][new_col+1])&&(!WA::wasUsed))
      || (dynamic_pointer_cast<WD>(theFloor[new_row+1][new_col+1])&&(!WD::wasUsed))){
        addaction("sees an unknown potion");
      }



      action = "PC move to " + action + ".";

      //ENERMY
      #ifdef D
      cout<<"enemy move"<<endl;
      #endif
      if ( freeze == false ){
        enermy_move();
      }
      #ifdef D
      cout<<"done enemy move"<<endl;
      #endif
    }
  }

  void Floor::clearaction(){
    action = "";
  }

  void Floor::enermy_move(){
    for ( int i = 0; i < board_row ; i++){
      for ( int j = 0; j < board_col ; j++){
        if (dynamic_pointer_cast<Enemy>(theFloor[i][j]) && //it is an enermy
        theFloor[i][j]->Moved() == false ){

          #ifdef D2
          cout<<"is enemy at "<<i<<" "<<j<<endl;
          #endif
          int count = 0;
          vector<int> temp = check_tile(i, j);
          int new_row = temp[0];
          int new_col = temp[1];
          #ifdef D2
          cout<<"done check_tile "<<new_row<<" "<<new_col<<" "<<endl;
          #endif
          vector <int> info = theFloor[i][j]->getPos();
          #ifdef D2
          cout<<"done getpos"<<endl;
          #endif
          shared_ptr<Cell> temp2 = theFloor[new_row][new_col];
          theFloor[new_row][new_col] = theFloor[i][j];
          theFloor[new_row][new_col]->setPos(new_row, new_col,info[0]);
          theFloor[i][j] = temp2;
          theFloor[new_row][new_col]->setMoved(true);
        }
      }
    }
    for ( int i = 0; i < board_row ; i++){
      for ( int j = 0; j <board_col; j++){
        if (theFloor[i][j]){
          #ifdef D2
          cout<<"done getpos"<<endl;
          #endif
          theFloor[i][j]->setMoved(false);
        }
      }

    }
  }




  vector<int> Floor::getRandomPos(){
    #ifdef D
    cout<<"enter getrampos"<<endl;
    #endif
    vector <int> result;
    int row = 0;
    int col = 0;
    int chamber = 0;
    while ( dynamic_pointer_cast<Wall>(theFloor[row][col]) ){
      #ifdef D2
      cout<<"row and col"<<row<<"&"<<col<<endl;
      #endif
      //  srand(time(NULL));
      chamber = rand() % 5; // which chamber?
      #ifdef D
      cout<<"chamber"<<chamber<<endl;
      cout<<"thedim size"<<theDim.size()<<endl;
      #endif
      int c_size = theDim[chamber].size(); //how many row in the chamber?
      #ifdef D2
      cout<<"size"<<endl;
      #endif
      // srand(time(NULL));
      int line = rand() % c_size; // which row in the selected chamber?
      #ifdef D2
      cout<<"line"<<endl;
      #endif
      // srand(time(NULL));
      int block = rand() % theDim[chamber][line]; // which col is the selected chamber?
      #ifdef D2
      cout<<"block"<<endl;
      #endif
      int row_start;
      int col_start;
      #ifdef D
      cout<<"c_size, line, block"<<c_size<<" "<<line<<" "<<block<<endl;
      #endif
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
          row_start = 3;
          col_start = 61;
        }
      }else if ( chamber == 4){ //fifth chamber
        if ( line <= 2){
          row_start = 16;
          col_start = 65;
        }else{
          row_start = 16;
          col_start = 37;
        }
      }
      int row_operate = row_start + line;
      int col_operate = col_start + block;
      #ifdef D2
      cout<<"chamber, row col operate"<<chamber<<"&"<<row_operate<<"&"<<col_operate<<endl;
      #endif
      if (theFloor[row_operate][col_operate]->isEmpty()){
        row = row_operate;
        col = col_operate;
      }
    }
    result.push_back(chamber);
    result.push_back(row);
    result.push_back(col);

    return result;
    #ifdef D
    cout<<"DONE getrampos"<<endl;
    #endif
  }


  void Floor::EnermySwitch(){
    if (freeze == false){
      freeze = true;
    }else if ( freeze == true){
      freeze = false;
    }
  }

  void Floor::attack(string direction){
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
    if( dynamic_pointer_cast<Enemy>(theFloor[new_row][new_col]) ){
      //n->attackedBy(pc);
      auto n= dynamic_pointer_cast<Subject>(theFloor[new_row][new_col]);
      pc->notify(n);
      pc->notifyObservers( SubType::CELL );
    }
  }

  void Floor::UsePotion(string direction){
    vector<int> info = pc->getPos();
    #ifdef D
    cout<<"inside usepotion pos:"<<info[0]<<" "<<info[1]<<" "<<info[2]<<" "<<endl;
    #endif
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
    #ifdef D
    cout<<"inside usepotion before checking, pos:"<<new_row<<" "<<new_col<<" "<<new_chamber<<endl;
    #endif
    if (auto n=dynamic_pointer_cast<Item>(theFloor[new_row][new_col]) ){
      #ifdef D
      cout<<"inside usepotion is item"<<endl;
      #endif
      if (auto n=dynamic_pointer_cast<RH>(theFloor[new_row][new_col]) ){
        RH::wasUsed=true;
        addaction("uses RH");
        #ifdef D
        cout<<"inside usepotion rh"<<endl;
        #endif
      } else if (auto n=dynamic_pointer_cast<BA>(theFloor[new_row][new_col]) ){
        BA::wasUsed=true;
        addaction("uses BA");
        #ifdef D
        cout<<"inside usepotion ba"<<endl;
        #endif
      }else if (auto n=dynamic_pointer_cast<BD>(theFloor[new_row][new_col]) ){
        BD::wasUsed=true;
        addaction("uses BD");
        #ifdef D
        cout<<"inside usepotion bd"<<endl;
        #endif
      }else if (auto n=dynamic_pointer_cast<PH>(theFloor[new_row][new_col]) ){
        PH::wasUsed=true;
        addaction("uses PH");
        #ifdef D
        cout<<"inside usepotion ph"<<endl;
        #endif
      }else if (auto n=dynamic_pointer_cast<WA>(theFloor[new_row][new_col]) ){
        WA::wasUsed=true;
        addaction("uses WA");
        #ifdef D
        cout<<"inside usepotion wa"<<endl;
        #endif
      }else if (auto n=dynamic_pointer_cast<WD>(theFloor[new_row][new_col]) ){
        WD::wasUsed=true;
        addaction("uses WD");
        #ifdef D
        cout<<"inside usepotion wd"<<endl;
        #endif
      }

      #ifdef D
      if (auto n=dynamic_pointer_cast<Treasure>(theFloor[new_row][new_col])){
        cout<<"potion is treasure"<<endl;
      }

      cout<<"inside usepotion ready to use"<<endl;
      #endif

      pc->use(n);
      #ifdef D
      cout<<"inside usepotion done using"<<endl;
      #endif
    }
  }

  void Floor::addaction(string action2){
    action = action +", and "+ action2;
  }

  void Floor::notify(shared_ptr<Subject> &s){
    ///when enermy died
    vector<int> info = s->getPos();
    //for dragon human merchant
    if ( theFloor[info[1]][info[2]]->getRep() == "G" ) {
      theFloor[info[1]][info[2]] = make_shared<Empty>(info[0],info[1],info[2]);

    }else if  ( theFloor[info[1]][info[2]]->getRep() == "H" ){
      theFloor[info[1]][info[2]] = make_shared<Treasure>(info[0],info[1],info[2],4);// false

    }else if(theFloor[info[1]][info[2]]->getRep() =="M" ){
      theFloor[info[1]][info[2]] = make_shared<Treasure>(info[0],info[1],info[2],4);//, false
    }else{ //others
      int val = rand() % 2 + 1;
      theFloor[info[1]][info[2]] = make_shared<Treasure>(info[0],info[1],info[2],val);//, false
      if (auto t=dynamic_pointer_cast<Item>(theFloor[info[1]][info[2]])){
        pc->use(t);
      }
      theFloor[info[1]][info[2]] = make_shared<Empty>(info[0],info[1],info[2]);
    }
  }

  SubType Floor::subtype() const{
    return SubType::FLOOR;
  }

  ostream &operator<<(ostream &out, const Floor &f){
    string s;
    Info o = f.pc->getInfo();
    for ( int i = 0; i < f.board_row ; i++){
      for ( int j = 0; j < f.board_col; j++){
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
    spaces = spaces - s.length() - 1;
    for ( int i = 0; i < spaces; i++){
      s = s + " ";
    }
    s  = s + "Floor " + to_string(f.floorNum);
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
