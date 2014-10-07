#ifndef CENTRALWIDGET_H
#define CENTRALWIDGET_H

#include <QtGui>
#include <QApplication>
#include <QGridLayout>
#include <QPushButton>
#include <QFont>
#include <QVBoxLayout>
#include <QWidget>
#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include <QInputDialog>
#include <QPropertyAnimation>
#include <QMessageBox>

#include "guispace.h"
#include "player.h"
#include "guiplayer.h"

class CentralWidget: public QWidget {
  Q_OBJECT

  private:
    QPushButton* cardDeckButton;
    QPushButton* cardDeckButton2;
    QLabel* boardLabel;
    QLabel* boardLabel2;
    QPixmap* cardFaceDown1;
    QPixmap* cardFaceUp1;
    QPixmap* cardFaceDown2;
    QPixmap* cardFaceUp2;
    QPixmap* cardFaceUp3;
    QPixmap* cardFaceUp4;
    QPixmap* cardFaceUp5;
    QPixmap* cardFaceUp6;
    QPixmap* cardFaceUp7;
    QPixmap* cardFaceUp8;
    bool isFaceDown;
    bool isFaceDown2;
    bool rolling;
    bool buying;
    bool upgrading;
    bool ending;
    QPushButton* diceButton;
    QPixmap* dice;
    QPixmap* dice1;
    QPixmap* dice2;
    QPixmap* dice3;
    QPixmap* dice4;
    QPixmap* dice5;
    QPixmap* dice6;

    QPushButton* firstpiece;
    QPushButton* secondpiece;
    QPushButton* thirdpiece;
    QPushButton* fourthpiece;
    
    QPixmap* piece1;
    QPixmap* piece2;
    QPixmap* piece3;
    QPixmap* piece4;

    QPushButton* buyProperty;
    QPixmap* property;

    QPushButton* upgradeProperty;
    QPixmap* niceproperty;

    QPushButton* endTurn;
    QPixmap* end;

  public slots:
    void drawCard();
    void drawCard2();
    void payProperty();
    void payupgradeProperty();
    void endplayerTurn();
    void runTurn();

  
 public:
    CentralWidget(int _pn, int *_pp, QWidget *parent, Player* playersm[4],GUIPlayer* guiPlayers[4]); //4?
    CentralWidget(QWidget *parent);
    int pn;
    int *pp;
    int currentPlayer;
    int x;
    int y;
    int amount;
    void updateSpace(int currentPlayer);
    void movePlayers(int, int, int);
    void createboard();
    void drawPlayers();
    void rollDice();
    void enableDice();
    Player** players;
    GUISpace* board[40];
    GUIPlayer** gplayers;
    void playerBroke();
    void promptStart();
    
};

#endif
