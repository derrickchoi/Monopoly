#include "guispace.h"

GUISpace::GUISpace() {}

GUISpace::GUISpace(int xcoordinate, int ycoordinate, int spacenumber, int price) {
	x = xcoordinate;
	y = ycoordinate;
	space = spacenumber;
	amount = price;
	owner = NULL;
	upgrade = false;
} //passing in parameters of coordinates, space number, space price, owner set to NULL and upgrade for spaces set to false

int GUISpace::getX() {
	return x; //gets the x coordinate
}

int GUISpace::getY() {
	return y; //gets the y coordinate
}

int GUISpace::getamount(){
	return amount; //gets the amount of price of space
}

void GUISpace::setOwner (Player* p) {
	owner = p; //sets the owner of the space to the player
}

Player* GUISpace::checkOwner() {
	return owner; // checks the owner of the space
}
