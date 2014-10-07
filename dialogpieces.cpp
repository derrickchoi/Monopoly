/*
#include "dialogpieces.h"
#include <iostream>

Dialogpieces::Dialogpieces(QWidget * parent, Qt::WindowFlags f): QDialog(parent, f) {
	setVisible(true);

	playertext = new QLabel("Choose the piece for each player", this);
	playertext->setVisible(true);
	playertext->setGeometry(160,40,500,50);

	button0 = new QPushButton("Wheelbarrow", this);
	button0->setVisible(true);
	button0->setGeometry(10,150,40,50);

	button1 = new QPushButton("Battleship", this);
	button1->setVisible(true);
	button1->setGeometry(60,150,40,50);

	button2 = new QPushButton("Racecar", this);
	button2->setVisible(true);
	button2->setGeometry(110,150,40,50);

	button3 = new QPushButton("Thimble", this);
	button3->setVisible(true);
	button3->setGeometry(160,150,100,50);

	button4 = new QPushButton("Boot", this);
	button4->setVisible(true);
	button4->setGeometry(210,150,100,50);

	button5 = new QPushButton("Scottie Dog", this);
	button5->setVisible(true);
	button5->setGeometry(260,150,100,50);

	button6 = new QPushButton("Top Hat", this);
	button6->setVisible(true);
	button6->setGeometry(310,150,100,50);

	button7 = new QPushButton("Weird Cat", this);
	button7->setVisible(true);
	button7->setGeometry(360,150,100,50);

	button8 = new QPushButton("Iron", this);
	button8->setVisible(true);
	button8->setGeometry(410,150,100,50);

	button9 = new QPushButton("Train", this);
	button9->setVisible(true);
	button9->setGeometry(460,150,100,50);

	button10 = new QPushButton("Ok", this);
	button10->setVisible(true);
	button10->setGeometry(528,230,40,40);

	connect( button0, SIGNAL(clicked()), this, SLOT(pickpiece0()) );
	connect( button1, SIGNAL(clicked()), this, SLOT(pickpiece1()) );
	connect( button2, SIGNAL(clicked()), this, SLOT(pickpiece2()) );
	connect( button3, SIGNAL(clicked()), this, SLOT(pickpiece3()) );
	connect( button4, SIGNAL(clicked()), this, SLOT(pickpiece4()) );
	connect( button5, SIGNAL(clicked()), this, SLOT(pickpiece5()) );
	connect( button6, SIGNAL(clicked()), this, SLOT(pickpiece6()) );
	connect( button7, SIGNAL(clicked()), this, SLOT(pickpiece7()) );
	connect( button8, SIGNAL(clicked()), this, SLOT(pickpiece8()) );
	connect( button9, SIGNAL(clicked()), this, SLOT(pickpiece9()) );
	connect( button10, SIGNAL(clicked()), this, SLOT(accept()));

	exec();
	reject();
}

void Dialogpieces::pickpiece0() {
	*playerPiece = 0;
}

void Dialogpieces::pickpiece1() {
	*playerPiece = 1;
}

void Dialogpieces::pickpiece2() {
	*playerPiece = 2;
}

void Dialogpieces::pickpiece3() {
	*playerPiece = 3;
}

void Dialogpieces::pickpiece4() {
	*playerPiece = 4;
}

void Dialogpieces::pickpiece5() {
	*playerPiece = 5;
}

void Dialogpieces::pickpiece6() {
	*playerPiece = 6;
}

void Dialogpieces::pickpiece7() {
	*playerPiece = 7;
}

void Dialogpieces::pickpiece8() {
	*playerPiece = 8;
}

void Dialogpieces::pickpiece9() {
	*playerPiece = 9;
}
*/