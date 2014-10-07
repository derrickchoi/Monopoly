#ifndef SPACE_H
#define SPACE_H

#include <string>
#include "player.h"
//class Player;
//The space class has three strings of top, middle and bottom text with a space function, int nextSpace and a call to the action file but is not currently being used in PA4.

using namespace std;

class space {
	public:
		space();
		~space();
		string pieces;

		int nextSpace;
		int cardspace;
		Player *owner; //owner of property
		bool upgrade; //set to false 
		void spaceupgrade(); //return upgrade to true
		
		Player* checkOwner(); //pointer checking the owner of property
		void setOwner(Player*); //function to set the owner

		int x;
		int y;

	private:
};

#endif
