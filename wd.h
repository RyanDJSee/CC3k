#ifndef WD_H
#define WD_H

class WD: public Potion {
  static bool wasUsed; //whether the type of this potion has been used before

public:
  WD(int chamber, int amt=-5); //constructor, default amt is for cell on Floor
  void notify(Subject &whoNotified) override;
  // wN called this.notify(wN), this should do sth on wN
  int getDef() const override; // returns the Def amount in this

};


#endif
