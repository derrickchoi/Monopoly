#include "centralwidget.h"
#include <iostream>
#include <QPushButton>

CentralWidget::CentralWidget(QWidget *parent): QWidget(parent) {
}

CentralWidget::CentralWidget(int _pn, int* _pp, QWidget *parent, Player* playersm[4], GUIPlayer* guiPlayers[4]): QWidget(parent) { //_pp[3]
  //pass in parameters to constructor
  currentPlayer = 0; //sets currenPlayer to 0
  players = playersm;
  pn = _pn;
  pp = _pp;
  gplayers = guiPlayers;

  boardLabel = new QLabel( this );
  boardLabel->setPixmap( QPixmap("boardupdated.png") ); //board picture

  //Create the images
  cardFaceDown2 = new QPixmap( ":/images/chancedown.jpg" );
  cardFaceDown1 = new QPixmap( ":/images/communitydown.jpg" );

  cardFaceUp1 = new QPixmap( ":/images/communitychest0.png" );
  cardFaceUp2 = new QPixmap( ":/images/communitychest1.png" );
  cardFaceUp3 = new QPixmap( ":/images/communitychest2.png" );
  cardFaceUp4= new QPixmap( ":/images/communitychest3.png" );
  cardFaceUp5 = new QPixmap( ":/images/chance0.png" );
  cardFaceUp6 = new QPixmap( ":/images/chance1.png" );
  cardFaceUp7 = new QPixmap( ":/images/chance2.png" );
  cardFaceUp8 = new QPixmap( ":/images/chance3.png" );

  dice = new QPixmap( ":/images/diceupdated.jpg");
  dice1 = new QPixmap( ":/images/dice1.jpg");
  dice2 = new QPixmap( ":/images/dice2.png");
  dice3 = new QPixmap( ":/images/dice3.jpg");
  dice4 = new QPixmap( ":/images/dice4.jpg");
  dice5 = new QPixmap( ":/images/dice5.png");
  dice6 = new QPixmap( ":/images/dice6.png");

  piece1 = new QPixmap( ":/images/piece1.png");
  piece2 = new QPixmap( ":/images/piece2.png");
  piece3 = new QPixmap( ":/images/piece3.png");
  piece4 = new QPixmap( ":/images/piece4.png");

  property = new QPixmap( ":/images/buybutton.png");
  niceproperty = new QPixmap( ":/images/upgradebutton.png");
  end = new QPixmap( ":/images/endbutton.png");

  //Create the button for the card deck
  cardDeckButton = new QPushButton( this );
  cardDeckButton->setIcon( *cardFaceDown1 );
  cardDeckButton->setIconSize( QSize(97, 152) );
  cardDeckButton->setGeometry( 428, 220, 97, 152 );
  cardDeckButton->setEnabled(false);

  cardDeckButton2 = new QPushButton( this );
  cardDeckButton2->setIcon( *cardFaceDown2 );
  cardDeckButton2->setIconSize( QSize(97, 152) );
  cardDeckButton2->setGeometry( 73, 220, 97, 152 );
  cardDeckButton2->setEnabled(false);
  
   //Create the button for the dice
  diceButton = new QPushButton( this );
  diceButton->setIcon( *dice );
  diceButton->setIconSize( QSize(121, 97) );
  diceButton->setGeometry( 240, 245, 121, 97 );
  diceButton->setEnabled(false);

 //Create the button for the buy property
  buyProperty = new QPushButton ( this );
  buyProperty->setIcon( *property );
  buyProperty->setIconSize( QSize(150, 75) );
  buyProperty->setGeometry( 72, 400, 124, 58);
  buyProperty->setEnabled(false);

 //Create the button for the upgrade property
  upgradeProperty = new QPushButton ( this );
  upgradeProperty->setIcon( *niceproperty );
  upgradeProperty->setIconSize( QSize(150, 75) );
  upgradeProperty->setGeometry( 237, 400, 124, 58);
  upgradeProperty->setEnabled(false);

 //Create the button for ending turn
  endTurn = new QPushButton ( this );
  endTurn->setIcon( *end );
  endTurn->setIconSize( QSize(150, 75) );
  endTurn->setGeometry( 402, 400, 124, 58);
  endTurn->setEnabled(false);

 //Create the button for the four pieces
  firstpiece = new QPushButton ( this );
  firstpiece->setIcon( *piece1 );
  firstpiece->setIconSize( QSize(12.75, 25) );
  firstpiece->setGeometry( 0, 29, 15, 25);
  firstpiece->setEnabled(false);
  //firstpiece->setVisible(false);

  secondpiece = new QPushButton ( this );
  secondpiece->setIcon( *piece2 );
  secondpiece->setIconSize( QSize(12.75, 25) );
  secondpiece->setGeometry( 13.75, 29, 15, 25);
  secondpiece->setEnabled(false);
 //secondpiece->setVisible(false);

  thirdpiece = new QPushButton ( this );
  thirdpiece->setIcon( *piece3 );
  thirdpiece->setIconSize( QSize(12.75, 25) );
  thirdpiece->setGeometry( 27.5, 29, 15, 25);
  thirdpiece->setEnabled(false);
  //thirdpiece->setVisible(false);

  fourthpiece = new QPushButton ( this );
  fourthpiece->setIcon( *piece4 );
  fourthpiece->setIconSize( QSize(12.75, 25) );
  fourthpiece->setGeometry( 41.25, 29, 15, 25);
  fourthpiece->setEnabled(false);
  //fourthpiece->setVisible(false);

  //Connect the button to slots with signals
  connect( cardDeckButton, SIGNAL(clicked()), this, SLOT(drawCard()) );
  isFaceDown = true;

  connect( cardDeckButton2, SIGNAL(clicked()), this, SLOT(drawCard2()) );
  isFaceDown2 = true;

  connect ( diceButton, SIGNAL(clicked()), this, SLOT(runTurn()) );
  rolling = true;

  connect ( buyProperty, SIGNAL(clicked()), this, SLOT(payProperty()) );
  buying = true;

  connect ( upgradeProperty, SIGNAL(clicked()), this, SLOT(payupgradeProperty()) );
  upgrading = true;

  connect ( endTurn, SIGNAL(clicked()), this, SLOT(endplayerTurn()) );
  ending = true;
  createboard();
}

void CentralWidget::drawCard() {
  //this function has the player randomly get a card from the deck and implement it
  srand(time(0));
  std::cout << "drawing \n";
  int card1 = rand() % 4 + 1;
  std::cout << "card1 " << card1 << std::endl;
  if (card1 == 1) {
      std::cout << "card 1 \n";
      cardDeckButton->setIcon( *cardFaceUp1 );
      isFaceDown = true;
      players[currentPlayer]->updateSpace(-1); //updates space -1
      buyProperty->setEnabled(true);
      int newSpace = players[currentPlayer]->getSpace(); //gets the newSpace of the player
      x = board[newSpace-1]->getX();
      std:: cout << "X: " << x << std::endl;
      y = board[newSpace-1]->getY();
      std::cout << "Y: " << y << std::endl;
  } if (card1 == 2) {
      std::cout << "card 2 \n";
      cardDeckButton->setIcon( *cardFaceUp2 );
      isFaceDown = true;
      players[currentPlayer]->updateSpace(3);
      int newSpace = players[currentPlayer]->getSpace();
      x = board[newSpace-1]->getX();
      std:: cout << "X: " << x << std::endl;
      y = board[newSpace-1]->getY();
      std::cout << "Y: " << y << std::endl;
  } if (card1 == 3) {
      std::cout << "card 3 \n";
      cardDeckButton->setIcon( *cardFaceUp3 );
      isFaceDown = true;
      players[currentPlayer]->updateSpace(4);
      buyProperty->setEnabled(true);
      int newSpace = players[currentPlayer]->getSpace();
      x = board[newSpace-1]->getX();
      std:: cout << "X: " << x << std::endl;
      y = board[newSpace-1]->getY();
      std::cout << "Y: " << y << std::endl;
  } 
  if (card1 == 4) {
      std::cout << "card 4 \n";
      cardDeckButton->setIcon( *cardFaceUp4 );
      isFaceDown = true;
      players[currentPlayer]->updateSpace(5);
      buyProperty->setEnabled(true);
      int newSpace = players[currentPlayer]->getSpace();
      x = board[newSpace-1]->getX();
      std:: cout << "X: " << x << std::endl;
      y = board[newSpace-1]->getY();
      std::cout << "Y: " << y << std::endl;
  }
  movePlayers(currentPlayer,x,y); //moving the players after the card
}

void CentralWidget::drawCard2() {
  //same as above excpet this is for the chance deck
  srand(time(0));
  int card2 = rand() % 4 + 1;
  if (card2 == 1) {
      cardDeckButton2->setIcon( *cardFaceUp5 );
      isFaceDown2 = true;
      players[currentPlayer]->updateSpace(-4);
      int newSpace = players[currentPlayer]->getSpace();
      x = board[newSpace-1]->getX();
      std:: cout << "X: " << x << std::endl;
      y = board[newSpace-1]->getY();
      std::cout << "Y: " << y << std::endl;
  } if (card2 == 2) {
      cardDeckButton2->setIcon( *cardFaceUp6 );
      isFaceDown2 = true;
      players[currentPlayer]->updateSpace(3);
      int newSpace = players[currentPlayer]->getSpace();
      x = board[newSpace-1]->getX();
      std:: cout << "X: " << x << std::endl;
      y = board[newSpace-1]->getY();
      std::cout << "Y: " << y << std::endl;
  } if (card2 == 3) {
      cardDeckButton2->setIcon( *cardFaceUp7 );
      isFaceDown2 = true;
      players[currentPlayer]->updateSpace(6);
      //buyProperty->setEnabled(true);
      int newSpace = players[currentPlayer]->getSpace();
      x = board[newSpace-1]->getX();
      std:: cout << "X: " << x << std::endl;
      y = board[newSpace-1]->getY();
      std::cout << "Y: " << y << std::endl;
  } if (card2 == 4) {
      cardDeckButton2->setIcon( *cardFaceUp8 );
      isFaceDown2 = true;
      players[currentPlayer]->updateSpace(-2);
      //buyProperty->setEnabled(true);
      int newSpace = players[currentPlayer]->getSpace();
      x = board[newSpace-1]->getX();
      std:: cout << "X: " << x << std::endl;
      y = board[newSpace-1]->getY();
      std::cout << "Y: " << y << std::endl;
  }
}

void CentralWidget::payProperty() {
//this is when the player clicks on the buy property button
  buyProperty->setIcon( *property );
  buying = true;
  players[currentPlayer]->payMoney(amount); //pays the money to the bank
  board[players[currentPlayer]->getSpace()-1]->setOwner(players[currentPlayer]); //sets the owner to the buyer
  std::cout << amount << std::endl;
  std::cout << players[currentPlayer]->printmoney()<< std::endl;
  gplayers[currentPlayer]->updateLabel(players[currentPlayer]->getSpace(), players[currentPlayer]->printmoney());
  //updates the money of the player on the side
  buyProperty->setEnabled(false);
  QMessageBox buy;// messsage box
    buy.setText(QString("You just bought a piece of property!       "));
    buy.setGeometry(410,315,100,100);
    buy.exec();
    buyProperty->setEnabled(false);

  if (players[currentPlayer]->printmoney() < 0) {
    //if player has less than 0 dollars, then the game ends immediately
    QMessageBox gameEnds;// = new QMessageBox(this);
    gameEnds.setText(QString("Looks like the game is ending because the player is broke! You will be kicked out of the game and your property will be taken by the bank!"));
    gameEnds.setGeometry(315,315,100,100);
    gameEnds.exec();
    QApplication::quit(); //quit the game if player has less than $0  
  }
}

void CentralWidget::playerBroke() {
  //player broke function
  if (players[currentPlayer]->printmoney() < 0) {
    QMessageBox gameEnds;// = new QMessageBox(this);
    gameEnds.setText(QString("The game is ending because the player is broke! You will be kicked out of the game and your property will be taken by the bank!"));
    gameEnds.setGeometry(315,315,100,100);
    gameEnds.exec();
    QApplication::quit(); //quit the game if player has less than $0  
  // QMessageBox* gameEnds = new QMessageBox(this);
  // gameEnds->setText(QString("The game is ending because a player is broke!"));
  }
}

void CentralWidget::payupgradeProperty() {
  //when the upgrade property button is pressed
  upgradeProperty->setIcon( *niceproperty );
  upgrading = true;
  board[players[currentPlayer]->getSpace()]->upgrade = true; //sets the upgrade to true with the bool in GUISpace.h
  QMessageBox payupgrade; //message box
  payupgrade.setText(QString("You just upgraded your space!     "));
  payupgrade.setGeometry(435,315,100,100);
  payupgrade.exec();
  upgradeProperty->setEnabled(false);
}

void CentralWidget::promptStart() {
  //prompts the player to start the game 
  QMessageBox gameStarts;
  gameStarts.setText(QString("The game is starting! Press to dice to roll! The players will show up in order in each space. May the force be with you!"));
  gameStarts.setGeometry(315,315,100,100);
  gameStarts.exec();
}

void CentralWidget::endplayerTurn() {
  //if the end turn button is pressed
  if ( ending ) {
    endTurn->setIcon( *end );
    ending = true;
  } else {
    endTurn->setIcon( *end );
    ending = true;
  }
  if (currentPlayer<pn-1) {
    currentPlayer++; //increments the currentplayer
  }
  else {
    currentPlayer = 0; //sets currentplayer back to 0
  }
  diceButton->setEnabled(true);
  buyProperty->setEnabled(false);
}

void CentralWidget::rollDice(){
  //rolling the dice with the actions that happen after
  std::cout<<"we be rollin'\n";
  int num = rand() % 6 + 1;
  std::cout<<"Roll Number: "<<num<< std::endl;
  if ( dice ) { //dice;
    diceButton->setIcon( *dice );
    rolling = true;
  } 
  if ( num == 1 ) {
    diceButton->setIcon( *dice1 );
    rolling = true;
  }
  if ( num == 2 ) {
    diceButton->setIcon( *dice2 );
    rolling = true;
  }
  if ( num == 3 ) {
    diceButton->setIcon( *dice3 );
    rolling = true;
  }
  if ( num == 4 ) {
    diceButton->setIcon( *dice4 );
    rolling = true;
  }
  if ( num == 5 ) { 
    diceButton->setIcon( *dice5 );
    rolling = true;
  }
  if ( num == 6 ) {
    diceButton->setIcon( *dice6 );
    rolling = true;
  }
  std:: cout << "no more!\n";
  std:: cout << currentPlayer<<std::endl;

  players[currentPlayer]->updateSpace(num); //updates space of player
  int newSpace = players[currentPlayer]->getSpace(); //gets the space
  std:: cout << newSpace << std::endl;
  if (newSpace > 40){ //if it passes the origin space 40
    int different = newSpace-40; //subtract it by 40 
    players[currentPlayer]->updateSpace(-newSpace);//-n);
    players[currentPlayer]->updateSpace(different);
    newSpace = players[currentPlayer]->getSpace(); //gets the space for newSpace
  }
  std::cout << "newSpace " << newSpace << std::endl;
  x = board[newSpace-1]->getX();
  std:: cout << "X: " << x << std::endl;
  y = board[newSpace-1]->getY();
  std::cout << "Y: " << y << std::endl;
  movePlayers(currentPlayer,x,y);
  amount = board[newSpace-1]->getamount(); //gets the amount $ for the space

  if (newSpace == 18) {
    cardDeckButton2->setEnabled(true);
    drawCard2(); //space for chance
  }

  if (newSpace == 34) {
    cardDeckButton->setEnabled(true);
    drawCard(); //space for community chest
  }

  if (newSpace ==2 || newSpace ==4 || newSpace ==5 || newSpace ==7 || newSpace ==9
    || newSpace ==10 || newSpace ==12 || newSpace ==14 || newSpace ==15 || newSpace ==16
    || newSpace ==17 || newSpace ==20 || newSpace ==22 || newSpace ==24 || newSpace ==25
    || newSpace ==27 || newSpace ==28 || newSpace ==30 || newSpace ==32 || newSpace ==33
    || newSpace ==34 || newSpace ==36 || newSpace ==38 || newSpace ==39 || newSpace ==40) {
    buyProperty->setEnabled(true); //these are spaces that are properties
    cardDeckButton->setEnabled(false);
    cardDeckButton2->setEnabled(false);
  }

  if (newSpace ==1 || newSpace ==3 || newSpace ==6 || newSpace ==8 || newSpace ==11
    || newSpace ==13 || newSpace ==18 || newSpace ==19 || newSpace ==21 || newSpace ==23
    || newSpace ==26 || newSpace ==29 || newSpace ==31 || newSpace ==34 || newSpace ==35 || newSpace ==37) {
    buyProperty->setEnabled(false); //these are spaces that are not properties
  }

  if (newSpace ==1) { //collect 200 on go adds money to player
    players[currentPlayer]->getMoney(200);
    QMessageBox landongo;//message box
    landongo.setText(QString("You just landed on go! Collect $200!        "));
    landongo.setGeometry(410,315,100,100);
    landongo.exec();
  }

  if (newSpace ==31) { //player goes to jail if they land on space 31
    players[currentPlayer]->setSpace(11);
    movePlayers(currentPlayer,x,y);
    QMessageBox landonjail; //message box
    landonjail.setText(QString("You just landed on jail! You will start from the jail space at your next turn!"));
    landonjail.setGeometry(315,315,100,100);
    landonjail.exec();
  }

  Player *owner = (board[players[currentPlayer]->getSpace()-1]->checkOwner());
  if (board[players[currentPlayer]->getSpace()-1]->checkOwner() == players[currentPlayer]) {
    //checks if the player owns the space he is on
     std::cout<<"same owner loop"<< std::endl;
     buyProperty->setEnabled(false); //can't buy it again
     std::cout<<"same owner loop2"<< std::endl;
     upgradeProperty->setEnabled(true); //can upgrade
     QMessageBox sameOwner; //message box
     sameOwner.setText(QString("You own this property You don't have to buy it again! You can upgrade your property so players will pay more!"));
     sameOwner.setGeometry(315,315,100,100);
     sameOwner.exec();
   }
  else if (owner !=NULL) { //if there is a owner 
     std::cout<<"pay owner loop"<< std::endl;
     if (board[players[currentPlayer]->getSpace()]->upgrade) {
      players[currentPlayer]->payMoney(0.50*(amount)); //pays 50% of space price if upgraded by another player
      buyProperty->setEnabled(false);
     QMessageBox payRent2; //message box
     payRent2.setText(QString("You just paid 50 percent of the property's price as rent to the bank because a player upgraded this space!"));
     payRent2.setGeometry(315,315,100,100);
     payRent2.exec();
     }
     else {
     players[currentPlayer]->payMoney(0.20*(amount)); //pay normal 20% rent
     std::cout<<"currentPlayer" <<players[currentPlayer] <<std::endl;
     buyProperty->setEnabled(false);
     QMessageBox payRent; //message box
     payRent.setText(QString("You just paid 20 percent of the property's price as rent to the bank because a player owns this space!"));
     payRent.setGeometry(315,315,100,100);
     payRent.exec();
   }
  }

  QMessageBox gameTurn; //message box for ending turn
  gameTurn.setText(QString("Press 'End Turn' when you want to end your player's turn!       "));
  gameTurn.setGeometry(338,315,80,100);
  gameTurn.exec();
  srand(time(0));

  gplayers[currentPlayer]->updateLabel(players[currentPlayer]->getSpace(), players[currentPlayer]->printmoney());
} //updating the label for space and balance

void CentralWidget::enableDice() {
  diceButton->setEnabled(true); //enables dice for rolling at start
}

void CentralWidget::runTurn() { //turn progression for player
  rollDice();
  movePlayers(currentPlayer, x, y);
  diceButton->setEnabled(false);
}

void CentralWidget::drawPlayers() { 
//picks the pieces according to the number user puts in from 1-4

  for (int i = 0; i < pn; i++){
    int piece = pp[i];
    if (piece == 1){
      firstpiece->setEnabled(true);
    }
    else if (piece == 2) {
      secondpiece->setEnabled(true);
    }
    else if (piece == 3) {
      thirdpiece->setEnabled(true);
    }
    else if (piece == 4) {
      fourthpiece->setEnabled(true);
    }
  }
}  

void CentralWidget::movePlayers(int currentPlayer, int x, int y) {
 int piece= pp[currentPlayer];
 //moving the player according to the piece they chose
  if (piece == 1) {
    firstpiece->setGeometry(x+(currentPlayer*12), y, 15, 20);
    //*12 to set the geometry inside that space as each player has designated space
  }
  else if (piece == 2) {
    secondpiece->setGeometry(x+(currentPlayer*12), y, 15, 20);
  }
  else if (piece == 3) {
    thirdpiece->setGeometry(x+(currentPlayer*12), y, 15, 20);
  }
  else if (piece == 4) { 
    fourthpiece->setGeometry(x+(currentPlayer*12), y, 15, 20);
  }
  endTurn->setEnabled(true);
  diceButton->setEnabled(false);
}

void CentralWidget::createboard() {
  //creates the board from GUISpace with x and y coordinate, space number and space price
  board[0] = new GUISpace (0,29, 1,0);
  board[1] = new GUISpace (55, 29, 2,100);
  board[2] = new GUISpace (110, 29, 3,0);
  board[3] = new GUISpace (165, 29, 4,100);
  board[4] = new GUISpace (220, 29, 5,120);
  board[5] = new GUISpace (275, 29, 6,0);
  board[6] = new GUISpace (330, 29, 7,100);
  board[7] = new GUISpace (385, 29, 8,0);
  board[8] = new GUISpace (440, 29, 9,100);
  board[9] = new GUISpace (495, 29, 10,120);
  board[10] = new GUISpace (550, 29, 11,0);

  board[11] = new GUISpace (550, 84, 12,140);
  board[12] = new GUISpace (550, 139, 13,0);
  board[13] = new GUISpace (550, 194, 14,140);
  board[14] = new GUISpace (550, 249, 15,160);
  board[15] = new GUISpace (550, 304, 16,170);
  board[16] = new GUISpace (550, 359, 17,180);
  board[17] = new GUISpace (550, 414, 18,0);
  board[18] = new GUISpace (550, 469, 19,0);
  board[19] = new GUISpace (550, 524, 20,200);
  board[20] = new GUISpace (550, 579, 21,0);

  board[21] = new GUISpace (495 ,579, 22,280);
  board[22] = new GUISpace (440 ,579, 23,0);
  board[23] = new GUISpace (385 ,579, 24,260);
  board[24] = new GUISpace (330 ,579, 25,260);
  board[25] = new GUISpace (275 ,579, 26,0);
  board[26] = new GUISpace (220 ,579, 27,240);
  board[27] = new GUISpace (165 ,579, 28,220);
  board[28] = new GUISpace (110 ,579, 29,0);
  board[29] = new GUISpace (55 ,579, 30,220);
  board[30] = new GUISpace (0 ,579, 31,0);

  board[31] = new GUISpace (0, 524, 32,300);
  board[32] = new GUISpace (0, 469, 33,300);
  board[33] = new GUISpace (0, 414, 34,0);
  board[34] = new GUISpace (0, 349, 35,0);
  board[35] = new GUISpace (0, 304, 36,320);
  board[36] = new GUISpace (0, 249, 37,0);
  board[37] = new GUISpace (0, 194, 38,350);
  board[38] = new GUISpace (0, 139, 39,350);
  board[39] = new GUISpace (0, 84, 40,400);
}