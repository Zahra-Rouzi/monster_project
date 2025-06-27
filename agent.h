#ifndef AGENT_H
#define AGENT_H

#include "qpushbutton.h"
#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>
#include "tile.h"

class Player;
class tile;
class Agent : public QPushButton
{
    Q_OBJECT
    QML_ELEMENT
public:
    Agent(QWidget *parent = nullptr, int h = 100, int m = 1, int d = 100, int a = 1);
    tile* getCell(){return currentCell;}
    int getDamage(){return Damage;}
    int getHP(){return HP;}
    int getMobility(){return Mobility;}
    int getAttackRange(){return attackRange;}
    Player* getOwner(){return owner;}
    void setHP(int h){
        HP = (h < 0) ? 0 : h;
    }
    void setCell(tile &t){
        currentCell = &t;
    }
    void setOwner(Player* pl){
        owner=pl;
    }
   // void attack()
    virtual bool canMoveT0(int type) const = 0;
    virtual bool canStandOn(int type) const = 0;

private:
    int HP;
    int Mobility;
    int Damage;
    int attackRange;
    tile *currentCell;
    Player* owner;///

};

#endif // AGENT_H
