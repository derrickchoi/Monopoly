#include <QtGui>
#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include <QInputDialog>
#include <QPushButton>
#include <QAction>
#include <QMessageBox>

#include "guiplayerhorizontal.h"
#include "guiplayervertical.h"
#include "centralwidget.h"
#include "guispace.h"
#include "guiplayer.h"

class MainWindow : public QMainWindow {
  Q_OBJECT

  private:
    QLabel *boardLabel;
    Player** players;
    GUIPlayer* guiPlayers[4];
    QPushButton* cardDeckButton;
    CentralWidget* central;
    QAction *startAction;

  public:
    MainWindow();
    int pn;
    int*pp;
    void endGame();
    void playerBroke();

   public slots:
    void start();

};
