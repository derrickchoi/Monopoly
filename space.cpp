#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include "space.h"
//#include "player.h"
//#include "action.h"

//IGNORE DIDN'T USE
using namespace std;

space::space() {
	owner = NULL;
	upgrade = false;
} //constructor

Player* space::checkOwner() {
	return owner;
}


void space::spaceupgrade() {
	upgrade = true;
}

space::~space(){} //deconstructor

