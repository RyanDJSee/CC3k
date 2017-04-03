#include "subject.h"
#include "observer.h"
#include "subtype.h"
#include <memory>
#include <vector>
#include <iostream>
#include "cell.h"
using namespace std;


void Subject::attach(shared_ptr<Observer> o) {
  //add to observers
  observers.emplace_back(o);
}


void Subject::dettachall(){
  int len=observers.size();
  for (int i=0;i<len;++i){
    observers.pop_back();
  }
}


void Subject::notifyObservers(SubType t) {
  auto thisptr=shared_from_this();
  #ifdef D
      cout<<"start notifyObservers"<<endl;
  #endif
  //go through all observers and notify ones with type t
  #ifdef D
      cout<<"num of obs"<<observers.size()<<endl;
      if(t==SubType::CELL){
        cout<<"t is CELL"<<endl;
      } else {
        cout<<"t is FLOOR"<<endl;
      }
  #endif
  for (auto ob : observers) {
  #ifdef D
    if (!ob){
      cout<<"nullptr"<<endl;
    }else if (ob->subtype()==SubType::CELL){
      cout<<"cell"<<endl;
    } else if (ob->subtype()==SubType::FLOOR){
      cout<<"floor"<<endl;
    }
  #endif
    if (ob->subtype()==t) {
#ifdef D
  cout<<"ob is "<<dynamic_pointer_cast<Cell>(ob)->getRep()<<endl;
  cout<<"iam "<<dynamic_pointer_cast<Cell>(thisptr)->getRep()<<endl;
#endif

      ob->notify(thisptr);
      #ifdef D
          cout<<"notify each"<<endl;
          cout<<dynamic_pointer_cast<Cell>(ob)->getRep()<<endl;
          cout<<dynamic_pointer_cast<Cell>(ob)->getPos()[0]<<endl;
          cout<<dynamic_pointer_cast<Cell>(ob)->getPos()[1]<<endl;
          cout<<dynamic_pointer_cast<Cell>(ob)->getPos()[2]<<endl;
      #endif
    }
  }
}


void Subject::attackedBy(Human &hu){}
void Subject::attackedBy(Dwarf &dw){}
void Subject::attackedBy(Halfling &half){}
void Subject::attackedBy(Elf &elf){}
void Subject::attackedBy(Orc &orc){}
void Subject::attackedBy(Merchant &mer){}
void Subject::attackedBy(Dragon &dra){}
void Subject::attackedBy(Shade& shade){}
void Subject::attackedBy(Goblin& goblin) {}
void Subject::attackedBy(Vampire& vampire) {}
void Subject::attackedBy(Troll& troll){}
void Subject::attackedBy(Drow& drow){}


vector<int> Subject::getPos() const{
  //will be implemented in Cell
  vector<int> v;
  v.emplace_back(-1);
  v.emplace_back(-1);
  return v;
}


Subject:: ~Subject() {}
