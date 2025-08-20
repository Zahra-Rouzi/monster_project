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
    friend class tile;
    friend class MainPage;
    Q_OBJECT
    QML_ELEMENT
public:
    Agent(QWidget *parent = nullptr, int h = 300, int m = 2, int d = 50, int a = 2);
    void setConnection();
    tile* getCell(){return currentCell;}
    int getDamage(){return Damage;}
    int getHP(){return HP;}
    int getMobility(){return Mobility;}
    int getAttackRange(){return attackRange;}
    Player* getOwner(){return owner;}
    void setHP(int h){
        HP = (h < 0) ? 0 : h;
    }
    void setMobility(int m){Mobility=m;}
    void setAttackRange(int a){attackRange=a;}
    void setDamage(int d){Damage=d;}

    void setCell(tile *t);  // فقط اعلان


    void setOwner(Player* pl){
        owner=pl;
    }
    void moveToTile(tile* t);

    virtual void attack(Agent* target)=0;
    virtual bool canMoveT0(int type) const = 0;
    virtual bool canStandOn(int type) const = 0;

private:
    int HP;
    int Mobility;
    int Damage;
    int attackRange;
    tile *currentCell;
    Player* owner;///
    bool WaitingForTarget=false;

};
extern Agent* selectedAgent;
extern bool isPlaying;
extern bool done;

#endif // AGENT_H
