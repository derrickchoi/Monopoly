#include <QApplication>
#include <QGridLayout>
#include <QPushButton>
#include <QFont>
#include <QVBoxLayout>
#include <QWidget>
#include <iostream>
#include <QMessageBox>

#include "mainwindow.h"
//#include "dialog.h"
//#include "dialogpieces.h"

//int playerNum;
//int playerPiece;

int main( int argv, char* argc[] ) {

  QApplication app( argv, argc );
  MainWindow mw;
  mw.show();

   QMessageBox startGame; //message box to start game
   startGame.setText(QString("Welcome to Derrick Choi's Hong Kong Monopoly Game! Start the Game in the Menu Bar!"));
   startGame.setGeometry(315,315,100,100);
   startGame.exec();

  return app.exec();
}
