#include "shade.h"
#include "pc.h"
#include <memory>
#include <string>
#include "enemy.h"
#include <iostream>
using namespace std;


Shade::Shade(int chamber, int r, int c):
    PC(chamber, r, c, 125, 25, 25, 125) {
#ifdef D
        cout<<"character is"<<getName()<<endl;
        cout<<"maxhp is"<<maxHP<<endl;;
#endif
    }

// whoNotified notifies that it can be attacked
void Shade::notify(shared_ptr<Subject>& whoNotified) {
  #ifdef D
    cout<<"start shade notify"<<endl;
  #endif
  dynamic_pointer_cast<Enemy> (whoNotified)->attackedBy(*dynamic_pointer_cast<Shade> (shared_from_this()));
#ifdef D
  cout<<"done shade notify"<<endl;
#endif
}

string Shade::getName() const { return "Shade"; }
