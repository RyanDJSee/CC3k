#include <iostream>
using namespace std;

class RESTART;

int main(int argc, char* argv[]) {// need to add args
  cin.exceptions(ios::eofbit|ios::failbit);

  try{
    game g;
    string cmd;
    string filename="";

    while (true) {
      cin>>cmd;

      if (cmd == "q") {
        return 0;//terminate

      } else if (cmd == "s" || cmd == "d" ||
      cmd == "v" || cmd == "g" ||cmd == "t"){
        //check if there is an input floor
        if(argc>1) {
          filename=argv[1];
        }
        GameInit(cmd, filename); //creates first floor and enemies
        while (true) {
          cin>>cmd;

          if ( cmd == "no" || cmd == "so" || cmd == "ea" || cmd == "we"
          || cmd == "ne" || cmd == "nw" || cmd == "sw" ) {
            MoveChar(cmd);
          } else if ( cmd == "u" ) {
            cin >> cmd;//direction
            //check direction is valid
            UsePotion(cmd);
          } else if ( cmd == "a" ) {
            cin >> cmd;//direction
            //check direction is valid
            Attack(cmd);
          } else if ( cmd == "f" ) {//stops
            EnemySwitch();
          } else if ( cmd == "r" ) {//restarts
            throw RESTART();
          } else if (cmd == "q") {
            return 0;//terminate
          }//else ignore
          catch(...){}//ignore invalid input
        }
      } //else ignore
      catch (RESTART &re) {}//continue (before game)
    } catch (...) { return 0; }
  }
