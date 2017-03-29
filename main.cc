#include <iostream>
using namespace std;

class RESTART;

int main() {// need to add args
  cin.exceptions(ios::eofbit|ios::failbit);

  try{
    game g;
    string cmd;

    while (true) {
      cin>>cmd;

      if (cmd == "q") {
        return 0;//terminate

      }else if (cmd == "s" || cmd == "d" ||
      cmd == "v" || cmd == "g" ||cmd == "t"){
        GameInit(cmd); //creates first floor and enemies
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
            throw RESTART;
          } else if (cmd == "q") {
            return 0;//terminate
          }//else ignore
        }
      } //else ignore
      catch (RESTART) {}//continue (before game)
    } catch (...) { return 0; }
  }
