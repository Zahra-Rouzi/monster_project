#ifndef FLYING_H
#define FLYING_H

#include "agent.h"
#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>



class flying : public Agent
{
    Q_OBJECT
    QML_ELEMENT
public:
    flying(QWidget * parent): Agent(parent){}
    bool canMoveT0(int type) const override{
        return 1;
    }
    bool canStandOn(int type) const override{
        if(type == 0 || type == 1 || type == 2)
            return 1;
        return 0;
    };


};

#endif // FLYING_H
