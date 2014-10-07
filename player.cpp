#include "player.h"

Player::Player() {
	currentSpace = 1;
	money = 4000;
}

Player::Player( QString n ) {
  playerName = n;
}

void Player::setName( QString n ) {
  playerName = n;
}

QString Player::getName() {
  return playerName;
}

int Player::payMoney(int n) //pays money
{
	money = money - n;
	return money;
}

int Player::printmoney() //prints out money
{
	return money;
}

int Player::getMoney(int n) //receives money
{
	money = money + n;
	return money;
}

void Player::updateSpace(int changeSpace){ //updates space of player
	currentSpace = changeSpace + currentSpace;
}

int Player::getSpace(){ //gets the space of the player
	return currentSpace;
}

void Player::setSpace(int s) { //setting the space of player
	currentSpace = s;
}