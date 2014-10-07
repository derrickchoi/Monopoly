/*#include "dialog.h"
#include <iostream>

Dialog::Dialog(int* playerNum, int* playerPiece, QWidget * parent, Qt::WindowFlags f): QDialog(parent, f){
	setVisible(true);
	//setFixedSize(640, 325);
	setFixedSize(650, 550);
	this->playerNum = playerNum;
	playertext = new QLabel("Click to choose the number of players", this);
	playertext->setVisible(true);
	playertext->setGeometry(195,40,500,50);

	button1 = new QPushButton("2", this);
	button1->setVisible(true);
	button1->setGeometry( 70, 110, 100, 100 );

	button2 = new QPushButton("3", this);
	button2->setVisible(true);
	button2->setGeometry( 270, 110, 100, 100 );

	button3 = new QPushButton("4", this);
	button3->setVisible(true);
	button3->setGeometry( 470, 110, 100, 100 );

	button14 = new QPushButton("Ok", this);
	button14->setVisible(true);
	button14->setGeometry( 528, 475, 40, 40);

	connect( button1, SIGNAL(clicked()), this, SLOT(pick2players()) );
	connect( button2, SIGNAL(clicked()), this, SLOT(pick3players()) );
	connect( button3, SIGNAL(clicked()), this, SLOT(pick4players()) );
////
//for (int i=0; i<playerNum; i++) {
	this->playerPiece = playerPiece;
	playertext2 = new QLabel("Choose the piece for each player", this);
	playertext2->setVisible(true);
	playertext2->setGeometry(210,260,500,50);

	button4 = new QRadioButton("Wheelbarrow", this);
	button4->setVisible(true);
	button4->setGeometry(30,310,115,50);

	button5 = new QRadioButton("Battleship", this);
	button5->setVisible(true);
	button5->setGeometry(160,310,100,50);

	button6 = new QRadioButton("Racecar", this);
	button6->setVisible(true);
	button6->setGeometry(270,310,100,50);

	button7 = new QRadioButton("Thimble", this);
	button7->setVisible(true);
	button7->setGeometry(390,310,100,50);

	button8 = new QRadioButton("Boot", this);
	button8->setVisible(true);
	button8->setGeometry(510,310,100,50);

	button9 = new QRadioButton("Scottie Dog", this);
	button9->setVisible(true);
	button9->setGeometry(30,385,110,50);

	button10 = new QRadioButton("Top Hat", this);
	button10->setVisible(true);
	button10->setGeometry(160,385,100,50);

	button11= new QRadioButton("Weird Cat", this);
	button11->setVisible(true);
	button11->setGeometry(270,385,100,50);

	button12 = new QRadioButton("Iron", this);
	button12->setVisible(true);
	button12->setGeometry(390,385,100,50);

	button13 = new QRadioButton("Train", this);
	button13->setVisible(true);
	button13->setGeometry(510,385,100,50);

	//connect( button14, SIGNAL(clicked()), this, SLOT(accept()));

	connect( button4, SIGNAL(clicked()), this, SLOT(pickpiece0()) );
	connect( button5, SIGNAL(clicked()), this, SLOT(pickpiece1()) );
	connect( button6, SIGNAL(clicked()), this, SLOT(pickpiece2()) );
	connect( button7, SIGNAL(clicked()), this, SLOT(pickpiece3()) );
	connect( button8, SIGNAL(clicked()), this, SLOT(pickpiece4()) );
	connect( button9, SIGNAL(clicked()), this, SLOT(pickpiece5()) );
	connect( button10, SIGNAL(clicked()), this, SLOT(pickpiece6()) );
	connect( button11, SIGNAL(clicked()), this, SLOT(pickpiece7()) );
	connect( button12, SIGNAL(clicked()), this, SLOT(pickpiece8()) );
	connect( button13, SIGNAL(clicked()), this, SLOT(pickpiece9()) );
//}

	connect( button14, SIGNAL(clicked()), this, SLOT(accept()));

	//playertext.setText("Please enter number of players");
	//playertext.displayText();
	exec();
	reject();
	//finished(*playerNum);
	setVisible(false);
}

void Dialog::pick2players() {
	*playerNum = 2;
	std::cout << *playerNum << std::endl;
}

void Dialog::pick3players() {
	*playerNum = 3;
	std::cout << *playerNum << std::endl;
}

void Dialog::pick4players() {
	*playerNum = 4;
	std::cout << *playerNum << std::endl;
}

//////////////////////////////////

void Dialog::pickpiece0() {
	*playerPiece = 0;
	std::cout << *playerPiece<<std::endl;
}

void Dialog::pickpiece1() {
	*playerPiece = 1;
	std::cout << *playerPiece<<std::endl;
}

void Dialog::pickpiece2() {
	*playerPiece = 2;
	std::cout << *playerPiece<<std::endl;
}

void Dialog::pickpiece3() {
	*playerPiece = 3;
	std::cout << *playerPiece<<std::endl;
}

void Dialog::pickpiece4() {
	*playerPiece = 4;
	std::cout << *playerPiece<<std::endl;
}

void Dialog::pickpiece5() {
	*playerPiece = 5;
	std::cout << *playerPiece<<std::endl;
}

void Dialog::pickpiece6() {
	*playerPiece = 6;
	std::cout << *playerPiece<<std::endl;
}

void Dialog::pickpiece7() {
	*playerPiece = 7;
	std::cout << *playerPiece<<std::endl;
}

void Dialog::pickpiece8() {
	*playerPiece = 8;
	std::cout << *playerPiece<<std::endl;
}

void Dialog::pickpiece9() {
	*playerPiece = 9;
	std::cout << *playerPiece<<std::endl;
}

///////////////////////////////////////////

/*for (int i=0; i<playerNum; i++) {  
	gamers[i] = new Player();
 }*/

//i<((Dialog *)mw.dialog)->playerNum;
