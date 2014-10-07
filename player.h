//player.h
#ifndef PLAYER_H
#define PLAYER_H

#include <QString>
#include <string>
//#include "bank.h"
//#include "gameboard.h"

class Player {
 private:
  QString playerName;

 public:
  Player();
  Player(QString n);
  void setName( QString n );
  QString getName();
  int currentSpace;
  void updateSpace(int);
  int getSpace();
  void setSpace(int);

	//int piece;
	//int currentSpace; 
	int payMoney(int); //player deducts money
	int printmoney(); //printing player money
	int getMoney(int); //player receiving money
	//int property[40]; //array of property size 40
	//int buyProperty(gameboard, bank*); //buying property function
	//int hold; //random number 

  protected:
  	double money;

};

#endif
