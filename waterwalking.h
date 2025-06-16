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
    waterWalking(QWidget * parent): Agent(parent){}
    bool canMoveT0(int type) const override;
    bool canStandOn(int type) const override;

};

#endif // WATERWALKING_H
