#include "guiplayer.h"
//#include "mainwindow.h"

GUIPlayer::GUIPlayer( Player* p ) {
  player = p;
  nameLabel = new QLabel( this );
  nameLabel->setText( player->getName() );
  setFixedSize(QSize(194,300));

  nameLabel0 = new QLabel (this); //qlabel for the bank
  nameLabel0->setGeometry(0,15,200,40);
  nameLabel0->setText("\nBank $: Infinite. Don't Worry.");

  nameLabel1 = new QLabel (this); //qlabel for the player space and money
  nameLabel1->setGeometry(0,35,200,40);
  nameLabel1->setText("\nPlayer Space and Money");

  nameLabel2 = new QLabel (this);
  nameLabel2->setGeometry(0,60,200,40);

  moneyLabel = new QLabel (this);
  moneyLabel-> setGeometry (20,60,200,40);

  nameLabel4 = new QLabel (this);
  nameLabel4->setGeometry(0,80,200,40);

  nameLabel3 = new QLabel (this);
  nameLabel3->setGeometry(0,0,200,40);

  propertyScroll = new QScrollArea(this);
  propertyScroll->setGeometry(0,160,195,140);
  propertyScroll->setWidget(nameLabel3);
}

void GUIPlayer::buyProperty() {} //dont do anything

void GUIPlayer::setStatus() {} //dont do anything

void GUIPlayer::updateLabel(int space, int balance) {
	moneyLabel->setText(QString("%1").arg(balance));
	nameLabel2->setText(QString("%1").arg(space));
} //updates the space and the balance of the player playing