#include "flying.h"
#include <utility>
#include "agent.h"
#include "player.h"
#include "tile.h"
#include "mainpage.h"
#include <QObject>
#include <QMetaObject>
#include <QEvent>
void flying::attack(Agent* target)  {
    target->setHP((target->getHP())-(this->getDamage()));
    setHP((this->getHP())-(target->getDamage()/2));
    int r=rand()%6;
    tile*randomCell=target->getCell();
    tile*w=nullptr;
    if(r<=randomCell->getNeighbors().size()){
        if(randomCell->getNeighbors()[r] && canStandOn(randomCell->getNeighbors()[r]->getType())
            && !randomCell->getNeighbors()[r]->getAgent() ){

            w=randomCell->getNeighbors()[r];
            this->setGeometry(w->geometry());
            this->getCell()->setAgent(nullptr);
            this->setCell(w);
            w->setAgent(this);



        }
        if(target->getHP()<=0){
            target->getOwner()->removeAgent(target);

            target->getCell()->setAgent(nullptr);
            target->setCell(nullptr);
            target->hide();

        }
    }




}
