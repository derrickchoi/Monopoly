/*#ifndef DIALOGPIECES_H
#define DIALOGPIECES_H

#include <QtGui>
#include <QDialog>
#include <QLineEdit>
#include <QLabel>
//#include "player.h"

class Dialogpieces: public QDialog {
	Q_OBJECT

  public:
	Dialogpieces(QWidget * parent = 0, Qt::WindowFlags f = 0);
	QLabel* playertext;

	QPushButton *button0;
	QPushButton *button1;
	QPushButton *button2;
	QPushButton *button3;
	QPushButton *button4;
	QPushButton *button5;
	QPushButton *button6;
	QPushButton *button7;
	QPushButton *button8;
	QPushButton *button9;
	QPushButton *button10;

	int* playerPiece;

  private slots:
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