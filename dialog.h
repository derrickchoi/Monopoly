/*#ifndef DIALOG_H
#define DIALOG_H

#include <QtGui>
#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include "player.h"

class Dialog: public QDialog {
  Q_OBJECT

 public:
  Dialog(int* playerNum, int* playerPiece, QWidget * parent = 0, Qt::WindowFlags f = 0);
  QLabel* playertext;

  QPushButton *button1;
  QPushButton *button2;
  QPushButton *button3;
  QPushButton *button14;

  int* playerNum;
  int* playerPiece;

  QLabel* playertext2;

  QRadioButton *button4;
  QRadioButton *button5;
  QRadioButton *button6;
  QRadioButton *button7;
  QRadioButton *button8;
  QRadioButton *button9;
  QRadioButton *button10;
  QRadioButton *button11;
  QRadioButton *button12;
  QRadioButton *button13;


 // Player *gamers[4];
  
  public slots:
	void pick2players();
	void pick3players();
	void pick4players();

	void pickpiece0();
	void pickpiece1();
	void pickpiece2();
	void pickpiece3();
	void pickpiece4();
	void pickpiece5();
	void pickpiece6();
	void pickpiece7();
	void pickpiece8();
	void pickpiece9();

};

#endif
*/