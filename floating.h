#ifndef FLOATING_H
#define FLOATING_H

#include "agent.h"
#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>



class floating : public Agent
{
    Q_OBJECT
    QML_ELEMENT
public:
    bool canMoveT0(int type) const override{
        return 1;
    }
    bool canStandOn(int type) const override{
        return 1;
    }
};

#endif // FLOATING_H
