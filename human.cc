#include "human.h"
#include <string>
#include <memory>
#include "info.h"

using namespace std;

class Subject;

Human::Human(int chamber, int r, int c):
    Enemy{chamber, r, c, 140, 20, 20} {}

string Human::getRep() const{ return "H"; }

void Human::notify(shared_ptr<Subject>& whoNotified) {
#ifdef D
  cout<<"inside human notify"<<endl;
  cout<<"char info is"<<dynamic_pointer_cast<Character> (whoNotified)->getInfo().hp<<endl;
#endif
    dynamic_pointer_cast<Character> (whoNotified)->attackedBy(*dynamic_pointer_cast<Human>(shared_from_this()));
}

string Human::getName() const { return "Human"; }
