#include "dragon.h"
#include <string>
#include <memory>
#include <iostream>

using namespace std;

class Subject;

Dragon::Dragon(int chamber, int r, int c):
    Enemy{chamber, r, c, 150, 20, 20} {}

string Dragon::getRep() const { return "D"; }

void Dragon::notify(shared_ptr<Subject>& whoNotified) {
#ifdef D
  cout<<"inside dragon notify"<<endl;
#endif
    whoNotified->attackedBy(*this);
    #ifdef D
      cout<<"done dragon notify"<<endl;
    #endif
}

string Dragon::getName() const { return "Dragon"; }
