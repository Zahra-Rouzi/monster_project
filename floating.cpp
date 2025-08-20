#include "floating.h"
#include <utility>
#include "agent.h"
#include "player.h"
#include "tile.h"
#include "mainpage.h"
#include <QObject>
#include <QMetaObject>
#include <QEvent>
#include <QMessageBox>

void floating::attack(Agent* target)  {
    qDebug() << "Attack start. Attacker:" << this << " Target:" << target;
    target->setHP((target->getHP())-(this->getDamage()));
    setHP((this->getHP())-(target->getDamage()/2));
    tile*randomCell=target->getCell();
    qDebug()<<"Defender HP"<<target->getHP()<<"Attacker HP"<<this->getHP();

    tile*p=nullptr;
    bool randomMoved =false;
    while(!randomMoved){
        int r=rand()%(randomCell->getNeighbors().size());
        qDebug() << "random tile:" << r;

        if(r<=randomCell->getNeighbors().size()){
            if(randomCell->getNeighbors()[r] && canStandOn(randomCell->getNeighbors()[r]->getType())
                && !randomCell->getNeighbors()[r]->getAgent() ){

                p=randomCell->getNeighbors()[r];
                //this->move(p->getW()->pos());
                //this->setGeometry(p->getW()->geometry());
                qDebug() << "Agent parent =" << this->parentWidget();
                qDebug() << "Tile parent  =" << p->getW()->parentWidget();

                this->moveToTile(p);
                QPoint globalPos = p->getW()->mapToGlobal(QPoint(0, 0));
                QPoint localPos  = this->parentWidget()->mapFromGlobal(globalPos);

                qDebug() << "Tile global =" << globalPos
                         << "Local for Agent =" << localPos
                         << "Tile geom =" << p->getW()->geometry();

                this->getCell()->setAgent(nullptr);
                this->setCell(p);
                p->setAgent(this);

            }
            if(target->getHP()<=0){
                qDebug()<<"target dided! hp<=0"<<target->getHP();
                target->getOwner()->getPlayerAgents().removeOne(target);
                qDebug()<<"remove one";
                target->getOwner()->setCount(1);
                qDebug()<<"count agent--";
                target->getCell()->setAgent(nullptr);
                qDebug()<<"setAgent";
                target->hide();
                qDebug()<<"hiding";
                delete target;
                qDebug()<<"deleating!";


            }
            if(this->getHP()<=0){
                qDebug()<<"you dided! hp<=0"<<this->getHP();
                //this->getOwner()->removeAgent(this);
                this->getOwner()->getPlayerAgents().removeOne(this);
                qDebug()<<"remove one";
                this->getOwner()->setCount(1);
                qDebug()<<"count agent--";
                this->getCell()->setAgent(nullptr);
                qDebug()<<"setAgent";
                //this->setCell(nullptr);
                //qDebug()<<"setCell";
                this->hide();
                qDebug()<<"hiding";
                delete this;
                qDebug()<<"deleating!";


            }
            randomMoved=true;
        }

    }
    if(player1.getCountAgent()==0){
        qDebug() << "game finished!"<<player2.getName()<<"won the game !";
        QMessageBox msgBox(QMessageBox::Warning,
                           "game finished",
                           "player2 won the game!",
                           QMessageBox::Ok,
                           this->parentWidget());
        msgBox.setStyleSheet(
            "QMessageBox {"
            "background-color: #FFC07C;"
            "color: #000000;"
            "font-size: 12px;"
            "padding: 10px;"
            "}"
            "QLabel {"
            "color: #000000;"
            "font-size: 12px;"
            "}"
            "QPushButton {"
            "background-color: #FFF;"
            "color: #000000;"
            "border: 1px solid #FFC07C;"
            "border-radius: 5px;"
            "padding: 5px;"
            "}"
            );
        msgBox.exec();
        //MainPage.close();
    }
    if(player2.getCountAgent()==0){
        qDebug() << "game finished!"<<player1.getName()<<"won the game !";
        QMessageBox msgBox(QMessageBox::Warning,
                           "game finished",
                           "player1 won the game!",
                           QMessageBox::Ok,
                           this->parentWidget());
        msgBox.setStyleSheet(
            "QMessageBox {"
            "background-color: #FFC07C;"
            "color: #000000;"
            "font-size: 12px;"
            "padding: 10px;"
            "}"
            "QLabel {"
            "color: #000000;"
            "font-size: 12px;"
            "}"
            "QPushButton {"
            "background-color: #FFF;"
            "color: #000000;"
            "border: 1px solid #FFC07C;"
            "border-radius: 5px;"
            "padding: 5px;"
            "}"
            );
        msgBox.exec();
        //MainPage.close();
    }




}
