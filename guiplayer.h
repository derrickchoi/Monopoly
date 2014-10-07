#include <QtGui>
#include <QLabel>
#include <QInputDialog>
#include <iostream>
#include <QAction>

#ifndef GUIPLAYER_H
#define GUIPLAYER_H

#include "player.h"
#include "guiplayer.h"

class GUIPlayer : public QDockWidget {
  Q_OBJECT

  protected:
    Player* player;
    QLabel *nameLabel0;
    QLabel *nameLabel;
    QLabel *nameLabel1;
    QLabel *nameLabel2;
    QLabel *nameLabel3;
    QLabel *nameLabel4; 
    QLabel *moneyLabel;
    QScrollArea *propertyScroll;   

  public:
    GUIPlayer( Player* p );
    void buyProperty();
    void setStatus();
    void updateLabel(int space, int balance);

};

#endif
