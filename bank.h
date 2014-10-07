#ifndef BANK_H
#define BANK_H

#include <string>
//#include "player.h"

using namespace std;

class bank { //: public player {
  public:
	bank();
	int givemoney(int); //bank giving out money
	int takemoney(int); //bank taking in money
	int get_Amount(); //getting the vauly amount
	~bank();
  protected:
	double vault;

};

#endif