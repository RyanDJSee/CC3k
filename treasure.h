#ifndef TREASURE_H
#define TREASURE_H

class Treasure: public Item {
  bool isGuarded; //if true: it's a Dragon Hoard that is guarded
public:
  Treasure(int chamber, int amt, bool isGuarded); //constructor
  void notify(Subject &whoNotified) override;
  // wN called this.notify(wN), this should do sth on wN
  char getRep() const override; //returns the text representation of this
  StepType Steppable() const;
  //returns the StepType of this: CantStep/PickUp/WalkOver

};


#endif
