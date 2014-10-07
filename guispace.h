#include <QtGui>
#include <QLabel>
#include <QInputDialog>
#ifndef GUISPACE_H
#define GUISPACE_H

#include "space.h"

class GUISpace : public QWidget {
  Q_OBJECT

  protected:

  public:
    GUISpace();
    GUISpace(int, int, int, int);
    GUISpace *board[40];
    //void createboard();
    int getX();
    int getY();
    int getamount();
    void setOwner(Player*);
    Player *owner; //owner of property
    Player* checkOwner();
    bool upgrade;

  private:
    int x;
    int y;
    int space;
    int amount;

};

#endif

