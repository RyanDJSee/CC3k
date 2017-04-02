#include <iostream>
#include "game.h"
#include "RESTART.h"
#include "INVCOMMAND.h"
#include <string>
using namespace std;


int main(int argc, char* argv[]) {// need to add args
  cin.exceptions(ios::eofbit|ios::failbit);

  try{
    Game g;
    string cmd;
    string filename="";

    while (true) {
      try{
        cin>>cmd;

        if (cmd == "q") {
          return 0;//terminate

        } else if (cmd == "s" || cmd == "d" ||
        cmd == "v" || cmd == "g" ||cmd == "t"){
          //check if there is an input floor
          if(argc>1) {
            filename=argv[1];
          }
#ifdef D
          cout<<"gameinit"<<endl;
#endif
          g.GameInit(cmd, filename); //creates first floor and enemies
          while (true) {
            try{
              cin>>cmd;

              if ( cmd == "no" || cmd == "so" || cmd == "ea" || cmd == "we"
              || cmd == "ne" || cmd == "nw" || cmd == "sw" ) {
                g.MoveChar(cmd);
              } else if ( cmd == "u" ) {
                cin >> cmd;//direction
                //check direction is valid
                if( cmd == "no" || cmd == "so" || cmd == "ea" || cmd == "we"
                || cmd == "ne" || cmd == "nw" || cmd == "sw" ) {
                  g.UsePotion(cmd);
                } else {//not dir
                  throw INVCOMMAND();
                }
              } else if ( cmd == "a" ) {
                cin >> cmd;//direction
                //check direction is valid
                if( cmd == "no" || cmd == "so" || cmd == "ea" || cmd == "we"
                || cmd == "ne" || cmd == "nw" || cmd == "sw" ) {
                  g.Attack(cmd);
                } else {//not dir
                  throw INVCOMMAND();
                }
              } else if ( cmd == "f" ) {//stops
                g.EnemySwitch();
              } else if ( cmd == "r" ) {//restarts
                throw RESTART();
              } else if (cmd == "q") {
                return 0;//terminate
              }//else ignore
            } catch(...){
#ifdef D
              cout<<cmd<<"invalid"<<endl;
              throw;
#endif
            }//ignore invalid input
          }
        }
      } //else ignore
      catch (RESTART &re) {
#ifdef D
        throw;
#endif
      }//continue (before game)
    }
  } catch (...) {
#ifdef D
    throw;
#endif
  }//return 0; }
}
