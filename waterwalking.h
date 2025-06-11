#ifndef WATERWALKING_H
#define WATERWALKING_H

#include "agent.h"
#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>

class waterWalking : public Agent
{
    Q_OBJECT
    QML_ELEMENT
public:
    bool canMoveT0(int type) const override{
        if(type == 0 || type == 1 || type == 2 || type == 3)
            return 1;
        return 0;
    }
    bool canStandOn(int type) const override{
        if(type == 0 || type == 1 || type == 2 || type == 3)
            return 1;
        return 0;
    }

};

#endif // WATERWALKING_H
