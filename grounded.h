#ifndef GROUNDED_H
#define GROUNDED_H

#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>
#include "agent.h"



class Grounded : public Agent
{
    Q_OBJECT
    QML_ELEMENT
public:
    Grounded(QWidget *parent, int h, int m, int d, int a):Agent(parent, h, m , d, a){
        //setHP(h);
    }
    bool canMoveT0(int type) const override{
        if(type == 0 || type == 1 || type == 2)
            return 1;
        return 0;
    }
    bool canStandOn(int type) const override{
        if(type == 0 || type == 1 || type == 2)
            return 1;
        return 0;
    }
    void attack(Agent* target) override;



private:

};

#endif // GROUNDED_H
