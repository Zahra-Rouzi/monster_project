#ifndef TILE_H
#define TILE_H

#include "qpushbutton.h"
#include "mainpage.h"
#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>
#include <vector>
#include "agent.h"

class Agent;
class tile : public QPushButton {
    friend class MainPage;
    friend class Agent;
    // Q_OBJECT

public:
    tile(double , double , QWidget *, int,int,int);//tile**?
    tile(tile &o);
    void pic(int c);
    void bfsMove(int d,Agent * a,bool canGo[5][9]);
    void bfsAttack(int d,Agent* a,bool canAttack[5][9]);
    int  getS(){return s;}
    int  getR(){return r;}
    Agent* getAgent(){return agent;}
    void setAgent(Agent *a){agent=a;}
    QPushButton* getW(){return w;}
    int getType(){return type;}
    void get_hex_neighbors(int r, int c, int rows, int cols) ;
    bool isOccupiedByAlly(Agent* a);
    QVector<tile*> getNeighbors() const { return neighbors; }


private:
    QPushButton *w;
    int type,s,r;
    QVector<tile*> neighbors;
    Agent* agent=nullptr;//???

    //tile** neighbors;//tile**??

};

#endif // TILE_H

/*,tile*,tile*,tile*,tile*    tile* right;
tile* left;
    tile* down;
    tile* up;
*/
