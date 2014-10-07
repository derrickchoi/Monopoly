#include <iostream>
#include "mainwindow.h"

MainWindow::MainWindow() { //QInputDialogs for player number and player piece
  bool pick = true;
  bool ok;
  pn = QInputDialog::getInt(this, tr("Welcome to Derrick Choi's Monopoly Game!"),
    tr("Number of Players between 2 and 4:"), 2, 2, 4, 1, &ok);
  pp = new int[pn]; //dyanmic array for player piece
  players = new Player*[pn]; //dynamic array
  for (int i = 0; i < pn; i++ ) { 
    players[i] = new Player();
  } 
  for (int i=0;i<pn;i++) {
    bool ok;
    pp[i] = QInputDialog::getInt(this, tr("Now pick pieces!"), 
      tr("For each player, pick a different piece from 1-4:"), 1, 1, 4, 1, &ok);
    std::cout << pn << std::endl;
    std::cout << pp[i] << std::endl;
    do { //checks if the player piece has already been taken. prompts again
      pick = true;
      for (int j=0;j<pn;j++) { 
        if (pp[i]==pp[j] && i != j) {
          pick = false;
          pp[i] = QInputDialog::getInt(this, tr("Now pick a piece that has not been taken!"),
            tr("Piece taken! Pick a unique piece from 1-4:"), 1, 1, 4, 1, &ok);
        }
      }
    } while(!pick);
  } 

  setGeometry( 0, 0, 1000, 600 );

  //Display the board in the central widget
  central = new CentralWidget(pn, pp, this, players, guiPlayers);

  setCentralWidget( central );

  //Player 1 is at the left. 2 at the left. 3 on right. 4 on the right
  //Create the GUIPlayers
  if (pn <=2){ //if statements for every player number because it is dynamic
  guiPlayers[0] = new GUIPlayerHorizontal( players[0] );
  guiPlayers[1] = new GUIPlayerVertical( players[1] );
  addDockWidget( Qt::LeftDockWidgetArea, guiPlayers[0] );
  addDockWidget( Qt::LeftDockWidgetArea, guiPlayers[1] );
}
else if (pn<=3){
  guiPlayers[0] = new GUIPlayerHorizontal( players[0] );
  guiPlayers[1] = new GUIPlayerVertical( players[1] );
  guiPlayers[2] = new GUIPlayerHorizontal( players[2] );

  addDockWidget( Qt::LeftDockWidgetArea, guiPlayers[0] );
  addDockWidget( Qt::LeftDockWidgetArea, guiPlayers[1] );
  addDockWidget( Qt::RightDockWidgetArea, guiPlayers[2] );
  }
else{
  guiPlayers[0] = new GUIPlayerHorizontal( players[0] );
  guiPlayers[1] = new GUIPlayerVertical( players[1] );
  guiPlayers[2] = new GUIPlayerHorizontal( players[2] );
  guiPlayers[3] = new GUIPlayerVertical( players[3] );

  addDockWidget( Qt::LeftDockWidgetArea, guiPlayers[0] );
  addDockWidget( Qt::LeftDockWidgetArea, guiPlayers[1] );
  addDockWidget( Qt::RightDockWidgetArea, guiPlayers[2] );
  addDockWidget( Qt::RightDockWidgetArea, guiPlayers[3] );
}

  //Menu Bar Code
  QMenuBar *mb = menuBar(); //creates the menu bar
  QMenu* menu= new QMenu("Menu of Options! Click on Me!", this);
  mb->addMenu(menu);

  startAction = new QAction( "Start the Game!", this ); //start game button
  menu->addAction( startAction );
  connect(startAction, SIGNAL(triggered()), this, SLOT(start()));

  QAction *resignAction = new QAction( "Player Resign! This is going to quit the game!", this );
  menu->addAction( resignAction ); //player resigning and quitting the program whole
  connect(resignAction, SIGNAL(triggered()), qApp, SLOT(quit())); 

  QAction *exitAction = new QAction( "Quit the Game! The program will end!", this );
  menu->addAction( exitAction ); //quit the game as a whole
  connect(exitAction, SIGNAL(triggered()), qApp, SLOT(quit())); 
  endGame();
}

void MainWindow::start() { //starting of the game and making buttons come to life after they were set to false
  startAction->setEnabled(true);
  central->enableDice();
  central->drawPlayers();
  startAction->setEnabled(false);
  central->promptStart();
}

void MainWindow::endGame() {
  QMessageBox* gameEnds = new QMessageBox(this);
  gameEnds->setText(QString("The game is ending! Looks like there is no winner in this game!"));
}