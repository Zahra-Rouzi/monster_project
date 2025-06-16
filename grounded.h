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
    Grounded(QWidget * parent): Agent(parent){}
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


private:

};

#endif // GROUNDED_H
